/**
 *
 * @file DictionaryInfoThread.h
 * @author Moritz Wagner
 * @date 27.08.2013
 *
 */

#pragma once

#include <vector>
#include <map>
#include <string>

#include <Thread.h>

#include "KeywordDictionary.h"

namespace database {
	class DatabaseConnection;
	class WhereConditionTableColumnCreateParam;
}

namespace queryserver {

	class Query;

/**
 * @brief helper class for queryserver::QueryThread classes that need infos from the dictionary
 */
class DictionaryInfoThread: public threading::Thread {

public:
	/**
	 * create from database connection and associated query
	 * @param dbConn database connection
	 * @param query query
	 */
	DictionaryInfoThread(database::DatabaseConnection* dbConn,const Query& query);
	virtual ~DictionaryInfoThread();

public:
	/**
	 * gets keyword dictionary for this query
	 * @return keyword dictionary
	 */
	const KeywordDictionary& GetDictionary(void) const { return dictionary; }

private:
	static void* DictionaryInfoThreadFunction(threading::Thread::THREAD_PARAM* threadParam);

private:
	database::DatabaseConnection* dbConn;
	const Query& query;
	KeywordDictionary dictionary;
};

}

