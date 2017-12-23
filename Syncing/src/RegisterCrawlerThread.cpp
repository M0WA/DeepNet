/*
 * @file RegisterCrawlerThread.cpp
 * @date Dec 3, 2017
 * @author Moritz Wagner
 */

#include "RegisterCrawlerThread.h"

#include <DatabaseHelper.h>
#include <DatabaseLayer.h>

#include <PerformanceCounter.h>

namespace syncing {

RegisterCrawlerThread::RegisterCrawlerThread()
: threading::Thread(RegisterCrawlerThread::RegisterCrawlerThreadFunc,false)
, crawlerID(-1) {
}

RegisterCrawlerThread::~RegisterCrawlerThread() {
}

void* RegisterCrawlerThread::RegisterCrawlerThreadFunc(threading::Thread::THREAD_PARAM* param) {

	log::Logging::RegisterThreadID("RegisterCrawlerThread");

	RegisterCrawlerThread* instance(dynamic_cast<RegisterCrawlerThread*>(param->instance));
	RegisterCrawlerThreadParam* p(reinterpret_cast<RegisterCrawlerThreadParam*>(param->pParam));

	database::DatabaseHelper helper;
	database::DatabaseConnection* db(helper.CreateConnection(p->dbConf));

	PERFORMANCE_LOG_START;
	database::crawlersessionsTableBase crawlerSession;
	crawlerSession.Insert(db);
	if(!db->LastInsertID(instance->crawlerID)){
		log::Logging::LogError("could not request crawler_session_id, this is bad...");
		instance->crawlerID = -1;
		delete p;
		return (void*)1;
	}
	PERFORMANCE_LOG_STOP("RegisterCrawlerThread overall");

	delete p;
	return NULL;
}

}
