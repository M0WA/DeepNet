/**
 *
 * @file UnitTestCacheUrlPathPart.h
 * @author Moritz Wagner
 * @date 04.08.2013
 *
 */

#pragma once

#include "UnitTest.h"

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

class UnitTestCacheUrlPathPart: public toolbot::UnitTest {
public:
	UnitTestCacheUrlPathPart(database::DatabaseConnection* connection,const std::string& urlPathPartValidateFile);
	virtual ~UnitTestCacheUrlPathPart();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestCacheUrlPathPart"; }

private:
	database::DatabaseConnection* connection;
	std::string urlPathPartValidateFile;
};

}
