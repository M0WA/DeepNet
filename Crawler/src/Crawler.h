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

#include "UrlFetcherThread.h"

namespace database {
	class DatabaseConfig;
}

namespace crawler
{

/**
 * @brief generic crawler thread implementation.
 */
class Crawler : public threading::Thread
{
public:
	/**
	 * @struct CrawlerParam
	 * @brief generic crawler parameters.
	 */
	struct CrawlerParam
	{
		CrawlerParam()
		: threadCount(8)
		, waitOnIdle(25)
		, minAge(30)
		, maxPerSelect(20)
		, userAgent("Mozilla/5.0 (Windows NT 6.2; rv:9.0.1) Gecko/20100101 Firefox/9.0.1")
		, connectTimeout(8)
		, connectionTimeout(15)
		, useIPv6(false)
		, speedLimitKB(300)
		, respectRobotsTxt(false)
		, databaseConfig(0)
		{
		}

		/**
		 * maximum number of concurrent url fetcher threads.
		 */
		int threadCount;

		/**
		 * how long to sleep before retrying to get a new url to fetch (in seconds).
		 */
		int waitOnIdle;

		/**
		 * minimum age of an url before recrawling (in days).
		 */
		int minAge;

		/**
		 * maximum number urls that should be fetched at once from database.
		 */
		int maxPerSelect;

		/**
		 * useragent.
		 */
		std::string userAgent;

		/**
		 * TODO: document
		 */
		int connectTimeout;

		/**
		 * TODO: document
		 */
		int connectionTimeout;

		/**
		 * TODO: document
		 */
		bool useIPv6;

		/**
		 * speed limit in kb (upload and download).
		 */
		int speedLimitKB;

		/**
		 * crawl only if allowed by robots.txt.
		 */
		bool respectRobotsTxt;

		/**
		 * database configuration.
		 */
		database::DatabaseConfig* databaseConfig;

		/**
		 * type of the http client
		 */
		network::HttpClientFactory::HttpClientType clientType;
	};

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
	std::map<UrlFetcherThread*,UrlFetcherThread::UrlFetcherThreadParam*> urlFetcherThreads;
};

}
