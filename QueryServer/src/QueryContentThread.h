/**
 *
 * @file QueryContentThread.h
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#pragma once

#include "QueryThread.h"

#include <vector>
#include <string>
#include <map>

#include <DatabaseHelper.h>
#include <SelectResultContainer.h>


namespace database {
	class TableBase;
}

namespace queryserver {

	class Query;

/**
 * @brief queries for search results matching in the content of a webpage
 */
class QueryContentThread : public queryserver::QueryThread {
public:
	QueryContentThread();
	virtual ~QueryContentThread();

private:
	virtual void OnInitThreadInstance();
	virtual void OnDestroyThreadInstance();
	virtual void* OnRun();
	virtual const char* GetThreadName() const { return "QueryContentThread"; }

private:
	bool GetIDsForKeywords();
	bool GetIDsForCaseInsensitiveKeywords();
	bool GetUrlsForKeywords();
	bool ProcessResults(database::SelectResultContainer<database::TableBase>& results);

private:
	std::map<long long,size_t> dictIDPosition;

	std::vector<long long> dictIDs;
	std::vector< std::vector<long long> > caseInsensitiveDictIDs;
};

}
