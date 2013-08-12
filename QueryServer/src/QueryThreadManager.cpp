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

namespace queryserver {

QueryThreadManager::QueryThreadManager() {
}

QueryThreadManager::~QueryThreadManager() {
}

void QueryThreadManager::AddQuery(const database::DatabaseConfig* dbConfig,const Query& query) {

	if(query.properties.queryContent) {
		AddThread(
			new QueryContentThread(),
			new QueryContentThread::QueryContentThreadParam(dbConfig, query));
	}

	if(query.properties.queryMeta) {
		//
		//TODO:
		//
	}
}

void QueryThreadManager::GetResult() {

	WaitForAll();
}

}
