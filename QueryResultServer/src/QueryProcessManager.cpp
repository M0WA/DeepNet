/**
 * @file QueryProcessManager.cpp
 * @author Moritz Wagner
 * @date Apr 8, 2015
 */

#include "QueryProcessManager.h"

namespace queryserver {

QueryProcessManager::QueryProcessManager(const database::DatabaseConfig* dbConfig)
: cleanupThread(*this)
, cleanResultThread(dbConfig,300)
, dbConfig(dbConfig) {
	cleanupThread.StartThread();
	cleanResultThread.StartThread();
}

QueryProcessManager::~QueryProcessManager() {
	if(cleanupThread.IsRunning()) {
		cleanupThread.SetShallEnd();
		cleanupThread.WaitForThread(); }

	if(cleanResultThread.IsRunning()) {
		cleanResultThread.SetShallEnd();
		cleanResultThread.WaitForThread(); }
}

void QueryProcessManager::AddQuery(const long long& queryId,const querylib::Query& query, const std::string& sessionID, const std::string& rawQueryString) {
	QueryProcessThread* thread(new QueryProcessThread(dbConfig,queryId,query,sessionID,rawQueryString));
	std::pair<long long,QueryProcessThread*> ins(queryId, thread);
	lockThreads.Lock();
	threads.insert(ins);
	lockThreads.Unlock();

	thread->StartThread();
}

}
