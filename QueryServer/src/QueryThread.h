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

#include "QueryThreadResultEntry.h"

namespace database {
	class DatabaseConfig;
}

namespace queryserver {

	class Query;
	class QueryThreadParam;

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
	bool InitThreadInstance(threading::Thread::THREAD_PARAM* threadParam);

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

