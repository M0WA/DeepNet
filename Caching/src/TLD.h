/**
 * @file TLD.h
 * @author Moritz Wagner
 * @date 25.03.2012
 */

#pragma once

#include <string>
#include <map>
#include <vector>
#include <Mutex.h>

namespace database {
	class DatabaseConnection;
}

namespace caching {

/**
 * @brief class containing all top level domains available
 */
class TLD
{
public:
	/**
	 * initializes top level domain cache, this function should be called once per runtime
	 * @param db database connection
	 * @return true if successful, false if unsuccessful
	 */
	static bool InitTLDCache(database::DatabaseConnection* db);

	/**
	 * gets a top level domain by it's id
	 * @param tldID id of the toplevel domain
	 * @return top level domain as string
	 */
	static const std::string GetTLDByID(const long long tldID);

	/**
	 * gets a top level domain by it's name
	 * @param tld top level domain string
	 * @return top level domain id
	 */
	static const long long   GetTLDIDByTLD(const std::string& tld);

	/**
	 * gets a vector filled with all available top level domains
	 * @param tlds available top level domains
	 */
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
