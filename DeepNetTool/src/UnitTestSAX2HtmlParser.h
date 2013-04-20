/**
 *
 * @file UnitTestSAX2HtmlParser.h
 * @author Moritz Wagner
 * @date Apr 20, 2013
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

class UnitTestSAX2HtmlParser: public toolbot::UnitTest {
public:
	UnitTestSAX2HtmlParser(database::DatabaseConnection* db, const std::string& unitBaseDir,const std::vector<std::string>& htmlFilenames);
	virtual ~UnitTestSAX2HtmlParser();

	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestSAX2HtmlParser"; }

private:
	bool Test(const htmlparser::DatabaseUrl& baseUrl);

private:
	database::DatabaseConnection* db;
	std::string unitBaseDir;
	std::vector<std::string> htmlFilenames;
};

}
