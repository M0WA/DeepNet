/**
 * @file QueryResultServer.h
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#pragma once

#include <FastCGIServer.h>

namespace fastcgiserver {
	class FastCGIServerThread;
	class FastCGISocket;
}

namespace database {
	class DatabaseConfig;
}

namespace threading {
	class Mutex;
}

namespace queryserver {

/**
 * @brief fastcgi server that queries results for search queries
 */
class QueryResultServer : public fastcgiserver::FastCGIServer {
public:
	QueryResultServer();
	virtual ~QueryResultServer();

public:
	virtual bool StartServer(int argc, char** argv);
	virtual bool StopServer();

private:
	virtual void RegisterConfig();
	virtual bool InitConfig();

	virtual fastcgiserver::FastCGIServerThread* CreateThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket);

private:
	unsigned long long requery_after;
};

}
