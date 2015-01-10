/**
 *
 * @file QueryThreadManager.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QueryThreadManager.h"

#include "Query.h"
#include "QueryThreadParam.h"
#include "QueryThreadResultEntry.h"

#include "QueryContentThread.h"
#include "QueryMetaThread.h"
#include "QuerySecondLevelDomainThread.h"
#include "QuerySubdomainThread.h"
#include "QueryUrlPathThread.h"

#include "QueryDictionaryInfoThread.h"

#include <Logging.h>
#include <ContainerTools.h>

namespace queryserver {

QueryThreadManager::QueryThreadManager(const database::DatabaseConfig* dbConfig)
: releaseSeen(true)
, dictionary(0){

	for(size_t i(0); i < QUERY_THREAD_MANAGER_DB_HELPERS_SIZE; i++) {
		dbHelpers[i].CreateConnection(dbConfig); }
}

QueryThreadManager::~QueryThreadManager() {
	ReleaseQuery();

	for(size_t i(0); i < QUERY_THREAD_MANAGER_DB_HELPERS_SIZE; i++) {
		dbHelpers[i].DestroyConnection(); }
}

void QueryThreadManager::BeginQuery(Query& query) {

	if(!releaseSeen) {
		log::Logging::LogWarn("canceling running query, this should no be happening");
		ReleaseQuery();	}

	releaseSeen = false;

	const QueryCriteria& criteria(query.GetQueryProperties().GetCriteria());

	bool dictionaryThreadNeeded(
		criteria.IsCriteriaEnabled(QueryCriteria::CRITERIA_CONTENT) ||
		criteria.IsCriteriaEnabled(QueryCriteria::CRITERIA_META) );

	if(dictionaryThreadNeeded) {
		dictionary = new QueryDictionaryInfoThread();
		dictionary->StartThread(
				new QueryDictionaryInfoThread::QueryDictionaryInfoThreadParam( query, dbHelpers[0].GetDatabaseConfig() )
		);
	}

	if( criteria.IsCriteriaEnabled(QueryCriteria::CRITERIA_DOMAIN) ) {
		AddQueryTyped<QuerySecondLevelDomainThread,QueryThreadParam>(dbHelpers[2].Connection(),query);
		AddQueryTyped<QuerySubdomainThread,QueryThreadParam>(dbHelpers[3].Connection(),query); }

	if(criteria.IsCriteriaEnabled(QueryCriteria::CRITERIA_PATH)) {
		AddQueryTyped<QueryUrlPathThread,QueryThreadParam>(dbHelpers[4].Connection(),query); }

	if(dictionaryThreadNeeded) {

		dictionary->WaitForThread();

		if(criteria.IsCriteriaEnabled(QueryCriteria::CRITERIA_CONTENT)) {
			AddQueryTyped<QueryContentThread,QueryDictionaryThreadParam>(dbHelpers[0].Connection(),query,dictionary); }

		if(criteria.IsCriteriaEnabled(QueryCriteria::CRITERIA_META)) {
			AddQueryTyped<QueryMetaThread,QueryDictionaryThreadParam>(dbHelpers[1].Connection(),query,dictionary); }
	}
}

void QueryThreadManager::WaitForResults(std::vector<const QueryThreadResultEntry*>& results) {

	//TODO:


/*
	if(releaseSeen) {
		log::Logging::LogError("waiting for invalid query, skipping");
		return; }

	WaitForAll();

	std::vector<threading::Thread::ThreadID>::const_iterator i(queryThreadIDs.begin());
	for(;i != queryThreadIDs.end();++i) {
		const std::vector<QueryThreadResultEntry*>& threadResults(GetThreadInfosByID(*i).first->GetResults().GetConstVector());
		std::vector<const QueryThreadResultEntry*> out;
		tools::ContainerTools::ToConstVector(threadResults,out);
		results.insert(results.end(),out.begin(),out.end()); }
		*/
}

void QueryThreadManager::ReleaseQuery() {

	queryThreadIDs.clear();
	ReleaseAll();

	if(dictionary) {
		delete dictionary;
		dictionary = 0; }

	releaseSeen = true;
}

}
