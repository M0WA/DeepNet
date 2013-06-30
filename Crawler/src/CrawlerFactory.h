/**
 *
 * @file CrawlerFactory.h
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#pragma once

#include <vector>

namespace crawler {

	class Crawler;

class CrawlerFactory {
private:
	CrawlerFactory();
public:
	virtual ~CrawlerFactory();

public:
	static Crawler* CreateCommerceSearchCrawler();
	static Crawler* CreateDataminingCrawler();
	static Crawler* CreateGenericWebCrawler();
	static Crawler* CreateFencedCrawler(const std::vector<long long>& boundSecondLevelDomains);
};

}
