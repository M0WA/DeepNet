/**
 * @file QueryProcessThread.cpp
 * @author Moritz Wagner
 * @date Apr 8, 2015
 */

#include "QueryProcessThread.h"

#include "QueryThreadResultEntry.h"

#include <CacheDatabaseUrl.h>
#include <DatabaseUrl.h>

#include <TimeTools.h>

#include <DatabaseLayer.h>
#include <DatabaseException.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

namespace queryserver {

QueryProcessThread::QueryProcessThread(const database::DatabaseConfig* dbConfig, const long long& queryId, const Query& query, const std::string& sessionID, const std::string& rawQueryString)
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(QueryProcessThread::QueryProcessThreadFunction)),false)
, dbConfig(dbConfig)
, queryId(queryId)
, query(query)
, sessionID(sessionID)
, rawQueryString(rawQueryString)
, queryManager(dbConfig) {
}

QueryProcessThread::~QueryProcessThread() {
}

void* QueryProcessThread::QueryProcessThreadFunction(threading::Thread::THREAD_PARAM* param) {

	database::DatabaseHelper dh;
	QueryProcessThread* instance(dynamic_cast<QueryProcessThread*>(param->instance));

	database::DatabaseConnection* db(dh.CreateConnection(instance->dbConfig));
	instance->RunQuery(db);
	dh.DestroyConnection();

	return 0;
}

bool QueryProcessThread::RunQuery(database::DatabaseConnection* db) {

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
	if(query.GetQueryProperties().groupBySecondLevelDomain) {
		MergeDuplicateSecondLevel(db, responseEntries);}

	//sort results
	SortResults(responseEntries);

	//save results to database
	InsertResults(db,responseEntries);

	SetQueryFinished(db,responseEntries.size());

	//releasing the query invalidates
	//all pointers to it's results
	results.clear();
	queryManager.ReleaseQuery();

	return true;
}

bool QueryProcessThread::SetQueryFinished(database::DatabaseConnection* db,const long long& resultCount)
{
	database::TableBaseUpdateParam param;
	param.limit = -1;
	param.onlyDirtyColumns = true;

	database::searchqueryTableBase::GetWhereColumnsFor_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),database::WhereCondition::InitialComp()),
		queryId,
		param.whereCols);

	database::searchqueryTableBase tbl;
	tbl.Set_modified(tools::TimeTools::NowUTC());
	tbl.Set_finished(1);
	tbl.Set_total(resultCount);
	try {
		tbl.Update(db,param); }
	catch(database::DatabaseException& e) {
		return false; }

	return true;
}

void QueryProcessThread::InsertResults(
	database::DatabaseConnection* db,
	const std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	//insert all results
	std::vector<QueryXmlResponseResultEntry>::const_iterator i(responseEntries.begin());
	for(size_t resultPosition(0);i!=responseEntries.end();++i,++resultPosition) {

		std::ostringstream xmlResultEntry;
		i->AppendToXML(db,query,resultPosition,xmlResultEntry);

		database::queryresultsTableBase queryResultTbl;
		queryResultTbl.Set_SEARCHQUERY_ID(queryId);
		queryResultTbl.Set_resultXML(xmlResultEntry.str());
		queryResultTbl.Set_position(resultPosition);

		try {
			queryResultTbl.Insert(db);
		}
		catch(database::DatabaseException& e) {
			return; }
	}
}

void QueryProcessThread::SortResults(std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	//resorting thread results in each response entry by relevance
	std::vector<QueryXmlResponseResultEntry>::iterator iResort(responseEntries.begin());
	for(;iResort!=responseEntries.end();++iResort) {
		iResort->SortResultsByRelevance(); }

	//sort response entries by relevance (descending, therefore we use reverse iterator)
	std::sort(responseEntries.rbegin(), responseEntries.rend());
}

void QueryProcessThread::MergeDuplicateSecondLevel(
		database::DatabaseConnection* db,
		std::vector<QueryXmlResponseResultEntry>& responseEntries) {
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

void QueryProcessThread::MergeDuplicateURLs(std::vector<QueryXmlResponseResultEntry>& responseEntries) {
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
