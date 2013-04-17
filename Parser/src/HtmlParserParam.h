/*
 * HtmlParserParam.h
 *
 *  Created on: 05.09.2012
 *      Author: Moritz Wagner
 */

#pragma once

namespace database {
	class DatabaseConfig;
}

namespace parser {

class HtmlParserParam {
protected:
	HtmlParserParam();
public:
	virtual ~HtmlParserParam();

	unsigned int parserThreadCount;
	int waitOnIdle;
	int maxPerSelect;
	database::DatabaseConfig* databaseConfig;
};

}

