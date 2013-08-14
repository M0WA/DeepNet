/**
 *
 * @file QueryContentThread.h
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#pragma once

#include "QueryDictionaryThread.h"

#include <SelectResultContainer.h>

namespace database {
	class TableBase;
}

namespace queryserver {

	class Query;

/**
 * @brief queries for search results matching in the content of a webpage
 */
class QueryContentThread : public queryserver::QueryDictionaryThread {
public:
	QueryContentThread();
	virtual ~QueryContentThread();

private:
	virtual void* OnRun();
	virtual const char* GetThreadName() const { return "QueryContentThread"; }

private:
	bool GetUrlsForKeywords(database::SelectResultContainer<database::TableBase>& results);
	bool ProcessResults(database::SelectResultContainer<database::TableBase>& results);
};

}
