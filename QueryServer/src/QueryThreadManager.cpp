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

namespace queryserver {

QueryThreadManager::QueryThreadManager() {
}

QueryThreadManager::~QueryThreadManager() {
}

void QueryThreadManager::AddQuery(const database::DatabaseConfig* dbConfig,const Query& query) {

	if(query.properties.relevanceContent > 0.0) {
		AddQueryTyped<QueryContentThread,QueryThreadParam>(dbConfig,query); }

	if(query.properties.relevanceMeta > 0.0) {
		AddQueryTyped<QueryMetaThread,QueryThreadParam>(dbConfig,query); }

	if(query.properties.relevanceSecondLevelDomain > 0.0) {
		AddQueryTyped<QuerySecondLevelDomainThread,QueryThreadParam>(dbConfig,query); }

	if(query.properties.relevanceSubdomain > 0.0) {
		AddQueryTyped<QuerySubdomainThread,QueryThreadParam>(dbConfig,query); }

	if(query.properties.relevanceUrlPath > 0.0) {
		AddQueryTyped<QueryUrlPathThread,QueryThreadParam>(dbConfig,query); }
}

void QueryThreadManager::WaitForResult() {

	WaitForAll();

	std::vector<QueryThreadResultEntry*> allResults;
	std::vector<threading::Thread::ThreadID>::const_iterator i(queryThreadIDs.begin());
	for(;i != queryThreadIDs.end();++i) {
		const std::vector<QueryThreadResultEntry*>& threadResults(GetThreadInfosByID(*i).first->GetResults().GetConstVector());
		allResults.insert(allResults.end(),threadResults.begin(),threadResults.end()); }

	//this invalidates allResults...
	ReleaseAll();
	allResults.clear();

}

}
