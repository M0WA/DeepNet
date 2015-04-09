/**
 * @file QueryProcessManager.h
 * @author Moritz Wagner
 * @date Apr 8, 2015
 */

#pragma once

#include "QueryProcessThread.h"
#include "QueryProcessManagerCleanupThread.h"

#include <Mutex.h>

#include <map>

namespace database {
	class DatabaseConfig;
}

namespace queryserver {

class Query;

/**
 * @brief manages execution of multiple queries (QueryProcessThread) simultaniously
 */
class QueryProcessManager {
public:
	QueryProcessManager();
	virtual ~QueryProcessManager();

	friend class QueryProcessManagerCleanupThread;

public:
	/**
	 * adds a query to be executed
	 * @param dbConfig database config
	 * @param queryId query id
	 * @param query Query objects
	 * @param sessionId session id
	 * @param rawQueryString raw query string
	 */
	void AddQuery(
		const database::DatabaseConfig* dbConfig,
		const long long& queryId,
		const Query& query,
		const std::string& sessionID,
		const std::string& rawQueryString);

private:
	std::map<long long,QueryProcessThread*> threads;
	threading::Mutex lockThreads;
	QueryProcessManagerCleanupThread cleanupThread;
};

}
