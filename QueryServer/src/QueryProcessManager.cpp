/**
 * @file QueryProcessManager.cpp
 * @author Moritz Wagner
 * @date Apr 8, 2015
 */

#include "QueryProcessManager.h"

namespace queryserver {

QueryProcessManager::QueryProcessManager()
: cleanupThread(*this) {
	cleanupThread.StartThread();
}

QueryProcessManager::~QueryProcessManager() {
	if(cleanupThread.IsRunning()) {
		cleanupThread.SetShallEnd();
		cleanupThread.WaitForThread(); }
}

void QueryProcessManager::AddQuery(const database::DatabaseConfig* dbConfig, const long long& queryId,const Query& query, const std::string& sessionID, const std::string& rawQueryString) {
	QueryProcessThread* thread(new QueryProcessThread(dbConfig,queryId,query,sessionID,rawQueryString));
	std::pair<long long,QueryProcessThread*> ins(queryId, thread);
	lockThreads.Lock();
	threads.insert(ins);
	lockThreads.Unlock();

	thread->StartThread();
}

}
