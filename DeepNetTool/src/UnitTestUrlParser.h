/**
 *
 * @file UnitTestUrlParser.cpp
 * @author Moritz Wagner
 * @date 24.08.2012
 *
 */

#pragma once

#include <string>
#include <vector>

#include "UnitTest.h"
#include "UnitTestUrl.h"

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

/**
 * @brief implements unit tests for parsing URLs
 * @see network::HttpUrl
 */
class UnitTestUrlParser : public UnitTest {
public:
	UnitTestUrlParser(database::DatabaseConnection* connection,
			const std::string& validUrlFileName,
			const std::string& invalidUrlFileName);
	virtual ~UnitTestUrlParser();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestUrlParser"; }

private:
	static bool TestInvalidUrls(database::DatabaseConnection* connection, const std::string& urlFileName);
	bool TestValidUrls(const std::string& urlFileName);

	static void OnError(const std::string& message, const UnitTestUrl& errorUrl);

private:
	database::DatabaseConnection* connection;
	const std::string validUrlFileName;
	const std::string invalidUrlFileName;
	std::vector<UnitTestUrl> testUrls;
};

}

