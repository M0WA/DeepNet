/**
 * @file CommerceSearchCrawler.h
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#pragma once

#include "Crawler.h"

namespace crawler {

	class CrawlerFactory;

/**
 * @brief crawler implementation for commerce search.
 * @see crawler::CommerceSearchFetcherThread
 * @see crawler::Crawler
 * this class implements the crawler::Crawler for the commerce search.
 */
class CommerceSearchCrawler: public crawler::Crawler {

	friend class CrawlerFactory;

private:
	CommerceSearchCrawler();
public:
	virtual ~CommerceSearchCrawler();

private:
	virtual bool StartCrawler();
};

}
