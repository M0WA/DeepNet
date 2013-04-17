/*
 * UnitTestCacheUrl.h
 *
 *  Created on: 25.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

#include "UnitTestUrlParser.h"
#include "UnitTestUrl.h"

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

class UnitTestCacheUrl {
private:
	UnitTestCacheUrl();
public:
	virtual ~UnitTestCacheUrl();

public:
	static bool TestUrlCache(database::DatabaseConnection* connection, std::vector<UnitTestUrl>& testUrls);

private:
	static bool TestSingleEntry(database::DatabaseConnection* connection, UnitTestUrl& testUrl);
};

}

