/**
 * @file CacheSecondLevelDomain.h
 * @author Moritz Wagner
 * @date 19.05.2012
 */

#pragma once

#include <map>
#include <vector>
#include <string>

#include "Cache.h"

namespace database {
	class DatabaseConnection;
}

namespace caching {

/**
 * @brief cache for secondlevel domains.
 */
class CacheSecondLevelDomain {
private:
	CacheSecondLevelDomain(size_t limit = 0);
public:
	virtual ~CacheSecondLevelDomain();

public:
	/**
	 * gets secondlevel domain id by string.
	 * this function may add secondlevel domains to database.
	 * @param connection database connection.
	 * @param secondleveldomain secondlevel domain.
	 * @param secondleveldomainID gets filled with corresponding secondlevel domain id.
	 */
	static void GetSecondLevelIDByDomain(
		database::DatabaseConnection* connection,
		const std::string& secondleveldomain,
		long long& secondleveldomainID);

	/**
	 * gets secondlevel domain by it's id.
	 * @param connection database connection.
	 * @param secondleveldomainID secondlevel domain id.
	 * @param secondleveldomain gets filled with corresponding secondlevel domain.
	 */
	static void GetDomainBySecondLevelID(
		database::DatabaseConnection* connection,
		const long long& secondleveldomainID,
		std::string& secondleveldomain);

	/**
	 * removes all items from cache.
	 */
	static void Clear(void);

	/**
	 * set current limit of cache.
	 * @param capacity maximum number of entries in cache.
	 */
	static void SetCapacity(const size_t capacity);

	/**
	 * gets current number of entries in cache.
	 * @return current number of entries in cache.
	 */
	static size_t GetSize() { return cacheInstance.idSecondLevelDomain.GetSize(); }

	/**
	 * get current match count of cache, clearing internal match counter.
	 * @return number of matches.
	 */
	static size_t GetMatches() { return cacheInstance.idSecondLevelDomain.GetMatches(); }

	/**
	 * get current miss count of cache, clearing internal miss counter.
	 * @return number of misses.
	 */
	static size_t GetMisses() { return cacheInstance.idSecondLevelDomain.GetMisses(); }

private:
	static CacheSecondLevelDomain cacheInstance;

private:
	Cache<long long,std::string> idSecondLevelDomain;
};

} /* namespace caching */
