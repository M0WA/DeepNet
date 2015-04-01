/**
 * @file CacheSubdomain.h
 * @author Moritz Wagner
 * @date 19.05.2012
 */

#pragma once

#include <string>
#include <map>

#include "Cache.h"

namespace database {
	class DatabaseConnection;
}

namespace caching {

class CacheUrl;

/**
 * @brief cache for subdomains.
 */
class CacheSubdomain {

private:
	CacheSubdomain(size_t limit = 0);
public:
	virtual ~CacheSubdomain();

public:
	/**
	 * gets subdomain id by string.
	 * @param db database connection.
	 * @param subdomain subdomain to look for.
	 * @param subdomainID gets filled with corresponding subdomain id.
	 */
	static void GetSubdomainIDByDomain(
		database::DatabaseConnection* db,
		const std::string& subdomain,
		long long& subdomainID);

	/**
	 * gets subdomain string by subdomain id.
	 * @param db database connection.
	 * @param subdomainID subdomain id to look for.
	 * @param subdomain gets filled with corresponding subdomain.
	 */
	static void GetDomainBySubdomainID(
		database::DatabaseConnection* db,
		const long long& subdomainID,
		std::string& subdomain);

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
	static size_t GetSize() { return cacheInstance.idSubdomain.GetSize(); }

	/**
	 * get current match count of cache, clearing internal match counter.
	 * @return number of matches.
	 */
	static size_t GetMatches() { return cacheInstance.idSubdomain.GetMatches(); }

	/**
	 * get current miss count of cache, clearing internal miss counter.
	 * @return number of misses.
	 */
	static size_t GetMisses() { return cacheInstance.idSubdomain.GetMisses(); }

private:
	static CacheSubdomain cacheInstance;

private:
	Cache<long long,std::string> idSubdomain;
};

}
