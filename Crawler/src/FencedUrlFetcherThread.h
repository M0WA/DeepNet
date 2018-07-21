/**
 *
 * @file FencedUrlFetcherThread.h
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#pragma once

#include <vector>

#include "GenericWebUrlFetcherThread.h"
#include "GenericWebUrlFetcherThreadParam.h"

namespace crawler {

/**
 * @brief fenced crawler that is bound to specific secondlevel domains
 */
class FencedUrlFetcherThread : public GenericWebUrlFetcherThread {

public:
	class FencedUrlFetcherThreadParam : public GenericWebUrlFetcherThreadParam {
	public:
		FencedUrlFetcherThreadParam(const CrawlerParam& crawlerParam, const std::vector<long long>& secondLevelDomains)
		: GenericWebUrlFetcherThreadParam(crawlerParam)
		, secondLevelDomains(secondLevelDomains)
		{}

		std::vector<long long> secondLevelDomains;
	};

public:
	FencedUrlFetcherThread();
	virtual ~FencedUrlFetcherThread();

protected:
	virtual long long GetSecondLevelDomainID();

private:
	const FencedUrlFetcherThreadParam* fencedParam;
	std::vector<long long>::const_iterator iDom;
};

}
