/**
 *
 * @file DatabaseRepair.h
 * @author Moritz Wagner
 * @date 02.07.2013
 *
 */

#pragma once

#include <vector>

namespace database {
	class DatabaseConnection;
}

namespace bot {

/**
 * @brief class for database consistency checks and fixing them if possible
 */
class DatabaseRepair {
private:
	DatabaseRepair();
public:
	virtual ~DatabaseRepair();

public:
	/**
	 * validates all sync tables and checks for inconsistencies
	 * @param db database connection
	 * @param oldCrawlerSessionIDs list of crawler sessions to check for consistency (empty list assumes that no instances use the database at the time of the call)
	 * @return true if database is consistent, false if inconsistent
	 */
	static bool ValidateSyncTables(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs = std::vector<long long>());

	/**
	 * validates and fixes all sync tables and checks for inconsistencies
	 * @param db database connection
	 * @param oldCrawlerSessionIDs list of crawler sessions to check for consistency (empty list assumes that no instances use the database at the time of the call)
	 * @return true if database is consistent, false if inconsistent
	 */
	static bool FixUncleanShutdown(database::DatabaseConnection* db, const bool validateBeforeFix = true, const std::vector<long long>& oldCrawlerSessionIDs = std::vector<long long>());

private:
	static bool ValidateSyncUrlTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs);
	static bool ValidateSecondLevelLockTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs);
	static bool ValidateCrawlerSessionTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs);

	static bool FixSyncUrlTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs);
	static bool FixSecondLevelLockTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs);
	static bool FixCrawlerSessionTable(database::DatabaseConnection* db, const std::vector<long long>& oldCrawlerSessionIDs);
};

}
