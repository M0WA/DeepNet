/**
 *
 * @file UnitTestDatabase.h
 * @author Moritz Wagner
 * @date 15.07.2013
 *
 */

#pragma once

#include "UnitTest.h"

#include <DatabaseHelper.h>

namespace database {
	class DatabaseConfig;
	class DatabaseConnection;
}

namespace toolbot {

class UnitTestDatabase: public toolbot::UnitTest {
public:
	UnitTestDatabase(const database::DatabaseConfig* dbConfig);
	virtual ~UnitTestDatabase();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestDatabase"; }

private:
	bool InsertTest();
	bool UpdateTest();
	bool DeleteTest();
	bool SelectTest();

private:
	const database::DatabaseConfig* dbConfig;
	database::DatabaseHelper dbHelper;
};

}
