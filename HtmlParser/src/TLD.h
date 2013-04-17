/*
 * TLD.h
 *
 *  Created on: 25.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <map>
#include <vector>
#include <Mutex.h>

namespace database {
	class DatabaseConnection;
}

namespace htmlparser {

class TLD
{
public:
	static bool InitTLDCache(database::DatabaseConnection* db);

	static const std::string GetTLDByID(const long long tldID);
	static const long long   GetTLDIDByTLD(const std::string& tld);
	static void GetTLDStrings(std::vector<std::string>& tlds);

private:
	bool Init(database::DatabaseConnection* db);

private:
	static TLD tld;

	static std::map<long long, std::string> mapIdTld;
	static std::map<std::string, long long> mapTldId;

	static threading::Mutex initMutex;
	static bool isInitialized;
};

}
