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

GenericWebCrawler::GenericWebCrawler(const CrawlerParam* crawlerParam)
: Crawler(crawlerParam) {
}

GenericWebCrawler::~GenericWebCrawler() {
}

bool GenericWebCrawler::StartCrawler()
{
	tools::thread_setup();
	for(int i = 0; i < crawlerParam->threadCount; i++)
	{
		GenericWebUrlFetcherThreadParam* threadParam = new GenericWebUrlFetcherThreadParam(*crawlerParam);
		GenericWebUrlFetcherThread* urlFetcherThread = new GenericWebUrlFetcherThread();
		urlFetcherThread->StartThread(threadParam);

		urlFetcherThreads[dynamic_cast<UrlFetcherThread*>(urlFetcherThread)] =
				dynamic_cast<UrlFetcherThreadParam*>(threadParam);
	}
	tools::thread_cleanup();
	return true;
}

}
