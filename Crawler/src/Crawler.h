/**
 * @file Crawler.h
 * @author Moritz Wagner
 * @date 06.03.2012
 */

#pragma once

#include <string>
#include <map>

#include <HttpClientFactory.h>
#include <Thread.h>

namespace database {
	class DatabaseConfig;
}

namespace crawler
{
	class UrlFetcherThreadParam;
	class UrlFetcherThread;
	class CrawlerParam;

/**
 * @brief generic crawler thread implementation.
 */
class Crawler : public threading::Thread
{
public:
	Crawler();
	virtual ~Crawler();

private:
	/**
	 * starts crawler thread.
	 * @return false on error, true on success.
	 */
	virtual bool StartCrawler()=0;

private:
	bool StopCrawler();
	bool WatchDog();

private:
	static void* CrawlerThreadFunc(threading::Thread::THREAD_PARAM* threadParam);

protected:
	/**
	 * crawler parameters associated with this thread.
	 */
	CrawlerParam* crawlerParam;

	/**
	 * map of url fetcher threads and their parameters.
	 */
	std::map<UrlFetcherThread*,UrlFetcherThreadParam*> urlFetcherThreads;
};

}
