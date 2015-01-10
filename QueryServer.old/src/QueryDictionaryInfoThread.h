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
	class DatabaseConfig;
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
	 * @brief parameters for a queryserver::QueryDictionaryInfoThread
	 */
	typedef struct _QueryDictionaryInfoThreadParam {

		/**
		 * constructs QueryDictionaryInfoThreadParam
		 * @param query query to be processed
		 * @param dbconf database config
		 */
		_QueryDictionaryInfoThreadParam(Query& query,const database::DatabaseConfig *dbconf);

		/**
		 * query to be processed
		 */
		Query& query;

		/**
		 * database config
		 */
		const database::DatabaseConfig *dbconf;
	} QueryDictionaryInfoThreadParam;

public:
	QueryDictionaryInfoThread();
	virtual ~QueryDictionaryInfoThread();

private:
	static void* QueryDictionaryInfoThreadFunction(threading::Thread::THREAD_PARAM* threadParam);
};

}

