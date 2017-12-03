/*
 * @file UnitTestSyncingRegisterCrawler.cpp
 * @date Dec 3, 2017
 * @author Moritz Wagner
 */

#include "UnitTestSyncingRegisterCrawler.h"

#include <RegisterCrawlerThread.h>

namespace toolbot {

UnitTestSyncingRegisterCrawler::UnitTestSyncingRegisterCrawler(database::DatabaseConfig* conf)
: conf(conf) {
}

UnitTestSyncingRegisterCrawler::~UnitTestSyncingRegisterCrawler() {
}

bool UnitTestSyncingRegisterCrawler::Run() {

	syncing::RegisterCrawlerThread* thread(new syncing::RegisterCrawlerThread());
	syncing::RegisterCrawlerThread::RegisterCrawlerThreadParam* p(new syncing::RegisterCrawlerThread::RegisterCrawlerThreadParam());

	p->pParam = p;
	p->instance = thread;
	p->dbConf = conf;

	void* rc(syncing::RegisterCrawlerThread::RegisterCrawlerThreadFunc(p));
	if(rc) {
		return false;
	}
	if(thread->GetCrawlerID() == -1) {
		return false;
	}
	return true;
}

}
