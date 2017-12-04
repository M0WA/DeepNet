/*
 * @file UnitTestSyncing.cpp
 * @date Dec 3, 2017
 * @author Moritz Wagner
 */

#include "UnitTestSyncing.h"

#include <GetUrlsThread.h>
#include <RegisterCrawlerThread.h>
#include <ReleaseCrawlerThread.h>

#include <Logging.h>

namespace toolbot {

UnitTestSyncing::UnitTestSyncing(database::DatabaseConfig* conf)
: conf(conf)
, crawlerID(-1) {
}

UnitTestSyncing::~UnitTestSyncing() {
}


bool UnitTestSyncing::CheckRegisterCrawler() {

	syncing::RegisterCrawlerThread* tRC(new syncing::RegisterCrawlerThread());
	syncing::RegisterCrawlerThread::RegisterCrawlerThreadParam* pRC(new syncing::RegisterCrawlerThread::RegisterCrawlerThreadParam());

	pRC->pParam = pRC;
	pRC->instance = tRC;
	pRC->dbConf = conf;

	void* rcRC(syncing::RegisterCrawlerThread::RegisterCrawlerThreadFunc(pRC));
	if(rcRC) {
		log::Logging::LogError("error while registering crawler");
		return false;
	}
	crawlerID = tRC->GetCrawlerID();
	if(crawlerID == -1) {
		log::Logging::LogError("invalid crawler id while registering crawler");
		return false;
	}

	return true;
}

bool UnitTestSyncing::CheckGetUrls() {

	syncing::GetUrlsThread* tG(new syncing::GetUrlsThread());
	syncing::GetUrlsThread::GetUrlsThreadParam* pG(new syncing::GetUrlsThread::GetUrlsThreadParam);

	pG->pParam = pG;
	pG->instance = tG;
	pG->crawlerID = crawlerID;
	pG->dbConf = conf;
	pG->urlCount = 2;
	pG->secondlevelDomain = 1;

	void* rcG(syncing::GetUrlsThread::GetUrlsThreadFunc(pG));
	if(rcG) {
		log::Logging::LogError("error while getting url ids");
		return false;
	}

	const std::vector<long long>& urlIDs(tG->GetUrlIDs());
	if(urlIDs.size() != (size_t)pG->urlCount) {
		log::Logging::LogError("invalid count (%lu) while getting url ids",urlIDs.size());
		return false;
	}
	return true;
}

bool UnitTestSyncing::CheckReleaseCrawler() {


	syncing::ReleaseCrawlerThread* tLC(new syncing::ReleaseCrawlerThread());
	syncing::ReleaseCrawlerThread::ReleaseCrawlerThreadParam* pLC(new syncing::ReleaseCrawlerThread::ReleaseCrawlerThreadParam);

	pLC->pParam = pLC;
	pLC->instance = tLC;
	pLC->crawlerID = crawlerID;
	pLC->dbConf = conf;

	void* rcLC(syncing::ReleaseCrawlerThread::ReleaseCrawlerThreadFunc(pLC));
	if(rcLC) {
		log::Logging::LogError("error while releasing crawler id");
		return false;
	}

	return true;
}

bool UnitTestSyncing::Run() {

	if(!CheckRegisterCrawler()) {
		return false; }

	bool success(true);
	if(!CheckGetUrls()) {
		success = false; }

	success &= CheckReleaseCrawler();

	log::Logging::RegisterThreadID("");
	return success;
}

}
