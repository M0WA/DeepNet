/**
 *
 * @file QueryDictionaryThread.h
 * @author Moritz Wagner
 * @date 14.08.2013
 *
 */

#pragma once

#include <map>

#include "QueryThread.h"

namespace queryserver {

/**
 * @brief base class for QueryThread that base their results on keywords located in the "dict" table
 */
class QueryDictionaryThread: public queryserver::QueryThread {
public:
	QueryDictionaryThread();
	virtual ~QueryDictionaryThread();

protected:
	virtual void OnInitThreadInstance();
	virtual void OnDestroyThreadInstance();
	virtual void* OnRun();

private:
	bool GetIDsForKeywords();
	bool GetIDsForCaseInsensitiveKeywords();

protected:
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
};

}

