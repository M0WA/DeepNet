/*
 * @file UnitTestSyncingRegisterCrawler.h
 * @date Dec 3, 2017
 * @author Moritz Wagner
 */

#pragma once

#include "UnitTest.h"

namespace database {
	class DatabaseConfig;
}

namespace toolbot {

class UnitTestSyncingRegisterCrawler : public toolbot::UnitTest {
public:
	UnitTestSyncingRegisterCrawler(database::DatabaseConfig* conf);
	virtual ~UnitTestSyncingRegisterCrawler();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestSyncingRegisterCrawler"; }

private:
	database::DatabaseConfig* conf;
};

}
