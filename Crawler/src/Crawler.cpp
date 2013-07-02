/**
 * @file Crawler.cpp
 * @author Moritz Wagner
 * @date 06.03.2012
 */

#include "Crawler.h"

#include "CrawlerParam.h"
#include "UrlFetcherThread.h"
#include "UrlFetcherThreadParam.h"

#include <Logging.h>

using namespace threading;

namespace crawler
{

Crawler::Crawler(const CrawlerParam* crawlerParam)
: Thread((Thread::ThreadFunction)&(Crawler::CrawlerThreadFunc))
, crawlerParam(crawlerParam)
{
}

Crawler::~Crawler() {
}

void* Crawler::CrawlerThreadFunc(Thread::THREAD_PARAM* threadParam)
{
	log::Logging::RegisterThreadID("Crawler");

	Crawler* instance = (Crawler*)threadParam->instance;
	instance->oldCrawlerSessionIDs.clear();

	if(!instance->StartCrawler())
		return (void*)1;

	bool errorOccured = false;
	while(!instance->ShallEnd())
	{
		if(instance->WatchDog()) {
			errorOccured = true;
			break; }

		sleep(1);
	}

	bool bReturn = !instance->StopCrawler() || errorOccured;
	instance->crawlerParam = NULL;
	return (void*)bReturn;
}

bool Crawler::StopCrawler()
{
	std::map<UrlFetcherThread*,UrlFetcherThreadParam*>::iterator iterThreads = urlFetcherThreads.begin();

	for(; iterThreads != urlFetcherThreads.end(); ++iterThreads) {
		iterThreads->first->SetShallEnd(true);
	}

	iterThreads = urlFetcherThreads.begin();
	for(; iterThreads != urlFetcherThreads.end(); ++iterThreads)
	{
		iterThreads->first->WaitForThread();
		oldCrawlerSessionIDs.push_back(iterThreads->first->GetOldCrawlerSessionID());
		delete iterThreads->first;
		delete iterThreads->second;
	}
	urlFetcherThreads.clear();

	return true;
}

bool Crawler::WatchDog()
{
	std::map<UrlFetcherThread*,UrlFetcherThreadParam*>::iterator iterThreads = urlFetcherThreads.begin();

	//check if at least one thread is alive
	for(; iterThreads != urlFetcherThreads.end(); ++iterThreads){
		if ( iterThreads->first->IsRunning() )
			return false;
	}
	return true;
}

const std::vector<long long>& Crawler::GetOldCrawlerSessionIDs() const {
	return oldCrawlerSessionIDs;
}

}
