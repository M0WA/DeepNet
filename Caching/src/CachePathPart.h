/**
 *
 * @file CachePathPart.h
 * @author Moritz Wagner
 * @date 05.08.2013
 *
 */

#pragma once

#include <string>

#include "Cache.h"

namespace database {
	class DatabaseConnection;
}

namespace caching {

/**
 * @brief Cache for pathpart table entries
 * @see caching::CacheUrlPathPart
 */
class CachePathPart {
private:
	CachePathPart(size_t limit = 0);
public:
	virtual ~CachePathPart();

public:
	/**
	 * removes all items from cache.
	 */
	static void Clear(void);

	/**
	 * gets an ID for a path part
	 * @param db database connection
	 * @param pathPart path part to query for
	 * @return path part ID or -1
	 */
	static long long GetIDByPathPart(database::DatabaseConnection* db,const std::string& pathPart);

	/**
	 * gets path part for an id
	 * @param db database connection
	 * @param pathPartID pathpart ID to query for
	 * @return path part or empty string
	 */
	static std::string GetPathPartByID(database::DatabaseConnection* db, const long long pathPartID);

	/**
	 * set current limit of cache.
	 * @param capacity maximum number of entries in cache.
	 */
	static void SetCapacity(const size_t capacity);

	/**
	 * gets current number of entries in cache.
	 * @return current number of entries in cache.
	 */
	static size_t GetSize() { return cacheInstance.idPathPart.GetSize(); }

	/**
	 * get current match count of cache, clearing internal match counter.
	 * @return number of matches.
	 */
	static size_t GetMatches() { return cacheInstance.idPathPart.GetMatches(); }

	/**
	 * get current miss count of cache, clearing internal miss counter.
	 * @return number of misses.
	 */
	static size_t GetMisses() { return cacheInstance.idPathPart.GetMisses(); }

private:
	static CachePathPart cacheInstance;

private:
	Cache<long long,std::string> idPathPart;
};

}
