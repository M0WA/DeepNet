/*
 * HtmlParserParam.h
 *
 *  Created on: 05.09.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <HtmlParserFactory.h>

namespace database {
	class DatabaseConfig;
}

namespace parser {

class HtmlParserParam {
public:
	HtmlParserParam();
	virtual ~HtmlParserParam();

	unsigned int parserThreadCount;
	int waitOnIdle;
	int maxPerSelect;
	database::DatabaseConfig* databaseConfig;
	htmlparser::HtmlParserFactory::HtmlParserType parserType;
};

}

