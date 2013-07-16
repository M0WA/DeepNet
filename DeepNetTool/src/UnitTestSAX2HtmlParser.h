/**
 *
 * @file UnitTestSAX2HtmlParser.h
 * @author Moritz Wagner
 * @date 20.04.2013
 *
 */

#pragma once

#include <string>
#include <vector>

#include "UnitTest.h"

namespace htmlparser {
	class DatabaseUrl;
}

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

/**
 * @brief implements unit tests for libXML2 based html parser
 * @see htmlparser::HtmlParserFactory
 */
class UnitTestSAX2HtmlParser: public toolbot::UnitTest {
public:
	UnitTestSAX2HtmlParser(database::DatabaseConnection* db, const std::string& unitBaseDir);
	virtual ~UnitTestSAX2HtmlParser();

	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestSAX2HtmlParser"; }

private:
	bool Test(const htmlparser::DatabaseUrl& baseUrl);

private:
	database::DatabaseConnection* db;
	std::string unitBaseDir;
	std::vector<std::string> contentFiles;
};

}
