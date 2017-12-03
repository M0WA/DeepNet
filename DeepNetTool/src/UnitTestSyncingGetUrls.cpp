/*
 * @file UnitTestSyncingGetUrls.cpp
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#include "UnitTestSyncingGetUrls.h"

#include <GetUrlsThread.h>

namespace toolbot {

UnitTestSyncingGetUrls::UnitTestSyncingGetUrls(database::DatabaseConfig* conf)
: conf(conf) {
}

UnitTestSyncingGetUrls::~UnitTestSyncingGetUrls() {
}

bool UnitTestSyncingGetUrls::UnitTestSyncingGetUrls::Run() {

	syncing::GetUrlsThread* thread(new syncing::GetUrlsThread());
	syncing::GetUrlsThread::GetUrlsThreadParam* p(new syncing::GetUrlsThread::GetUrlsThreadParam);

	p->pParam = p;
	p->instance = thread;
	p->crawlerID = 1;
	p->dbConf = conf;
	p->urlCount = 2;
	p->secondlevelDomain = 1;

	void* rc(syncing::GetUrlsThread::GetUrlsThreadFunc(p));

	//TODO: check result

	return !rc;
}

}
