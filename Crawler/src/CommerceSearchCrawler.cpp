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
		CommerceSearchFetcherThread* urlFetcherThread = new CommerceSearchFetcherThread();
		urlFetcherThread->StartThread(threadParam);

		urlFetcherThreads[dynamic_cast<UrlFetcherThread*>(urlFetcherThread)] =
				dynamic_cast<UrlFetcherThreadParam*>(threadParam);
	}
	tools::thread_cleanup();
	return true;
}

}
