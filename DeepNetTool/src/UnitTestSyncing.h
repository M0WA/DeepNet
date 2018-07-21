/*
 * @file UnitTestSyncing.h
 * @date Dec 3, 2017
 * @author Moritz Wagner
 */

#pragma once

#include "UnitTest.h"

namespace database {
	class DatabaseConfig;
}

namespace toolbot {

/**
 * @brief unit test for Syncing library
 */
class UnitTestSyncing : public UnitTest {
public:
	UnitTestSyncing(database::DatabaseConfig* conf);
	virtual ~UnitTestSyncing();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestSyncing"; }

private:
	bool CheckRegisterCrawler();
	bool CheckGetUrls();
	bool CheckReleaseCrawler();

private:
	database::DatabaseConfig* conf;
	long long crawlerID;
};

}
