/**
 * @file GenericWebCrawler.cpp
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#include "GenericWebCrawler.h"
#include "GenericWebUrlFetcherThread.h"
#include "GenericWebUrlFetcherThreadParam.h"

#include <OpenSSLThreadLock.h>

namespace crawler {

GenericWebCrawler::GenericWebCrawler()
: Crawler() {
}

GenericWebCrawler::~GenericWebCrawler() {
}

bool GenericWebCrawler::StartCrawler()
{
	tools::thread_setup();
	for(int i = 0; i < crawlerParam->threadCount; i++)
	{
		GenericWebUrlFetcherThreadParam* threadParam = new GenericWebUrlFetcherThreadParam(*crawlerParam);
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
		threadParam->clientType        = crawlerParam->clientType;
*/
		GenericWebUrlFetcherThread* urlFetcherThread = new GenericWebUrlFetcherThread();
		urlFetcherThread->StartThread(threadParam);

		urlFetcherThreads[dynamic_cast<UrlFetcherThread*>(urlFetcherThread)] =
				dynamic_cast<UrlFetcherThreadParam*>(threadParam);
	}
	tools::thread_cleanup();
	return true;
}

}
