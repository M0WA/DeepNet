/*
 * @file ReleaseCrawlerThread.cpp
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#include "ReleaseCrawlerThread.h"

#include "Sync.h"

#include <PerformanceCounter.h>

namespace syncing {

ReleaseCrawlerThread::ReleaseCrawlerThread(database::DatabaseConnection* dbConn)
: threading::Thread(ReleaseCrawlerThreadFunc,false)
, dbConn(dbConn) {
}

ReleaseCrawlerThread::~ReleaseCrawlerThread() {
}

void* ReleaseCrawlerThread::ReleaseCrawlerThreadFunc(threading::Thread::THREAD_PARAM* param) {

	ReleaseCrawlerThreadParam* p(reinterpret_cast<ReleaseCrawlerThreadParam*>(param->pParam));

	PERFORMANCE_LOG_START;
	if(!Sync::UnlockSecondLevelDomain(p->dbConn,p->crawlerID,-1)) {
		delete p;
		return (void*)1;
	}
	PERFORMANCE_LOG_STOP("ReleaseCrawler overall");

	delete p;
	return NULL;
}

}
