/*
 * UrlInserter.h
 *
 *  Created on: 20.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <vector>
#include <map>

namespace database {
	class DatabaseConnection;
}

namespace caching {
	class DatabaseUrl;
}

namespace htmlparser {

class UrlInserter {
private:
	UrlInserter();
public:
	virtual ~UrlInserter();

public:
	static int ReadURLFile(const std::string& fileName, std::multimap<std::string,std::string>& fileContent);

	static bool InsertURLFile(database::DatabaseConnection* db,const std::multimap<std::string,std::string>& fileContent);
	static bool ValidateURLFile(database::DatabaseConnection* db,const std::multimap<std::string,std::string>& fileContent);

	static caching::DatabaseUrl ValidateURL(database::DatabaseConnection* db,const std::string& sDomain, const std::string& sUrl, bool dumpUrl = true);
	static bool InsertURL(database::DatabaseConnection* db,const std::string& sDomain, const std::string& sUrl);
};

}
