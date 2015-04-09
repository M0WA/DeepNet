/**
 * @file QueryResultXmlResponse.cpp
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#include "QueryResultXmlResponse.h"

#include "QueryResultXmlRequest.h"

#include <FastCGIServerThread.h>

#include <DatabaseLayer.h>
#include <DatabaseException.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <Logging.h>

namespace queryserver {

QueryResultXmlResponse::QueryResultXmlResponse(QueryResultXmlRequest* xmlQueryResultRequest)
: fastcgiserver::FastCGIResponse(dynamic_cast<fastcgiserver::FastCGIRequest*>(xmlQueryResultRequest))
, xmlQueryResultRequest(xmlQueryResultRequest) {
}

QueryResultXmlResponse::~QueryResultXmlResponse() {
}

bool QueryResultXmlResponse::Process(FCGX_Request& request){

	long long queryId(xmlQueryResultRequest->QueryID());
	long long pageNo(xmlQueryResultRequest->PageNo());
	long long maxResults(xmlQueryResultRequest->MaxResults());
	const std::string& sessionID(fcgiRequest->GetCookieValueByName("SIRIDIAID"));

	long long total(-1);
	long long finished(0);
	if(!LoadQuery(queryId,sessionID,total,finished)) {
	}
	else if(!finished) {
	}
	else {
		database::SelectResultContainer<database::queryresultsTableBase> queryResults;
		if(!LoadResults(queryResults,queryId,pageNo,maxResults)) {
		}
		else {
			AssembleXMLResult(queryResults,total,queryId,pageNo);
		}
	}

	return FastCGIResponse::Process(request);
}

bool QueryResultXmlResponse::LoadQuery(
		const long long& queryId,
		const std::string& sessionID,
		long long& total,
		long long& finished) {

	std::vector<database::WhereConditionTableColumn*> where;

	database::searchqueryTableBase::GetWhereColumnsFor_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		queryId,
		where );

	database::searchqueryTableBase::GetWhereColumnsFor_session(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
		sessionID,
		where );

	database::DatabaseConnection* db(xmlQueryResultRequest->ServerThread()->DB().Connection());

	database::SelectResultContainer<database::searchqueryTableBase> results;
	try {
		database::searchqueryTableBase::GetBy_ID(db,queryId,results); }
	catch(database::DatabaseException& e) {
		return false; }

	if(results.Size() < 1) {
		log::Logging::LogInfo("query id %llu not found for session %s",queryId,sessionID.c_str());
		return false; }

	results.ResetIter();
	results.GetConstIter()->Get_total(total);
	results.GetConstIter()->Get_finished(finished);

	return true;
}

bool QueryResultXmlResponse::LoadResults(
		database::SelectResultContainer<database::queryresultsTableBase>& queryResults,
		const long long& queryId,
		const long long& pageNo,
		const long long& maxResults)
{
	long long startPosition(pageNo * maxResults);
	long long endPosition(startPosition + maxResults);

	std::vector<database::WhereConditionTableColumn*> where;

	database::queryresultsTableBase::GetWhereColumnsFor_SEARCHQUERY_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		queryId,
		where );

	database::queryresultsTableBase::GetWhereColumnsFor_position(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::GreaterOrEqual(),database::WhereCondition::And()),
		startPosition,
		where );

	database::queryresultsTableBase::GetWhereColumnsFor_position(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Smaller(),database::WhereCondition::And()),
		endPosition,
		where );

	database::SelectStatement selectQueryResults(database::queryresultsTableBase::CreateTableDefinition());
	selectQueryResults.SelectAllColumns();
	selectQueryResults.Where().AddColumns(where);

	selectQueryResults.OrderBy().AddColumn(database::queryresultsTableBase::GetDefinition_position(),database::ASCENDING);
	selectQueryResults.SetLimit(maxResults);

	database::DatabaseConnection* db(xmlQueryResultRequest->ServerThread()->DB().Connection());
	try {
		db->Select(selectQueryResults,queryResults); }
	catch(database::DatabaseException& e) {
		return false; }

	return true;
}

void QueryResultXmlResponse::AssembleXMLResult(
		const database::SelectResultContainer<database::queryresultsTableBase>& queryResults,
		const size_t& total,
		const long long& queryId,
		const long long& pageNo) {
	//assemble xml entries from results
	std::ostringstream xmlResultEntries;
	for(queryResults.ResetIter();!queryResults.IsIterEnd();queryResults.Next()) {
		const database::queryresultsTableBase* curTbl(queryResults.GetConstIter());
		std::string tmp;
		curTbl->Get_resultXML(tmp);
		xmlResultEntries << tmp; }

	//assemble complete xml response including header etc.
	std::ostringstream xmlResult;
	xmlResult <<
		"<?xml version=\"1.0\"?>\n"
		"<response>"
		"<queryId>" << queryId << "</queryId>"
		"<pageNo>" << pageNo << "</pageNo>"
		"<totalResults>" << total << "</totalResults>" <<
		xmlResultEntries.str() <<
		"</response>\n";

	//set xml string as response's content
	content = xmlResult.str();
}

}
