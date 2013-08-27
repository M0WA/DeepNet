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

#include "DictionaryInfoThread.h"

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

void QueryThreadManager::BeginQuery(const Query& query) {

	if(!releaseSeen) {
		log::Logging::LogWarn("canceling running query, this should no be happening");
		ReleaseQuery();	}

	releaseSeen = false;

	bool dictionaryThreadNeeded(
		(query.properties.relevanceContent > 0.0) ||
		(query.properties.relevanceMeta > 0.0) );

	if(dictionaryThreadNeeded) {
		dictionary = new DictionaryInfoThread(dbHelpers[0].Connection(),query);
		dictionary->StartThread();
	}

	if(query.properties.relevanceSecondLevelDomain > 0.0) {
		AddQueryTyped<QuerySecondLevelDomainThread,QueryThreadParam>(dbHelpers[2].Connection(),query); }

	if(query.properties.relevanceSubdomain > 0.0) {
		AddQueryTyped<QuerySubdomainThread,QueryThreadParam>(dbHelpers[3].Connection(),query); }

	if(query.properties.relevanceUrlPath > 0.0) {
		AddQueryTyped<QueryUrlPathThread,QueryThreadParam>(dbHelpers[4].Connection(),query); }

	if(dictionaryThreadNeeded) {
		dictionary->WaitForThread();

		if(query.properties.relevanceContent > 0.0) {
			AddQueryTyped<QueryContentThread,QueryDictionaryThreadParam>(dbHelpers[0].Connection(),query,dictionary); }

		if(query.properties.relevanceMeta > 0.0) {
			AddQueryTyped<QueryMetaThread,QueryDictionaryThreadParam>(dbHelpers[1].Connection(),query,dictionary);
		}
	}
}

void QueryThreadManager::WaitForResults(std::vector<const QueryThreadResultEntry*>& results) {

	if(releaseSeen) {
		log::Logging::LogError("waiting for invalid query, skipping");
		return; }

	WaitForAll();

	std::vector<threading::Thread::ThreadID>::const_iterator i(queryThreadIDs.begin());
	for(;i != queryThreadIDs.end();++i) {
		const std::vector<QueryThreadResultEntry*>& threadResults(GetThreadInfosByID(*i).first->GetResults().GetConstVector());
		std::vector<const QueryThreadResultEntry*> out;
		tools::ContainerTools::ToConstVector(threadResults,out);
		results.insert(results.end(),out.begin(),out.end());
	}
}

void QueryThreadManager::ReleaseQuery() {

	queryThreadIDs.clear();
	ReleaseAll();

	if(dictionary)
		delete dictionary;

	releaseSeen = true;
}

}
