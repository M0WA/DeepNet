/*
 * @file ReleaseCrawlerThread.cpp
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#include "ReleaseCrawlerThread.h"

#include "Sync.h"

#include <PerformanceCounter.h>
#include <DatabaseHelper.h>

namespace syncing {

ReleaseCrawlerThread::ReleaseCrawlerThread()
: threading::Thread(ReleaseCrawlerThreadFunc,false) {
}

ReleaseCrawlerThread::~ReleaseCrawlerThread() {
}

void* ReleaseCrawlerThread::ReleaseCrawlerThreadFunc(threading::Thread::THREAD_PARAM* param) {

	log::Logging::RegisterThreadID("ReleaseCrawlerThread");

	ReleaseCrawlerThreadParam* p(reinterpret_cast<ReleaseCrawlerThreadParam*>(param->pParam));

	database::DatabaseHelper helper;
	database::DatabaseConnection* db(helper.CreateConnection(p->dbConf));

	PERFORMANCE_LOG_START;
	if(!Sync::UnlockSecondLevelDomain(db,p->crawlerID,-1)) {
		delete p;
		return (void*)1;
	}
	PERFORMANCE_LOG_STOP("ReleaseCrawler overall");

	delete p;
	return NULL;
}

}
