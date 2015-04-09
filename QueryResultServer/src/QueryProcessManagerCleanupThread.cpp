/**
 * @file QueryProcessManagerCleanupThread.cpp
 * @author Moritz Wagner
 * @date Apr 8, 2015
 */

#include "QueryProcessManagerCleanupThread.h"

#include "QueryProcessManager.h"

#include <unistd.h>

namespace queryserver {

QueryProcessManagerCleanupThread::QueryProcessManagerCleanupThread(QueryProcessManager& qpm)
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(QueryProcessManagerCleanupThread::QueryProcessManagerCleanupFunc)),false)
, qpm(qpm){
}

QueryProcessManagerCleanupThread::~QueryProcessManagerCleanupThread() {
}

void* QueryProcessManagerCleanupThread::QueryProcessManagerCleanupFunc(threading::Thread::THREAD_PARAM* param) {

	QueryProcessManagerCleanupThread* instance(dynamic_cast<QueryProcessManagerCleanupThread*>(param->instance));

	while(!instance->ShallEnd()) {
		instance->qpm.lockThreads.Lock();
		std::map<long long,QueryProcessThread*>& threads(instance->qpm.threads);
		std::map<long long,QueryProcessThread*>::iterator i(threads.begin());
		for(; i != threads.end(); ++i) {
			if(!i->second->IsRunning()){
				threads.erase(i);
				--i; }
		}
		instance->qpm.lockThreads.Unlock();
		sleep(10);
	}
	return 0;
}

}
