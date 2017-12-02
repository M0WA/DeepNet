/*
 * @file UnitTestSyncingReleaseCrawler.cpp
 * @date Dec 2, 2017
 * @author Moritz Wagner
 */

#include "UnitTestSyncingReleaseCrawler.h"

#include <ReleaseCrawlerThread.h>

namespace toolbot {

UnitTestSyncingReleaseCrawler::UnitTestSyncingReleaseCrawler(database::DatabaseConnection* connection)
: connection(connection) {
}

UnitTestSyncingReleaseCrawler::~UnitTestSyncingReleaseCrawler() {
}

bool UnitTestSyncingReleaseCrawler::Run() {

	syncing::ReleaseCrawlerThread* thread(new syncing::ReleaseCrawlerThread(connection));
	syncing::ReleaseCrawlerThread::ReleaseCrawlerThreadParam* p(new syncing::ReleaseCrawlerThread::ReleaseCrawlerThreadParam);

	p->pParam = p;
	p->instance = thread;
	p->crawlerID = 1;
	p->dbConn = connection;

	void* rc(syncing::ReleaseCrawlerThread::ReleaseCrawlerThreadFunc(p));

	return !rc;
}

}
