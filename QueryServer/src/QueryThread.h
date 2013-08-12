/**
 *
 * @file QueryThread.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include <Thread.h>
#include <PointerContainer.h>

#include <DatabaseHelper.h>

namespace database {
	class DatabaseConfig;
}

namespace queryserver {

class Query;

typedef struct _QueryThreadParam {

	_QueryThreadParam(const database::DatabaseConfig* config, const Query& query)
	: config(config)
	, query(query) {}

	const database::DatabaseConfig* config;
	const Query& query;

} QueryThreadParam;

typedef struct _QueryThreadResultEntry {

	_QueryThreadResultEntry(const long long& urlID, const long long& urlStageID)
	: urlID(urlID)
	, urlStageID(urlStageID)
	{}

	long long urlID;
	long long urlStageID;
	std::vector<long long> detectedKeywords;

} QueryThreadResultEntry;

/**
 * @brief base class for all query threads
 * @see queryserver::QueryThreadManager
 */
class QueryThread : public threading::Thread {
public:
	QueryThread();
	virtual ~QueryThread();

public:
	/**
	 * returns results of quering by the contents of webpages.
	 * use only when thread has ended.
	 * @return results
	 */
	const tools::PointerContainer<QueryThreadResultEntry>& GetResults() const {
		return resultEntries; }

private:
	static void* QueryThreadFunction(threading::Thread::THREAD_PARAM* threadParam);

protected:
	bool DestroyThreadInstance();

private:
	bool InitThreadInstance();

private:
	virtual bool OnInitThreadInstance()=0;
	virtual bool OnDestroyThreadInstance()=0;
	virtual const char* GetThreadName() const=0;
	virtual void* Run()=0;

protected:
	tools::PointerContainer<QueryThreadResultEntry> resultEntries;
	database::DatabaseHelper dbHelper;

	QueryThreadParam* queryThreadParam;
	const threading::Thread::THREAD_PARAM* threadParam;
};

}

