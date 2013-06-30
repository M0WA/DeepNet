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
		DataminingUrlFetcherThread::DataminingUrlFetcherThreadParam* threadParam = new DataminingUrlFetcherThread::DataminingUrlFetcherThreadParam(*crawlerParam);
		DataminingUrlFetcherThread* urlFetcherThread = new DataminingUrlFetcherThread();
		urlFetcherThread->StartThread(threadParam);

		urlFetcherThreads[dynamic_cast<UrlFetcherThread*>(urlFetcherThread)] =
				dynamic_cast<UrlFetcherThreadParam*>(threadParam);
	}
	tools::thread_cleanup();
	return true;
}

}
