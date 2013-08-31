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
#include "QueryProperties.h"
#include "QueryXmlRequest.h"
#include "QueryThreadResultEntry.h"
#include "QueryThreadManager.h"
#include "Relevance.h"

#include <FastCGIRequest.h>
#include <FastCGIServerThread.h>

#include <CacheDatabaseUrl.h>
#include <DatabaseUrl.h>

#include <DatabaseLayer.h>
#include <DatabaseException.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <Logging.h>
#include <TimeTools.h>

namespace queryserver {

QueryXmlResponse::QueryXmlResponse(QueryThreadManager& queryManager,QueryXmlRequest* xmlQueryRequest)
: fastcgiserver::FastCGIResponse(dynamic_cast<fastcgiserver::FastCGIRequest*>(xmlQueryRequest))
, queryManager(queryManager)
, xmlQueryRequest(xmlQueryRequest){
}

QueryXmlResponse::~QueryXmlResponse() {
}

bool QueryXmlResponse::LoadQuery(const long long& queryId,const std::string& sessionID,const std::string& rawQueryString) {

	const Query& query(xmlQueryRequest->GetQuery());
	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	database::SelectResultContainer<database::searchqueryTableBase> results;
	try {
		database::searchqueryTableBase::GetBy_ID(db,queryId,results); }
	catch(database::DatabaseException& e) {
		return false; }

	results.ResetIter();
	std::string sessionIDTmp, rawQueryStringTmp;
	long long sizeTotal(0);
	results.GetConstIter()->Get_session(sessionIDTmp);
	results.GetConstIter()->Get_query(rawQueryStringTmp);
	results.GetConstIter()->Get_total(sizeTotal);

	if( sessionIDTmp.compare(sessionID) != 0 ||
		rawQueryStringTmp.compare(rawQueryString) != 0 )
	{
		log::Logging::LogWarn("invalid session id or query string received for this query id, cannot process request");
		return false; }

	long long startPosition(query.properties.pageNo * query.properties.maxResults);
	long long endPosition(startPosition + query.properties.maxResults);

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
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::SmallerOrEqual(),database::WhereCondition::And()),
		endPosition,
		where );

	database::SelectStatement selectQueryResults(database::queryresultsTableBase::CreateTableDefinition());
	selectQueryResults.SelectAllColumns();
	selectQueryResults.Where().AddColumns(where);

	database::SelectResultContainer<database::queryresultsTableBase> queryResults;
	try {
		db->Select(selectQueryResults,queryResults); }
	catch(database::DatabaseException& e) {
		return false; }

	AssembleXMLResult(queryResults,sizeTotal,queryId);
	return true;
}

void QueryXmlResponse::InsertResults(long long& queryId,const std::string& sessionID,const std::string& rawQueryString,const std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	const Query& query(xmlQueryRequest->GetQuery());
	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	//insert search query itself at first
	database::searchqueryTableBase insertSearchQuery;
	insertSearchQuery.Set_session(sessionID);
	insertSearchQuery.Set_query(rawQueryString);
	insertSearchQuery.Set_age(tools::TimeTools::NowUTC());
	insertSearchQuery.Set_total(responseEntries.size());

	try {
		insertSearchQuery.Insert(db);
		db->LastInsertID(queryId);
	}
	catch(database::DatabaseException& e) {
		return; }

	if(queryId == -1) {
		log::Logging::LogWarn("could not insert results for query: " + rawQueryString);
		return;	}

	//insert all results
	std::vector<QueryXmlResponseResultEntry>::const_iterator i(responseEntries.begin());
	for(size_t resultID(0);i!=responseEntries.end();++i,++resultID) {

		std::ostringstream xmlResultEntry;
		i->AppendToXML(db,query,resultID,xmlResultEntry);

		database::queryresultsTableBase queryResultTbl;
		queryResultTbl.Set_SEARCHQUERY_ID(queryId);
		queryResultTbl.Set_resultXML(xmlResultEntry.str());
		queryResultTbl.Set_position(resultID);

		try {
			queryResultTbl.Insert(db);
		}
		catch(database::DatabaseException& e) {
			return; }
	}
}

