/**
 *
 * @file FencedCrawler.cpp
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#include "FencedCrawler.h"

#include <OpenSSLThreadLock.h>

#include "FencedUrlFetcherThread.h"

namespace crawler {

FencedCrawler::FencedCrawler() {
}

FencedCrawler::~FencedCrawler() {
}

bool FencedCrawler::StartCrawler() {
	tools::thread_setup();

	/*
	FencedCrawlerParam* fencedParam = dynamic_cast<FencedCrawlerParam*>(crawlerParam);
	for(int i = 0; i < fencedParam->threadCount; i++)
	{
		FencedUrlFetcherThread::FencedUrlFetcherThreadParam* fencedThreadParam = new FencedUrlFetcherThread::FencedUrlFetcherThreadParam();
		fencedThreadParam->waitOnIdle        = fencedParam->waitOnIdle;
		fencedThreadParam->minAge            = fencedParam->minAge;
		fencedThreadParam->maxPerSelect      = fencedParam->maxPerSelect;
		fencedThreadParam->userAgent         = fencedParam->userAgent;
		fencedThreadParam->connectTimeout    = fencedParam->connectTimeout;
		fencedThreadParam->connectionTimeout = fencedParam->connectionTimeout;
		fencedThreadParam->useIPv6           = fencedParam->useIPv6;
		fencedThreadParam->speedLimitKB      = fencedParam->speedLimitKB;
		fencedThreadParam->respectRobotsTxt  = fencedParam->respectRobotsTxt;
		fencedThreadParam->databaseConfig    = fencedParam->databaseConfig;
		fencedThreadParam->clientType        = fencedParam->clientType;
		fencedThreadParam->secondLevelDomains= fencedParam->secondLevelDomains;

		FencedUrlFetcherThread* urlFetcherThread = new FencedUrlFetcherThread();
		urlFetcherThread->StartThread(fencedThreadParam);

		urlFetcherThreads[dynamic_cast<UrlFetcherThread*>(urlFetcherThread)] =
				dynamic_cast<UrlFetcherThread::UrlFetcherThreadParam*>(fencedThreadParam);
	}
	*/
	tools::thread_cleanup();
	return true;
}

}
