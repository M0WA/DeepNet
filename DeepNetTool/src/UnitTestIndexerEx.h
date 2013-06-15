/**
 *
 * @file UnitTestIndexerEx.h
 * @author Moritz Wagner
 * @date 15.06.2013
 *
 */

#pragma once

#include "UnitTest.h"

#include <vector>
#include <string>

namespace database {
	class DatabaseConnection;
}

namespace tools {
	class SpellChecking;
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
	bool HandleSingleFile(tools::SpellChecking& spellCheck,const std::string& fileName);

private:
	database::DatabaseConnection* connection;
	std::string testPath;
	std::vector<std::string> contentFiles;
};

}
