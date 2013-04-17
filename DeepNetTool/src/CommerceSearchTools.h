/*
 * CommerceSearchTools.h
 *
 *  Created on: 30.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

namespace database
{
	class DatabaseConnection;
}

namespace toolbot {

class CommerceSearchTools {
private:
	CommerceSearchTools();

public:
	virtual ~CommerceSearchTools();

public:
	static bool AddCustomer(database::DatabaseConnection* db,const std::string& username, const std::string& password, const std::string& domain, const long long revisitInterval);
};

}

