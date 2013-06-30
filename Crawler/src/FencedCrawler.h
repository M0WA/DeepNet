/**
 *
 * @file FencedCrawler.h
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#pragma once

#include <vector>

#include "Crawler.h"
#include "CrawlerParam.h"

namespace crawler {

class FencedCrawler : public Crawler {

public:
	struct FencedCrawlerParam : public CrawlerParam {
		std::vector<long long> secondLevelDomains;
	};

public:
	FencedCrawler();
	virtual ~FencedCrawler();

private:
	virtual bool StartCrawler();
};

}
