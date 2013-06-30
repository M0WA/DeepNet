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

FencedCrawler::FencedCrawler(const CrawlerParam* crawlerParam,const std::vector<long long>& boundSecondLevelDomains)
: Crawler(crawlerParam)
, boundSecondLevelDomains(boundSecondLevelDomains){
}

FencedCrawler::~FencedCrawler() {
}

bool FencedCrawler::StartCrawler() {
	tools::thread_setup();


	//TODO: distribute second level domain id fairly among running threads (crawlerParam->threadCount)

	/*
	for(int i = 0; i < crawlerParam->threadCount; i++)
	{
		//TODO: get second level domain id
		std::vector<long long> fencedSecondLevelIDs;

		FencedUrlFetcherThread::FencedUrlFetcherThreadParam* fencedThreadParam = new FencedUrlFetcherThread::FencedUrlFetcherThreadParam(*crawlerParam,fencedSecondLevelIDs);

		//fencedThreadParam->secondLevelDomains = boundSecondLevelDomains;

		FencedUrlFetcherThread* urlFetcherThread = new FencedUrlFetcherThread();
		urlFetcherThread->StartThread(fencedThreadParam);

		urlFetcherThreads[dynamic_cast<UrlFetcherThread*>(urlFetcherThread)] =
				dynamic_cast<UrlFetcherThreadParam*>(fencedThreadParam);
	}
	*/
	tools::thread_cleanup();
	return true;
}

}
