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

class QueryServerThread : public fastcgiserver::FastCGIServerThread
{
public:
	QueryServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, const int port, const int backlog = 0);
	QueryServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, const std::string& filename, const int backlog = 0);
	virtual ~QueryServerThread();

private:
	virtual fastcgiserver::FastCGIRequest*  CreateRequest();
	virtual fastcgiserver::FastCGIResponse* CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request);

	std::string requestXSD;
	std::string responseXSD;

	QueryThreadManager threadManager;
};

}

