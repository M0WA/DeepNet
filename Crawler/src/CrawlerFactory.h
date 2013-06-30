/**
 *
 * @file CrawlerFactory.h
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#pragma once

namespace crawler {

	class Crawler;
	class CrawlerParam;

class CrawlerFactory {
private:
	CrawlerFactory();
public:
	virtual ~CrawlerFactory();

public:
	static Crawler* CreateCommerceSearchCrawler(const CrawlerParam* crawlerParam);
	static Crawler* CreateDataminingCrawler(const CrawlerParam* crawlerParam);
	static Crawler* CreateGenericWebCrawler(const CrawlerParam* crawlerParam);
	static Crawler* CreateFencedCrawler(const CrawlerParam* crawlerParam);
};

}
