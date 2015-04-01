/**
 *
 * @file UrlFetcherThreadParam.h
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#pragma once

#include <string>
#include <HttpClientFactory.h>

#include "CrawlerParam.h"

namespace database {
	class DatabaseConfig;
}

namespace crawler {

/**
 * @brief url fetcher parameters.
 */
class UrlFetcherThreadParam : public CrawlerParam {
public:
	UrlFetcherThreadParam(const CrawlerParam& crawler);
	virtual ~UrlFetcherThreadParam();
};

}
