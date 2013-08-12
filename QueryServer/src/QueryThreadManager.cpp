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
#include "QueryUrlThread.h"

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

	if(query.properties.querySecondLevelDomain ||
	   query.properties.querySubdomain ||
	   query.properties.queryUrlPath) {
		AddThread(
			new QueryUrlThread(),
			new QueryThreadParam(dbConfig, query));
	}
}

void QueryThreadManager::GetResult() {

	WaitForAll();
}

}
