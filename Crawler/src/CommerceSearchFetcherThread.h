/**
 * @file CommerceSearchFetcherThread.h
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#pragma once

#include <map>
#include <vector>

#include "UrlFetcherThread.h"
#include <DatabaseUrl.h>

namespace crawler {

/**
 * @brief url fetcher implementation for commerce search.
 * @see crawler::CommerceSearchCrawler
 * @see crawler::UrlFetcherThread
 * this class implements the crawler::UrlFetcherThread for the commerce search.
 */
class CommerceSearchFetcherThread : public UrlFetcherThread {

public:
	struct CommerceSearchFetcherThreadParam : public UrlFetcherThread::UrlFetcherThreadParam {
		CommerceSearchFetcherThreadParam()
		: UrlFetcherThreadParam() {
		}
	};

private:
	struct CustomerDomainProperties
	{
		CustomerDomainProperties(const htmlparser::DatabaseUrl& url)
		: url(url)
		, customerDomainId(-1)
		, customerId(-1)
		, revisitInterval(-1)
		{}

		htmlparser::DatabaseUrl url;
		long long customerDomainId;
		long long customerId;
		long long revisitInterval;
	};

public:
	CommerceSearchFetcherThread();
	virtual ~CommerceSearchFetcherThread();

private:
	virtual bool GetNextSecondLevelDomain();
	virtual bool ReserveNextUrls(std::vector<long long>& urlIDs);

private:
	std::map<long long, CustomerDomainProperties > mapCustDomIdProperties;
	std::map<long long,time_t> activeCustomerDomainIds;
};

}
