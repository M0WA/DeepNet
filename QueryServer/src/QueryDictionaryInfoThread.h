/**
 *
 * @file QueryDictionaryInfoThread.h
 * @author Moritz Wagner
 * @date 02.02.2014
 *
 */

#pragma once

#include <string>
#include <vector>

#include <Thread.h>

namespace database {
	class DatabaseConnection;
	class WhereConditionTableColumnCreateParam;
}

namespace queryserver {

class Query;
class QueryKeywordGroup;

/**
 * @brief this class collects and prepares information about keywords and their groups
 * @see queryserver::QueryKeyword queryserver::QueryKeywordGroup
 */
class QueryDictionaryInfoThread : public threading::Thread {

public:
	/**
	 * @brief paramaters for a queryserver::QueryDictionaryInfoThread
	 */
	typedef struct _QueryDictionaryInfoThreadParam {

		/**
		 * constructs QueryDictionaryInfoThreadParam
		 * @param query query to be processed
		 * @param db database connection
		 */
		_QueryDictionaryInfoThreadParam(Query& query,database::DatabaseConnection *db);

		/**
		 * query to be processed
		 */
		Query& query;

		/**
		 * database connection
		 */
		database::DatabaseConnection *db;
	} QueryDictionaryInfoThreadParam;

public:
	QueryDictionaryInfoThread();
	virtual ~QueryDictionaryInfoThread();

private:
	static void* QueryDictionaryInfoThreadFunction(threading::Thread::THREAD_PARAM* threadParam);
};

}

