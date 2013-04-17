/*
 * UnitTestUrlParser.h
 *
 *  Created on: 24.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <vector>

#include "UnitTestUrl.h"

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

class UnitTestUrlParser {
private:
	UnitTestUrlParser();
public:
	virtual ~UnitTestUrlParser();

public:
	static bool TestUrlParser(
		database::DatabaseConnection* connection,
		const std::string& validUrlFileName,
		const std::string& invalidUrlFileName,
		std::vector<UnitTestUrl>& testUrls);

private:
	static bool ReadInvalidURLFile(const std::string& urlFileName, std::vector<UnitTestUrl>& testUrls);
	static bool TestInvalidUrls(database::DatabaseConnection* connection, const std::string& urlFileName);

	static bool ReadValidURLFile(const std::string& urlFileName, std::vector<UnitTestUrl>& testUrls);
	static bool TestValidUrls(database::DatabaseConnection* connection, const std::string& urlFileName,std::vector<UnitTestUrl>& testUrls);

	static void OnError(const std::string& message, const UnitTestUrl& errorUrl);
};

}

