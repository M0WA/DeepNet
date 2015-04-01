/**
 *
 * @file GenericWebUrlFetcherThreadParam.h
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#pragma once

#include "UrlFetcherThreadParam.h"

namespace crawler {

	class CrawlerParam;

class GenericWebUrlFetcherThreadParam : public UrlFetcherThreadParam{
public:
	GenericWebUrlFetcherThreadParam(const CrawlerParam& crawlerParam);
	virtual ~GenericWebUrlFetcherThreadParam();
};

}
