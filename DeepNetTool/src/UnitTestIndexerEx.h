/**
 *
 * @file UnitTestIndexerEx.h
 * @author Moritz Wagner
 * @date Jun 15, 2013
 *
 */

#pragma once

#include "UnitTest.h"

#include <vector>
#include <string>

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

class UnitTestIndexerEx: public toolbot::UnitTest {
public:
	UnitTestIndexerEx(database::DatabaseConnection* connection, const std::string& testPath);
	virtual ~UnitTestIndexerEx();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestIndexerEx"; }

private:
	database::DatabaseConnection* connection;
	std::string testPath;
	std::vector<std::string> contentFiles;
};

}