bool QueryXmlResponse::CreateQuery(long long& queryId,const std::string& sessionID,const std::string& rawQueryString) {

	const Query& query(xmlQueryRequest->GetQuery());
	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	queryManager.BeginQuery(query);

	//waiting for all results to arrive
	std::vector<const QueryThreadResultEntry*> results;
	queryManager.WaitForResults(results);

	//container for final results
	std::vector<QueryXmlResponseResultEntry> responseEntries;
	std::vector<const QueryThreadResultEntry*>::const_iterator iRes(results.begin());
	for(;iRes != results.end(); ++iRes) {
		responseEntries.push_back(QueryXmlResponseResultEntry(*iRes)); }

	//group results by url id
	MergeDuplicateURLs(responseEntries);

	//group results by secondlevel domain if requested
	if(query.properties.groupBySecondLevelDomain) {
		MergeDuplicateSecondLevel(db, responseEntries);}

	//sort results
	SortResults(responseEntries);

	//save results to database
	InsertResults(queryId,sessionID,rawQueryString,responseEntries);

	//releasing the query invalidates
	//all pointers to it's results
	results.clear();
	queryManager.ReleaseQuery();

	return true;
}

bool QueryXmlResponse::Process(FCGX_Request& request) {

	const Query& query(xmlQueryRequest->GetQuery());

	const std::string& sessionID(fcgiRequest->GetCookieValueByName("SIRIDIAID"));
	if(sessionID.empty()) {
		log::Logging::LogWarn("empty session id (SIRIDIAID) received, cannot process query request");
		return false; }

	const std::string& rawQueryString(xmlQueryRequest->GetRawQueryString());
	if(rawQueryString.empty()) {
		log::Logging::LogWarn("empty query string received, cannot process query request");
		return false; }

	long long relevantQueryID(query.properties.queryId);

	//no query id given, try to find it in database
	/*
	if(relevantQueryID <= 0) {
		std::vector<database::WhereConditionTableColumn*> where;

		database::searchqueryTableBase::GetWhereColumnsFor_session(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
			sessionID,
			where );

		database::searchqueryTableBase::GetWhereColumnsFor_query(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::And()),
			rawQueryString,
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
			resultSearchQuery.ResetIter();
			resultSearchQuery.GetConstIter()->Get_ID(relevantQueryID); }
		else {
			relevantQueryID = -1; }
	}
	*/

	//if query does not exist in database, create it
	if(relevantQueryID <= 0) {
		if(!CreateQuery(relevantQueryID,sessionID,rawQueryString))
			return false;
	}

	if(!LoadQuery(relevantQueryID,sessionID,rawQueryString))
		return false;

	return FastCGIResponse::Process(request);
}

void QueryXmlResponse::SortResults(std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	//resorting thread results in each response entry by relevance
	std::vector<QueryXmlResponseResultEntry>::iterator iResort(responseEntries.begin());
	for(;iResort!=responseEntries.end();++iResort) {
		iResort->SortResultsByRelevance(); }

	//sort response entries by relevance (descending, therefore we use reverse iterator)
	std::sort(responseEntries.rbegin(), responseEntries.rend());
}

void QueryXmlResponse::AssembleXMLResult(const database::SelectResultContainer<database::queryresultsTableBase>& queryResults,const size_t& total, const long long& queryId) {

	const Query& query(xmlQueryRequest->GetQuery());

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
		"<pageNo>" << query.properties.pageNo << "</pageNo>"
		"<totalResults>" << total << "</totalResults>" <<
		xmlResultEntries.str() <<
		"</response>\n";

	//set xml string as response's content
	content = xmlResult.str();
}

void QueryXmlResponse::MergeDuplicateSecondLevel(database::DatabaseConnection* db, std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	std::map<long long,size_t> secondLvlIDPos;

	std::vector<QueryXmlResponseResultEntry>::iterator i(responseEntries.begin());
	for(size_t pos(0);i!=responseEntries.end();++i) {

		tools::Pointer<htmlparser::DatabaseUrl> ptrUrl;
		caching::CacheDatabaseUrl::GetByUrlID(db,i->GetMostRelevantResult()->urlID,ptrUrl);
		long long secondLevelID(ptrUrl.GetConst()->GetSecondLevelID());

		if(secondLvlIDPos.count(secondLevelID) > 0) {
			responseEntries.at(secondLvlIDPos[secondLevelID]).AddResult(*i);
			responseEntries.erase(i);
			--i;
		}
		else {
			secondLvlIDPos[secondLevelID]=pos;
			++pos;
		}
	}
}

void QueryXmlResponse::MergeDuplicateURLs(std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	std::map<long long,size_t> urlIDPos;
	std::vector<QueryXmlResponseResultEntry>::iterator i(responseEntries.begin());

	for(size_t pos(0);i!=responseEntries.end();++i) {
		const long long& urlID(i->GetMostRelevantResult()->urlID);
		if(urlIDPos.count(urlID) > 0) {
			responseEntries.at(urlIDPos[urlID]).AddResult(*i);
			responseEntries.erase(i);
			--i;
		}
		else {
			urlIDPos[urlID]=pos;
			++pos;
		}
	}
}

}
