/**
 *
 * @file CrawlerParam.h
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#pragma once

#include <string>

#include <HttpClientFactory.h>

namespace database {
	class DatabaseConfig;
}

namespace crawler {

/**
 * @brief generic crawler parameters
 */
class CrawlerParam {
public:
	CrawlerParam();
	virtual ~CrawlerParam();

	/**
	 * maximum number of concurrent url fetcher threads
	 */
	int threadCount;

	/**
	 * how long to sleep before retrying to get a new url to fetch (in seconds).
	 */
	int waitOnIdle;

	/**
	 * minimum age of an url before recrawling (in days)
	 */
	int minAge;

	/**
	 * maximum number urls that should be fetched at once from database
	 */
	int maxPerSelect;

	/**
	 * useragent
	 */
	std::string userAgent;

	/**
	 * timeout for connect()
	 */
	int connectTimeout;

	/**
	 * timeout for connection
	 */
	int connectionTimeout;

	/**
	 * maximum download size when crawling websites
	 */
	size_t maxDownloadSize;

	/**
	 * true when IPv6 is used
	 */
	bool useIPv6;

	/**
	 * speed limit in kb (upload and download)
	 */
	int speedLimitKB;

	/**
	 * crawl only if allowed by robots.txt
	 */
	bool respectRobotsTxt;

	/**
	 * database configuration
	 */
	database::DatabaseConfig* databaseConfig;

	/**
	 * type of the http client
	 */
	network::HttpClientFactory::HttpClientType clientType;

	/**
	 * url of sync web api
	 */
	std::string syncApiUrl;

	/**
	 * password of sync web api
	 */
	std::string syncApiPass;
};

}
