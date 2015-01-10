/**
 *
 * @file QueryThread.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include <map>

#include <Thread.h>

#include <PointerContainer.h>
#include <Pointer.h>

#include "QueryThreadResultEntry.h"

namespace database {
	class DatabaseConnection;
}

namespace queryserver {

	class QueryThreadParam;

/**
 * @brief base class for all query threads
 * @see queryserver::QueryThreadManager
 */
class QueryThread : public threading::Thread {
protected:
	QueryThread();
public:
	virtual ~QueryThread();

public:
	/**
	 * returns results of quering by the contents of webpages.
	 * use only when thread has ended.
	 * @return results
	 */
	const std::map<QueryThreadResultKey,QueryThreadResultEntry>& GetResults() const;

private:
	/**
	 * called when a new query has arrived
	 */
	virtual void OnInitThreadInstance() {}

	/**
	 * called when query is released
	 */
	virtual void OnDestroyThreadInstance() {}

	/**
	 * returns specific name of the thread used for logging purposes
	 * @return specific thread name
	 */
	virtual const char* GetThreadName() const=0;

	/**
	 * called when initialization is done and the query is ready
	 * to be processed
	 */
	virtual void* OnRun()=0;

private:
	static void* QueryThreadFunction(threading::Thread::THREAD_PARAM* threadParam);

private:
	bool InitThreadInstance(threading::Thread::THREAD_PARAM* threadParam);
	bool DestroyThreadInstance();
	void* Run();

protected:
	std::map<QueryThreadResultKey,QueryThreadResultEntry> results;

	/**
	 * contains query thread params
	 */
	tools::Pointer<QueryThreadParam> queryThreadParam;
	database::DatabaseConnection* dbConn;
};

}

