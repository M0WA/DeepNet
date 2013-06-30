/**
 * @file GenericWebCrawler.h
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#pragma once

#include "Crawler.h"

namespace crawler {

/**
 * @brief generic web crawler thread implementation.
 * @see crawler::GenericWebUrlFetcherThread
 * @see crawler::DataminingCrawler
 */
class GenericWebCrawler: public crawler::Crawler {
public:
	GenericWebCrawler();
	virtual ~GenericWebCrawler();

private:
	virtual bool StartCrawler();
};

}
