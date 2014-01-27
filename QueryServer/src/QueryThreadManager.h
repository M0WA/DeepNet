/**
 *
 * @file QueryThreadManager.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include <vector>

#include "QueryThread.h"

#include <DatabaseHelper.h>
#include <ThreadManager.h>

namespace database {
	class DatabaseConfig;
	class DatabaseConnection;
}

namespace queryserver {

	/**
	 * this variable is used internally by queryserver::QueryThreadManager
	 */
	static const size_t QUERY_THREAD_MANAGER_DB_HELPERS_SIZE(5);

	class Query;
	class QueryThreadResultEntry;
	class DictionaryInfoThread;

/**
 * @brief manages several information gathering threads for a single queryserver::Query at a time
 */
class QueryThreadManager : private threading::ThreadManager<queryserver::QueryThread> {
public:
	/**
	 * creates query thread manager from a database config and
	 * establishes all needed database connections.
	 * @param dbConfig database config
	 */
	QueryThreadManager(const database::DatabaseConfig* dbConfig);

	virtual ~QueryThreadManager();

public:
	/**
	 * adds a single query and start processing it.
	 * call ReleaseQuery when finished with this query.
	 * @see queryserver::QueryThreadManager::ReleaseQuery
	 * @param query query to process
	 */
	void BeginQuery(const Query& query);

	/**
	 * waits for all querying threads to end and gives results.
	 * results are available till the current query is released
	 * @see queryserver::QueryThreadManager::ReleaseQuery
	 * @param results results of current query
	 */
	void WaitForResults(std::vector<const QueryThreadResultEntry*>& results);

	/**
	 * releases all resources allocated with current query (including
	 * results)
	 */
	void ReleaseQuery();

private:
	template <class threadT, class paramT>
	void AddQueryTyped(database::DatabaseConnection* dbConn,const Query& query)	{
		queryThreadIDs.push_back(
			AddThread(
				new threadT(),
				new paramT(dbConn, query))
		);
	}

	template <class threadT, class paramT, class extraT>
	void AddQueryTyped(database::DatabaseConnection* dbConn,const Query& query, extraT extra) {
		queryThreadIDs.push_back(
			AddThread(
				new threadT(),
				new paramT(dbConn, query, extra))
		);
	}

private:
	std::vector<threading::Thread::ThreadID> queryThreadIDs;
	bool releaseSeen;
	database::DatabaseHelper dbHelpers[QUERY_THREAD_MANAGER_DB_HELPERS_SIZE];
	DictionaryInfoThread* dictionary;
};

}

