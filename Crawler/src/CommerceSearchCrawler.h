/**
 * @file CommerceSearchCrawler.h
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#pragma once

#include "Crawler.h"

namespace crawler {

/**
 * @brief crawler implementation for commerce search.
 * @see crawler::CommerceSearchFetcherThread
 * @see crawler::Crawler
 * this class implements the crawler::Crawler for the commerce search.
 */
class CommerceSearchCrawler: public crawler::Crawler {
public:
	CommerceSearchCrawler();
	virtual ~CommerceSearchCrawler();

private:
	virtual bool StartCrawler();
};

}
