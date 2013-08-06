/**
 *
 * @file CacheUrlPathPart.h
 * @author Moritz Wagner
 * @date 03.08.2013
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
 * @brief Cache for urlpathpart table entries
 */
class CacheUrlPathPart {
private:
	CacheUrlPathPart(size_t limit = 0);
public:
	virtual ~CacheUrlPathPart();

public:
	/**
	 * gets path part of an url by it's urlpathpart ID
	 * @param db database connection
	 * @param urlPathPartID urlPathPartID
	 * @param pathPart path part for given urlPathPartID
	 */
	static void GetUrlPathPartByID(
		database::DatabaseConnection* db,
		const long long& urlPathPartID,
		std::string& pathPart);

	/**
	 * gets urlPathPartID of an url by it's path part
	 * @param db database connection
	 * @param urlPathPart url path part to search for
	 * @param urlPathPartID urlPathPartID for given path part
	 */
	static void GetIDByUrlPathPart(
		database::DatabaseConnection* db,
		const std::string& urlPathPart,
		long long& urlPathPartID);

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
	static size_t GetSize() {
		return cacheInstance.idUrlPathPart.GetSize(); }

	/**
	 * get current match count of cache, clearing internal match counter.
	 * @return number of matches.
	 */
	static size_t GetMatches() {
		return cacheInstance.idUrlPathPart.GetMatches(); }

	/**
	 * get current miss count of cache, clearing internal miss counter.
	 * @return number of misses.
	 */
	static size_t GetMisses() {
		return cacheInstance.idUrlPathPart.GetMisses(); }

private:
	static void InsertUrlPathPart(
		database::DatabaseConnection* db,
		std::vector<long long>& pathPartIDs,
		long long& urlPathPartID);

private:
	static CacheUrlPathPart cacheInstance;

private:
	Cache<long long,std::string> idUrlPathPart;
};

}
