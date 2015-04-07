/**
 *
 * @file QueryServerThread.h
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#pragma once

#include <string>

#include <FastCGIServerThread.h>

#include "QueryThreadManager.h"

namespace database {
	class DatabaseConfig;
	class DatabaseHelper;
}

namespace threading {
	class Mutex;
}

namespace fastcgiserver {
	class FastCGIRequest;
	class FastCGIResponse;
}

namespace queryserver {

/**
 * @brief encapsulates fastcgiserver::FastCGIServerThread for queryserver::QueryServer
 */
class QueryServerThread : public fastcgiserver::FastCGIServerThread
{
public:
	QueryServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket, unsigned long long requery_after);
	virtual ~QueryServerThread();

private:
	virtual fastcgiserver::FastCGIRequest*  CreateRequest();
	virtual fastcgiserver::FastCGIResponse* CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request);
	virtual const char* GetThreadName() const { return "QueryServerThread"; }

	std::string requestXSD;
	std::string responseXSD;

	QueryThreadManager threadManager;
	unsigned long long requery_after;
};

}

