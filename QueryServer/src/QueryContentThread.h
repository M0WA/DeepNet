/**
 *
 * @file QueryContentThread.h
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#pragma once

#include <vector>
#include <string>

#include <Thread.h>
#include <DatabaseHelper.h>
#include <SelectResultContainer.h>

#include "Query.h"

namespace database {
	class TableBase;
}

namespace queryserver {

/**
 * @brief queries content for matching search results
 */
class QueryContentThread : public threading::Thread {
public:
	typedef struct _QueryContentThreadParam {
		_QueryContentThreadParam(const database::DatabaseConfig* config, const Query& query)
		: config(config)
		, query(query) {}

		const database::DatabaseConfig* config;
		Query query;
	} QueryContentThreadParam;

	typedef struct _QueryContentResultEntry {

		_QueryContentResultEntry(const long long& urlID, const long long& urlStageID)
		: urlID(urlID)
		, urlStageID(urlStageID)
		{}

		long long urlID;
		long long urlStageID;
	} QueryContentResultEntry;

public:
	QueryContentThread();
	virtual ~QueryContentThread();

public:
	/**
	 * returns results of quering by the contents of webpages.
	 * use only when thread has ended.
	 * @return results
	 */
	const std::vector<QueryContentThread::QueryContentResultEntry>& GetResults() const {
		return resultEntries; }

private:
	static void* QueryContentThreadFunction(threading::Thread::THREAD_PARAM* threadParam);

private:
	bool InitThreadInstance();
	bool DestroyThreadInstance();
	bool GetIDsForKeywords();
	bool GetIDsForCaseInsensitiveKeywords();
	bool GetUrlsForKeywords();
	bool ProcessResults(database::SelectResultContainer<database::TableBase>& results);

private:
	QueryContentThreadParam* params;
	std::vector<std::string> lowerKeywords;

	std::vector<long long> keywordIDs;
	std::vector< std::vector<long long> > caseInsensitiveKeywordIDs;

	database::DatabaseHelper dbHelper;

	std::vector<QueryContentThread::QueryContentResultEntry> resultEntries;
};

}
