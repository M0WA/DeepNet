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
	UnitTestIndexerEx(database::DatabaseConnection* connection, const std::vector<std::string>& contents);
	virtual ~UnitTestIndexerEx();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestIndexerEx"; }

private:
	database::DatabaseConnection* connection;
	std::vector<std::string> contentFiles;
};

}
