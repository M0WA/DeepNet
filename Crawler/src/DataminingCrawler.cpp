/**
 * @file DataminingCrawler.cpp
 * @author Moritz Wagner
 * @date 07.10.2012
 */

#include "DataminingCrawler.h"
#include "DataminingUrlFetcherThread.h"

#include <OpenSSLThreadLock.h>

namespace crawler {

DataminingCrawler::DataminingCrawler() {
}

DataminingCrawler::~DataminingCrawler() {
}

bool DataminingCrawler::StartCrawler()
{
	tools::thread_setup();
	for(int i = 0; i < crawlerParam->threadCount; i++)
	{
		DataminingUrlFetcherThread::DataminingUrlFetcherThreadParam* threadParam = new DataminingUrlFetcherThread::DataminingUrlFetcherThreadParam();
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

		DataminingUrlFetcherThread* urlFetcherThread = new DataminingUrlFetcherThread();
		urlFetcherThread->StartThread(threadParam);

		urlFetcherThreads[dynamic_cast<UrlFetcherThread*>(urlFetcherThread)] =
				dynamic_cast<UrlFetcherThread::UrlFetcherThreadParam*>(threadParam);
	}
	tools::thread_cleanup();
	return true;
}

}
