/**
 *
 * @file CacheUrlSearchPart.h
 * @author Moritz Wagner
 * @date 06.08.2013
 *
 */

#pragma once

#include <string>

#include "Cache.h"

namespace database {
	class DatabaseConnection;
}

namespace caching {

class CacheUrlSearchPart {
public:
	CacheUrlSearchPart(size_t limit = 0);
	virtual ~CacheUrlSearchPart();

public:
	/**
	 * gets search part of an url by it's urlSearchPartID ID
	 * @param db database connection
	 * @param urlSearchPartID urlSearchPartID
	 * @param searchPart search part for given urlSearchPartID
	 */
	static void GetUrlSearchPartByID(
		database::DatabaseConnection* db,
		const long long& urlSearchPartID,
		std::string& searchPart);

	/**
	 * gets urlSearchPartID of an url by it's search part
	 * @param db database connection
	 * @param urlSearchPart url search part to search for
	 * @param urlSearchPartID urlSearchPartID for given search part
	 */
	static void GetIDByUrlSearchPart(
		database::DatabaseConnection* db,
		const std::string& urlSearchPart,
		long long& urlSearchPartID);

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
		return cacheInstance.idUrlSearchPart.GetSize(); }

	/**
	 * get current match count of cache, clearing internal match counter.
	 * @return number of matches.
	 */
	static size_t GetMatches() {
		return cacheInstance.idUrlSearchPart.GetMatches(); }

	/**
	 * get current miss count of cache, clearing internal miss counter.
	 * @return number of misses.
	 */
	static size_t GetMisses() {
		return cacheInstance.idUrlSearchPart.GetMisses(); }

private:
	static CacheUrlSearchPart cacheInstance;

private:
	Cache<long long,std::string> idUrlSearchPart;
};

}
