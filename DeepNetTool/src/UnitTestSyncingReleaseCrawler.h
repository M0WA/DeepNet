/*
 * @file UnitTestSyncingReleaseCrawler.h
 * @date Dec 2, 2017
 * @author Moritz Wagner
 */

#pragma once

#include "UnitTest.h"

namespace database {
	class DatabaseConfig;
}

namespace toolbot {

class UnitTestSyncingReleaseCrawler: public UnitTest {
public:
	UnitTestSyncingReleaseCrawler(database::DatabaseConfig* conf);
	virtual ~UnitTestSyncingReleaseCrawler();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestSyncingReleaseCrawler"; }

private:
	database::DatabaseConfig* conf;
};

}
