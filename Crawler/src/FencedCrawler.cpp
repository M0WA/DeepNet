/**
 *
 * @file FencedCrawler.cpp
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#include "FencedCrawler.h"

#include <cmath>

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

	if(boundSecondLevelDomains.size() == 0) {
		//log::Logging::LogError("no secondlevel domain ids found for FencedCrawler");
		return false; }

	//check if there are more threads allowed than needed
	size_t actualThreadCount = crawlerParam->threadCount;
	if(actualThreadCount > boundSecondLevelDomains.size()) {
		actualThreadCount = boundSecondLevelDomains.size(); }
	size_t domainsPerThread = std::ceil(boundSecondLevelDomains.size()/actualThreadCount);

	size_t curPos = 0;
	for(size_t i = 0; i < actualThreadCount && curPos < boundSecondLevelDomains.size(); i++) {
		std::vector<long long> tmpBound;
		for(size_t posTmp = 0; posTmp < domainsPerThread && curPos < boundSecondLevelDomains.size(); posTmp++,curPos++) {
			tmpBound.push_back(boundSecondLevelDomains.at(curPos)); }

		if(tmpBound.size() > 0) {
			FencedUrlFetcherThread::FencedUrlFetcherThreadParam* fencedThreadParam =
					new FencedUrlFetcherThread::FencedUrlFetcherThreadParam(*crawlerParam,tmpBound);
			FencedUrlFetcherThread* urlFetcherThread = new FencedUrlFetcherThread();
			urlFetcherThread->StartThread(fencedThreadParam);

			urlFetcherThreads[dynamic_cast<UrlFetcherThread*>(urlFetcherThread)] =
					dynamic_cast<UrlFetcherThreadParam*>(fencedThreadParam);
		}
	}
	tools::thread_cleanup();
	return true;
}

}
