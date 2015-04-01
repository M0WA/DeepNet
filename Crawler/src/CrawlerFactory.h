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

/**
 * @brief factory class for crawler::Crawler based classes
 */
class CrawlerFactory {
private:
	CrawlerFactory();
public:
	virtual ~CrawlerFactory();

public:
	/**
	 * creates a new commerce search crawler
	 * @param crawlerParam crawler parameters
	 * @return new commerce search crawler
	 */
	static Crawler* CreateCommerceSearchCrawler(const CrawlerParam* crawlerParam);

	/**
	 * creates a new datamining crawler
	 * @param crawlerParam crawler parameters
	 * @return new datamining crawler
	 */
	static Crawler* CreateDataminingCrawler(const CrawlerParam* crawlerParam);

	/**
	 * creates a new generic web crawler (i.e. search engine)
	 * @param crawlerParam crawler parameters
	 * @return new commerce search crawler
	 */
	static Crawler* CreateGenericWebCrawler(const CrawlerParam* crawlerParam);

	/**
	 * creates a new fenced search crawler (i.e. fenced search for datamining customers)
	 * @param crawlerParam crawler parameters
	 * @return new fenced crawler
	 */
	static Crawler* CreateFencedCrawler(const CrawlerParam* crawlerParam);
};

}
