/**
 * @file QueryResultCleanupThread.h
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#pragma once

#include <vector>
#include <Thread.h>

namespace database {
	class DatabaseConfig;
	class DatabaseConnection;
}

namespace queryserver {

/**
 * @brief thread to clean up expired search results from database
 */
class QueryResultCleanupThread : public threading::Thread {
public:
	/**
	 * constructs cleanup thread
	 * @param databaseConfig database config
	 * @param requery_after max age of search queries
	 */
	QueryResultCleanupThread(database::DatabaseConfig* databaseConfig,unsigned long long requery_after);
	virtual ~QueryResultCleanupThread();

private:
	unsigned long long Cleanup();

	void GetExpiredQueries(database::DatabaseConnection* db, std::vector<long long>& ids);
	void InvalidateQueries(database::DatabaseConnection* db,const std::vector<long long>& ids);
	void DeleteResults(database::DatabaseConnection* db,const std::vector<long long>& ids);
	void DeleteQueries(database::DatabaseConnection* db,const std::vector<long long>& ids);

private:
	static void* QueryResultCleanupThreadFunc(threading::Thread::THREAD_PARAM* param);

private:
	database::DatabaseConfig* databaseConfig;
	unsigned long long requery_after;
};

}
