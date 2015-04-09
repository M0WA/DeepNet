/**
 * @file QueryResultServerThread.h
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#pragma once

#include <FastCGIServerThread.h>

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
 * @brief encapsulates fastcgiserver::FastCGIServerThread for queryserver::QueryResultServer
 */
class QueryResultServerThread : public fastcgiserver::FastCGIServerThread {
public:
	QueryResultServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket);
	virtual ~QueryResultServerThread();

private:
	virtual fastcgiserver::FastCGIRequest*  CreateRequest();
	virtual fastcgiserver::FastCGIResponse* CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request);
	virtual const char* GetThreadName() const { return "QueryResultServerThread"; }

	std::string requestXSD;
	std::string responseXSD;
};

}
