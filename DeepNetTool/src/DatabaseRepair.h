/*
 * DatabaseRepair.h
 *
 *  Created on: 03.12.2012
 *      Author: Moritz Wagner
 */

#pragma once

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

class DatabaseRepair {
private:
	DatabaseRepair();
public:
	virtual ~DatabaseRepair();

public:
	static bool FixUncleanShutdown(database::DatabaseConnection* db);

private:
	static bool FixSyncUrlTable(database::DatabaseConnection* db);
	static bool FixSecondLevelLockTable(database::DatabaseConnection* db);
	static bool FixCrawlerSessionTable(database::DatabaseConnection* db);
};

}

