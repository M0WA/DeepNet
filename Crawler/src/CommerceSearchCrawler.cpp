/**
 * @file CommerceSearchCrawler.h
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#include "CommerceSearchCrawler.h"
#include "CommerceSearchFetcherThread.h"

#include <OpenSSLThreadLock.h>

namespace crawler {

CommerceSearchCrawler::CommerceSearchCrawler()
: Crawler() {
}

CommerceSearchCrawler::~CommerceSearchCrawler() {
}

bool CommerceSearchCrawler::StartCrawler()
{
	tools::thread_setup();
	for(int i = 0; i < crawlerParam->threadCount; i++)
	{
		CommerceSearchFetcherThread::CommerceSearchFetcherThreadParam* threadParam = new CommerceSearchFetcherThread::CommerceSearchFetcherThreadParam(*crawlerParam);
		/*
		threadParam->waitOnIdle        = crawlerParam->waitOnIdle;
		threadParam->minAge            = crawlerParam->minAge;
		threadParam->maxPerSelect      = crawlerParam->maxPerSelect;
		threadParam->userAgent         = crawlerParam->userAgent;
		threadParam->connectTimeout    = crawlerParam->connectTimeout;
		threadParam->connectionTimeout = crawlerParam->connectionTimeout;
		threadParam->useIPv6           = crawlerParam->useIPv6;
		threadParam->speedLimitKB      = crawlerParam->speedLimitKB;
		threadParam->respectRobotsTxt  = crawlerParam->respectRobotsTxt;
		threadParam->databaseConfig    = crawlerParam->databaseConfig;
		*/

		CommerceSearchFetcherThread* urlFetcherThread = new CommerceSearchFetcherThread();
		urlFetcherThread->StartThread(threadParam);

		urlFetcherThreads[dynamic_cast<UrlFetcherThread*>(urlFetcherThread)] =
				dynamic_cast<UrlFetcherThreadParam*>(threadParam);
	}
	tools::thread_cleanup();
	return true;
}

}
