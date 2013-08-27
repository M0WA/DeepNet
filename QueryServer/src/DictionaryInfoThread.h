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

#include <Thread.h>

namespace database {
	class DatabaseConnection;
}

namespace queryserver {

	class Query;

class DictionaryInfoThread: public threading::Thread {
public:
	DictionaryInfoThread(database::DatabaseConnection* dbConn,const Query& query);
	virtual ~DictionaryInfoThread();

private:
	bool GetIDsForKeywords();
	bool GetIDsForCaseInsensitiveKeywords();
	bool GetIDsForSimilarKeywords();

private:
	database::DatabaseConnection* dbConn;
	const Query& query;

public:
	/**
	 * maps DICT_ID and position of the keyword in the Query
	 */
	std::map<long long,size_t> dictIDPosition;

	/**
	 * contains all exact matches
	 */
	std::vector<long long> dictIDs;

	/**
	 * contains all case insensitve matches except the exact matches
	 */
	std::vector< std::vector<long long> > caseInsensitiveDictIDs;

	/**
	 * contains all similar matches except above
	 */
	std::vector<long long> similarDictIDs;

private:
	static void* DictionaryInfoThreadFunction(threading::Thread::THREAD_PARAM* threadParam);
};

}

