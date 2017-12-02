/*
 * @file Sync.h
 * @date Dec 2, 2017
 * @author Moritz Wagner
 */

#pragma once

namespace database {
	class DatabaseConnection;
}

namespace syncing {

/**
 * @brief class containing commonly used syncing functionality
 */
class Sync {
public:
	Sync();
	virtual ~Sync();

public:
	/**
	 * locks a secondlevel domain
	 * @param db database connection
	 * @param crawlerID crawler ID
	 * @param sld secondlevel domain to lock( use -1 to use random domain, will be set to selected domain if successful )
	 * @return true if successful, false if errors
	 */
	static bool LockSecondLevelDomain(database::DatabaseConnection* db, const long long& crawlerID, long long& sld);

	/**
	 * unlocks crawler session (and connected resources)
	 * @param db database connection
	 * @param crawlerID crawler ID
	 * @param sld secondlevel domain to lock( use -1 to unlock all )
	 * @return true if successful, false if errors
	 */
	static bool UnlockSecondLevelDomain(database::DatabaseConnection* db, const long long& crawlerID, const long long& sld);

	/**
	 * get reschedule interval in days
	 * @return schedule interval in days
	 */
	static long long GetRescheduleInterval();
};

}
