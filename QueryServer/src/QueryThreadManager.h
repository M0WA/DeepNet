/**
 *
 * @file QueryThreadManager.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include <map>

#include <ThreadManager.h>

#include "QueryThread.h"

namespace database {
	class DatabaseConfig;
}

namespace queryserver {

	class Query;

class QueryThreadManager : private threading::ThreadManager<queryserver::QueryThread> {
public:
	QueryThreadManager();
	virtual ~QueryThreadManager();

public:
	void AddQuery(const database::DatabaseConfig* dbConfig,const Query& query);
	void WaitForResult();

private:
	template <class threadT, class paramT>
	void AddQueryTyped(const database::DatabaseConfig* dbConfig,const Query& query)	{
		queryThreadIDs.push_back(
			AddThread(
				new threadT(),
				new paramT(dbConfig, query))
		);
	}

private:
	std::vector<threading::Thread::ThreadID> queryThreadIDs;
};

}

