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
	static void* QueryContentThreadFunction(threading::Thread::THREAD_PARAM* threadParam);

private:
	virtual bool OnInitThreadInstance();
	virtual bool OnDestroyThreadInstance();
	virtual void* Run();
	virtual const char* GetThreadName() const { return "QueryContentThread"; }

private:
	bool GetIDsForKeywords();
	bool GetIDsForCaseInsensitiveKeywords();
	bool GetUrlsForKeywords();
	bool ProcessResults(database::SelectResultContainer<database::TableBase>& results);

private:
	std::vector<long long> keywordIDs;
	std::vector< std::vector<long long> > caseInsensitiveKeywordIDs;
	std::vector<std::string> lowerKeywords;
};

}
