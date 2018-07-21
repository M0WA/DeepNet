/**
 * @file GenericWebUrlFetcherThread.h
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#pragma once

#include <ctime>
#include <vector>
#include <map>

#include <DatabaseLayer.h>

#include "UrlFetcherThreadParam.h"
#include "UrlFetcherThread.h"

namespace crawler {

	class CrawlerParam;

/**
 * @brief generic web crawler url fetcher thread implementation
 */
class GenericWebUrlFetcherThread : public UrlFetcherThread {

public:
	GenericWebUrlFetcherThread();
	virtual ~GenericWebUrlFetcherThread();

protected:
	//UrlFetchThread
	virtual bool GetNextUrlIDs(const long long& maxUrls,std::vector<long long>& urlIDs);

protected:
	//overridables
	virtual long long GetSecondLevelDomainID();

private:
	long long sldID;
	time_t    start;
};

}
