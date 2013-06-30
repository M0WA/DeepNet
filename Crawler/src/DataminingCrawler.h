/**
 * @file DataminingCrawler.h
 * @author Moritz Wagner
 * @date 07.10.2012
 */

#pragma once

#include "Crawler.h"

namespace crawler {

/**
 * @brief crawler implementation for datamining.
 * @see crawler::DataminingUrlFetcherThread
 * @see crawler::Crawler
 * this class implements the crawler::Crawler for datamining.
 */
class DataminingCrawler: public crawler::Crawler {

	friend class CrawlerFactory;

private:
	DataminingCrawler();
public:
	virtual ~DataminingCrawler();

private:
	virtual bool StartCrawler();
};

}

