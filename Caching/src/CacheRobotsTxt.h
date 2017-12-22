/**
 * @file CacheRobotsTxt.h
 * @author Moritz Wagner
 * @date 04.12.2012
 */

#pragma once

#include "Cache.h"
#include "CacheRobotsEntry.h"
#include "RobotTxt.h"

namespace database {
	class DatabaseConnection;
}

namespace htmlparser {
	class DatabaseUrl;
}

namespace caching {

/**
 * @brief cache for robot.txt's.
 */
class CacheRobotsTxt {
private:
	CacheRobotsTxt(size_t limit = 0);
public:
	virtual ~CacheRobotsTxt();

public:
	/**
	 * checks if given url is valid for given useragent.
	 * @param db database connection.
	 * @param url url to check.
	 * @param useragent useragent string to check for.
	 * @return false if not allow, true if allowed.
	 */
	static bool IsUrlAllowed(
			database::DatabaseConnection* db,
			const DatabaseUrl& url,
			const std::string& useragent);

	/**
	 * set current limit of cache.
	 * @param capacity maximum number of entries in cache.
	 */
	static void SetCapacity(const size_t capacity) { cacheInstance.cacheRobotsTxts.SetLimit(capacity); };

	/**
	 * gets current number of entries in cache.
	 * @return current number of entries in cache.
	 */
	static size_t GetSize() { return cacheInstance.cacheRobotsTxts.GetSize(); }

	/**
	 * get current match count of cache, clearing internal match counter.
	 * @return number of matches.
	 */
	static size_t GetMatches() { return cacheInstance.cacheRobotsTxts.GetMatches(); }

	/**
	 * get current miss count of cache, clearing internal miss counter.
	 * @return number of misses.
	 */
	static size_t GetMisses() { return cacheInstance.cacheRobotsTxts.GetMisses(); }

private:
	static bool LoadRobotsFromDatabase(database::DatabaseConnection* db,const CacheRobotsEntry& entry, RobotTxt& robot);
	static bool DownloadRobotsTxt(database::DatabaseConnection* db,const DatabaseUrl& url, RobotTxt& robot);

private:
	static CacheRobotsTxt cacheInstance;

private:
	Cache<CacheRobotsEntry,RobotTxt> cacheRobotsTxts;
	bool saveRobotsTxt;
};

}
