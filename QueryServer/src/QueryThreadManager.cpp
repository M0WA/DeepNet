/**
 *
 * @file QueryThreadManager.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QueryThreadManager.h"

#include "Query.h"
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

	if(query.properties.queryContent) {
		AddThread(
			new QueryContentThread(),
			new QueryThreadParam(dbConfig, query));
	}

	if(query.properties.queryMeta) {
		AddThread(
			new QueryMetaThread(),
			new QueryThreadParam(dbConfig, query));
	}

	if(query.properties.querySecondLevelDomain) {
		AddThread(
			new QuerySecondLevelDomainThread(),
			new QueryThreadParam(dbConfig, query));
	}

	if(query.properties.querySubdomain) {
		AddThread(
			new QuerySubdomainThread(),
			new QueryThreadParam(dbConfig, query));
	}

	if(query.properties.queryUrlPath) {
		AddThread(
			new QueryUrlPathThread(),
			new QueryThreadParam(dbConfig, query));
	}
}

void QueryThreadManager::GetResult() {

	WaitForAll();
}

}
