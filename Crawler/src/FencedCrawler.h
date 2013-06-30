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

namespace crawler {

class FencedCrawler : public Crawler {

public:
	struct FencedCrawlerParam : public Crawler::CrawlerParam {
		std::vector<long long> secondLevelDomains;
	};

public:
	FencedCrawler();
	virtual ~FencedCrawler();

private:
	virtual bool StartCrawler();
};

}
