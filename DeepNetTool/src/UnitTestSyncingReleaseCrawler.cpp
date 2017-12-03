/*
 * @file UnitTestSyncingReleaseCrawler.cpp
 * @date Dec 2, 2017
 * @author Moritz Wagner
 */

#include "UnitTestSyncingReleaseCrawler.h"

#include <ReleaseCrawlerThread.h>

namespace toolbot {

UnitTestSyncingReleaseCrawler::UnitTestSyncingReleaseCrawler(database::DatabaseConfig* conf)
: conf(conf) {
}

UnitTestSyncingReleaseCrawler::~UnitTestSyncingReleaseCrawler() {
}

bool UnitTestSyncingReleaseCrawler::Run() {

	syncing::ReleaseCrawlerThread* thread(new syncing::ReleaseCrawlerThread());
	syncing::ReleaseCrawlerThread::ReleaseCrawlerThreadParam* p(new syncing::ReleaseCrawlerThread::ReleaseCrawlerThreadParam);

	p->pParam = p;
	p->instance = thread;
	p->crawlerID = 1;
	p->dbConf = conf;

	void* rc(syncing::ReleaseCrawlerThread::ReleaseCrawlerThreadFunc(p));

	return !rc;
}

}
