/**
 *
 * @file QueryXmlResponse.cpp
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#include "QueryXmlResponse.h"

#include <algorithm>
#include <sstream>

#include "Query.h"
#include "QueryServer.h"
#include "QueryXmlRequest.h"

#include <QueryProperties.h>

#include <FastCGIRequest.h>
#include <FastCGIServerThread.h>

#include <DatabaseLayer.h>
#include <DatabaseException.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <Logging.h>
#include <TimeTools.h>

namespace queryserver {

QueryXmlResponse::QueryXmlResponse(QueryXmlRequest* xmlQueryRequest)
: fastcgiserver::FastCGIResponse(dynamic_cast<fastcgiserver::FastCGIRequest*>(xmlQueryRequest))
, xmlQueryRequest(xmlQueryRequest){
}

QueryXmlResponse::~QueryXmlResponse() {
}

void QueryXmlResponse::InsertQuery(
	long long& queryId,
	const std::string& sessionID,
	const std::string& rawQueryString) {

	const querylib::Query& query(xmlQueryRequest->GetQuery());
	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	struct tm now;
	tools::TimeTools::NowUTC(now);

	//insert search query itself at first
	database::searchqueryTableBase insertSearchQuery;
	insertSearchQuery.Set_RESULTTHREAD_ID(0);
	insertSearchQuery.Set_session(sessionID);
	insertSearchQuery.Set_query(rawQueryString);
	insertSearchQuery.Set_started(now);
	insertSearchQuery.Set_modified(now);
	insertSearchQuery.Set_finished(0);
	insertSearchQuery.Set_total(0);
	insertSearchQuery.Set_identifier(query.GetQueryIdentifier());

	try {
		insertSearchQuery.Insert(db);
		db->LastInsertID(queryId);
	}
	catch(database::DatabaseException& e) {
		return; }

	if(queryId == -1) {
		log::Logging::LogWarn("could not insert results for query: " + rawQueryString);
		return;	}
}

bool QueryXmlResponse::ValidateQueryData(
		const std::string& sessionID,
		const std::string& rawQueryString) {

	const querylib::Query& query(xmlQueryRequest->GetQuery());
	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	if(query.GetQueryProperties().queryId > 0) {

		// check if query is associated with session
		std::vector<database::WhereConditionTableColumn*> where;

		database::searchqueryTableBase::GetWhereColumnsFor_session(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
			sessionID,
			where );

		database::searchqueryTableBase::GetWhereColumnsFor_query(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
			rawQueryString,
			where );

		database::searchqueryTableBase::GetWhereColumnsFor_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
			query.GetQueryProperties().queryId,
			where);

		database::SelectStatement selectSearchQuery(database::searchqueryTableBase::CreateTableDefinition());
		selectSearchQuery.SelectAllColumns();
		selectSearchQuery.Where().AddColumns(where);

		database::SelectResultContainer<database::searchqueryTableBase> resultSearchQuery;
		try {
			db->Select(selectSearchQuery,resultSearchQuery);
		}
		catch(database::DatabaseException& e) {
			return false; }

		if(resultSearchQuery.Size() > 1) {
			log::Logging::LogWarn("too many results for search query, cannot process request");
			return false; }

		if(resultSearchQuery.Size() == 1) {
			return true; }
		else {
			log::Logging::LogInfo("client specified invalid query id for it's session, creating new query");
			return false; }
	}

	return false;
}

bool QueryXmlResponse::GetSimilarQuery(long long& queryId, const std::string& sessionID) {

	const querylib::Query& query(xmlQueryRequest->GetQuery());
	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	std::vector<database::WhereConditionTableColumn*> where;

	database::searchqueryTableBase::GetWhereColumnsFor_session(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		sessionID,
		where );

	database::searchqueryTableBase::GetWhereColumnsFor_identifier(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
		query.GetQueryIdentifier(),
		where );

	database::SelectStatement selectSearchQuery(database::searchqueryTableBase::CreateTableDefinition());
	selectSearchQuery.SelectAllColumns();
	selectSearchQuery.Where().AddColumns(where);

	database::SelectResultContainer<database::searchqueryTableBase> resultSearchQuery;
	try {
		db->Select(selectSearchQuery,resultSearchQuery);
	}
	catch(database::DatabaseException& e) {
		return false; }

	if(resultSearchQuery.Size() > 1) {
		log::Logging::LogWarn("too many results for search query, cannot process request");
		return false; }

	if(resultSearchQuery.Size() == 1) {
		for(resultSearchQuery.ResetIter();!resultSearchQuery.IsIterEnd();resultSearchQuery.Next()) {
			resultSearchQuery.GetIter()->Get_ID(queryId);
			log::Logging::LogTrace("found similiar query: %lld",queryId);
			return (queryId > 0);
		}
		return false;
	}
	else {
		log::Logging::LogTrace("could not find similiar query for identifier: %s",query.GetQueryIdentifier().c_str());
		return false; }

	return false;
}

bool QueryXmlResponse::AssembleResponse(const long long& relevantQueryID)
{
	//assemble complete xml response including header etc.
	std::ostringstream xmlResult;
	xmlResult <<
		"<?xml version=\"1.0\"?>\n"
		"<response>"
			"<queryId>" << relevantQueryID << "</queryId>"
		"</response>\n";

	//set xml string as response's content
	content = xmlResult.str();
	return true;
}

bool QueryXmlResponse::Process(FCGX_Request& request) {

	const querylib::Query& query(xmlQueryRequest->GetQuery());

	const std::string& sessionID(fcgiRequest->GetCookieValueByName("SIRIDIAID"));
	if(sessionID.empty()) {
		log::Logging::LogWarn("empty session id (SIRIDIAID) received, cannot process query request");
		return false; }

	const std::string& rawQueryString(xmlQueryRequest->GetRawQueryString());
	if(rawQueryString.empty()) {
		log::Logging::LogWarn("empty query string received, cannot process query request");
		return false; }

	long long relevantQueryID(query.GetQueryProperties().queryId);
	if(!ValidateQueryData(sessionID,rawQueryString))
		relevantQueryID = -1;

	if(relevantQueryID <= 0) {
		//query does not exist in database

		//check for similar query
		if(!GetSimilarQuery(relevantQueryID,sessionID)) {
			InsertQuery(relevantQueryID,sessionID,rawQueryString);
		}
	}

	AssembleResponse(relevantQueryID);
	return FastCGIResponse::Process(request);
}

}
