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
		_QueryContentThreadParam(const database::DatabaseConfig* config, const std::vector<std::string>& keywords, const bool caseInsensitive = true)
		: config(config)
		, keywords(keywords)
		, caseInsensitive(caseInsensitive) {}

		const database::DatabaseConfig* config;
		const std::vector<std::string> keywords;
		const bool caseInsensitive;
	} QueryContentThreadParam;

public:
	QueryContentThread();
	virtual ~QueryContentThread();

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
};

}
