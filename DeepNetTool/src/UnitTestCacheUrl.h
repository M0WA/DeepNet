/*
 * UnitTestCacheUrl.h
 *
 *  Created on: 25.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <vector>

#include "UnitTestUrl.h"
#include "UnitTest.h"

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

class UnitTestCacheUrl : public UnitTest {
public:
	UnitTestCacheUrl(database::DatabaseConnection* connection,const std::string& urlFileName);
	virtual ~UnitTestCacheUrl();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestCacheUrl"; }

private:
	static bool TestSingleEntry(database::DatabaseConnection* connection, UnitTestUrl& testUrl);

private:
	database::DatabaseConnection* connection;
	std::vector<UnitTestUrl> testUrls;
};

}

