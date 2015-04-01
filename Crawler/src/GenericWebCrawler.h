/**
 * @file GenericWebCrawler.h
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#pragma once

#include "Crawler.h"

namespace crawler {

	class CrawlerParam;
	class CrawlerFactory;

/**
 * @brief generic web crawler thread implementation.
 * @see crawler::GenericWebUrlFetcherThread
 * @see crawler::DataminingCrawler
 */
class GenericWebCrawler: public crawler::Crawler {

	friend class CrawlerFactory;

private:
	GenericWebCrawler(const CrawlerParam* crawlerParam);
public:
	virtual ~GenericWebCrawler();

private:
	virtual bool StartCrawler();
};

}
