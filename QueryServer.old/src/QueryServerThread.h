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

class QueryServerConfig;

/**
 * @brief encapsulates fastcgiserver::FastCGIServerThread for queryserver::QueryServer
 */
class QueryServerThread : public fastcgiserver::FastCGIServerThread
{
public:
	QueryServerThread(const queryserver::QueryServerConfig& queryserverConfig, database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, const int port, const int backlog = 0);
	QueryServerThread(const queryserver::QueryServerConfig& queryserverConfig, database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, const std::string& filename, const int backlog = 0);
	virtual ~QueryServerThread();

public:
	/**
	 * gets QueryServerConfig
	 * @return QueryServerConfig of current QueryServer instance
	 */
	const queryserver::QueryServerConfig& GetQueryServerConfig() const;

private:
	virtual fastcgiserver::FastCGIRequest*  CreateRequest();
	virtual fastcgiserver::FastCGIResponse* CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request);
	virtual const char* GetThreadName() const { return "QueryServerThread"; }

private:
	std::string requestXSD;
	std::string responseXSD;

	QueryThreadManager threadManager;
	const queryserver::QueryServerConfig& queryserverConfig;
};

}

