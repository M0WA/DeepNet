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

private:
	virtual bool LockNextSecondLevelDomain();
	virtual bool CheckSecondLevelDomainTimeout(database::SelectResultContainer<database::locksecondleveldomainTableBase>& tblLockDomains);
	virtual void CheckMaxSecondLevelDomain();

private:
	const FencedUrlFetcherThreadParam* fencedParam;
	bool isDomainsReserved;
};

}
