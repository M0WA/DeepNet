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

	class CrawlerFactory;
	class CrawlerParam;

class FencedCrawler : public Crawler {

	friend class CrawlerFactory;

private:
	FencedCrawler(const CrawlerParam* crawlerParam);
public:
	virtual ~FencedCrawler();

private:
	virtual bool StartCrawler();

private:
	std::vector<long long> boundSecondLevelDomains;
};

}
