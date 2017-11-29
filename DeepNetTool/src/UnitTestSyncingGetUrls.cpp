/*
 * @file UnitTestSyncingGetUrls.cpp
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#include "UnitTestSyncingGetUrls.h"

#include <GetUrlsThread.h>

namespace toolbot {

UnitTestSyncingGetUrls::UnitTestSyncingGetUrls(database::DatabaseConnection* connection)
: connection(connection) {
}

UnitTestSyncingGetUrls::~UnitTestSyncingGetUrls() {
}

bool UnitTestSyncingGetUrls::UnitTestSyncingGetUrls::Run() {

	return false;

	syncing::GetUrlsThread* thread(new syncing::GetUrlsThread());
	syncing::GetUrlsThread::GetUrlsThreadParam* p(new syncing::GetUrlsThread::GetUrlsThreadParam);

	p->pParam = p;
	p->instance = thread;
	p->crawlerID = 1;
	p->dbConn = connection;
	p->urlCount = 2;
	p->minAge = 20;
	p->secondlevelDomain = 1;

	void* rc(syncing::GetUrlsThread::GetUrlsThreadFunc(p));

	//TODO: check result

	return !rc;
}

}
