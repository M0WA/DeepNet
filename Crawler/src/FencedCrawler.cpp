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

	for(int i = 0; i < crawlerParam->threadCount; i++)
	{
		//TODO: get second level domain id
		std::vector<long long> fencedSecondLevelIDs;

		FencedUrlFetcherThread::FencedUrlFetcherThreadParam* fencedThreadParam = new FencedUrlFetcherThread::FencedUrlFetcherThreadParam(*crawlerParam,fencedSecondLevelIDs);

		FencedUrlFetcherThread* urlFetcherThread = new FencedUrlFetcherThread();
		urlFetcherThread->StartThread(fencedThreadParam);

		urlFetcherThreads[dynamic_cast<UrlFetcherThread*>(urlFetcherThread)] =
				dynamic_cast<UrlFetcherThreadParam*>(fencedThreadParam);
	}
	tools::thread_cleanup();
	return true;
}

}
