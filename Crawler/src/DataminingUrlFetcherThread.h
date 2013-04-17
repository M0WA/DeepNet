/**
 * @file DataminingUrlFetcherThread.h
 * @author Moritz Wagner
 * @date 07.10.2012
 */

#pragma once

#include <vector>

#include "GenericWebUrlFetcherThread.h"

namespace crawler {

/**
 * @brief url fetcher implementation for datamining.
 * @see crawler::DataminingCrawler
 * @see crawler::GenericWebUrlFetcherThread
 * this class implements the crawler::UrlFetcherThread for the commerce search.
 */
class DataminingUrlFetcherThread: public crawler::GenericWebUrlFetcherThread {

public:
	struct DataminingUrlFetcherThreadParam : public GenericWebUrlFetcherThread::GenericWebUrlFetcherThreadParam {
		DataminingUrlFetcherThreadParam() : GenericWebUrlFetcherThreadParam() {}
	};

public:
	DataminingUrlFetcherThread();
	virtual ~DataminingUrlFetcherThread();
};

}

