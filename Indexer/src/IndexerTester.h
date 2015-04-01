/*
 * IndexerTester.h
 *
 *  Created on: 22.04.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

namespace database
{
	class DatabaseConnection;
}

namespace indexing {

class IndexerTester {
private:
	IndexerTester();
public:
	virtual ~IndexerTester();

	static bool Parse(database::DatabaseConnection* database, const std::string& content);
};

}
