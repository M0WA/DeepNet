/**
 * @file QueryProcessThread.h
 * @author Moritz Wagner
 * @date Apr 8, 2015
 */

#pragma once

#include "QueryThreadManager.h"
#include "QueryXmlResponseResultEntry.h"
#include "Query.h"

#include <Thread.h>

#include <string>
#include <vector>

namespace database {
	class DatabaseConnection;
}

namespace queryserver {

/**
 * @brief background threads that executes a single query and writes its results to the database
 */
class QueryProcessThread : public threading::Thread {
public:
	QueryProcessThread(
		const database::DatabaseConfig* dbConfig,
		const long long& queryId,
		const Query& query,
		const std::string& sessionID,
		const std::string& rawQueryString);

	virtual ~QueryProcessThread();

private:
	static void* QueryProcessThreadFunction(threading::Thread::THREAD_PARAM* param);

private:
	bool RunQuery(database::DatabaseConnection* db);

	void MergeDuplicateURLs(
		std::vector<QueryXmlResponseResultEntry>& responseEntries);

	void MergeDuplicateSecondLevel(
		database::DatabaseConnection* db,
		std::vector<QueryXmlResponseResultEntry>& responseEntries);

	void SortResults(
		std::vector<QueryXmlResponseResultEntry>& responseEntries);

	bool SetQueryFinished(
		database::DatabaseConnection* db,
		const long long& resultCount);

	void InsertResults(
		database::DatabaseConnection* db,
		const std::vector<QueryXmlResponseResultEntry>& responseEntries);

private:
	const database::DatabaseConfig* dbConfig;
	long long queryId;
	Query query;
	std::string sessionID;
	std::string rawQueryString;
	QueryThreadManager queryManager;
};

}
