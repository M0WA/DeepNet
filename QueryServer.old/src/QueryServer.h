/**
 *
 * @file QueryServer.h
 * @author Moritz Wagner
 * @date 12.03.2012
 *
 */

#pragma once

#include <string>
#include <FastCGIServer.h>

#include "QueryServerConfig.h"

namespace fastcgiserver {
	class FastCGIServerThread;
}

namespace database {
	class DatabaseConfig;
}

namespace threading {
	class Mutex;
}

namespace queryserver {

/**
 * @brief implements fastcgiserver::FastCGIServer used for query server application
 */
class QueryServer : public fastcgiserver::FastCGIServer
{
public:
	QueryServer();
	virtual ~QueryServer();

public:
	virtual bool StartServer(int argc, char** argv);

private:
	virtual void RegisterConfig();
	virtual bool InitConfig();

	virtual fastcgiserver::FastCGIServerThread* CreateThreadPort(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const int port, const int backlog = 0);
	virtual fastcgiserver::FastCGIServerThread* CreateThreadSocket(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog = 0);

private:
	QueryServerConfig queryserverConfig;
};

}