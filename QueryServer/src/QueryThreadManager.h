/**
 *
 * @file QueryThreadManager.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

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
	void GetResult();
};

}

