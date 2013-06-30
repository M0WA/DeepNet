/**
 * @file DataminingUrlFetcherThread.h
 * @author Moritz Wagner
 * @date 07.10.2012
 */

#pragma once

#include <vector>

#include "GenericWebUrlFetcherThread.h"
#include "GenericWebUrlFetcherThreadParam.h"

namespace crawler {

	class CrawlerParam;

/**
 * @brief url fetcher implementation for datamining.
 * @see crawler::DataminingCrawler
 * @see crawler::GenericWebUrlFetcherThread
 * this class implements the crawler::UrlFetcherThread for the commerce search.
 */
class DataminingUrlFetcherThread: public crawler::GenericWebUrlFetcherThread {

public:
	class DataminingUrlFetcherThreadParam : public GenericWebUrlFetcherThreadParam {
	public:
		DataminingUrlFetcherThreadParam(const CrawlerParam& crawlerParam)
		: GenericWebUrlFetcherThreadParam(crawlerParam)
		{}
	};

public:
	DataminingUrlFetcherThread();
	virtual ~DataminingUrlFetcherThread();
};

}

