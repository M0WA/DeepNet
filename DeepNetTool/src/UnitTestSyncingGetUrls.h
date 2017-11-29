/*
 * @file UnitTestSyncingGetUrls.h
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#pragma once

#include "UnitTest.h"

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

/**
 * @brief implements unit tests for syncing urls (get_urls)
 * @see syncing::GetUrlsThread
 */
class UnitTestSyncingGetUrls : public UnitTest {
public:
	UnitTestSyncingGetUrls(database::DatabaseConnection* connection);
	virtual ~UnitTestSyncingGetUrls();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestSyncingGetUrls"; }

private:
	database::DatabaseConnection* connection;
};

}
