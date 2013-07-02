/**
 *
 * @file DatabaseRepair.h
 * @author Moritz Wagner
 * @date 02.07.2013
 *
 */

#pragma once

namespace database {
	class DatabaseConnection;
}

namespace bot {

class DatabaseRepair {
private:
	DatabaseRepair();
public:
	virtual ~DatabaseRepair();

public:
	static bool ValidateSyncTables(database::DatabaseConnection* db);
	static bool FixUncleanShutdown(database::DatabaseConnection* db);

private:
	static bool ValidateSyncUrlTable(database::DatabaseConnection* db);
	static bool ValidateSecondLevelLockTable(database::DatabaseConnection* db);
	static bool ValidateCrawlerSessionTable(database::DatabaseConnection* db);

	static bool FixSyncUrlTable(database::DatabaseConnection* db);
	static bool FixSecondLevelLockTable(database::DatabaseConnection* db);
	static bool FixCrawlerSessionTable(database::DatabaseConnection* db);
};

}
