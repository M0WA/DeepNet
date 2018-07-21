/*
 * @file SyncServer.h
 * @author Moritz Wagner
 * @date 11.27.2017
 */

#pragma once

#include <FastCGIServer.h>

namespace fastcgiserver {
	class FastCGIServerThread;
}

namespace syncserver {

/**
 * @brief main class of sync server. responsible to distribute
 *        urls/domains among crawlers (WorkerBots)
 */
class SyncServer : public fastcgiserver::FastCGIServer {
public:
	SyncServer();
	virtual ~SyncServer();

	virtual bool StartServer(int argc, char** argv);

private:
	virtual void RegisterConfig();
	virtual bool InitConfig();

	virtual fastcgiserver::FastCGIServerThread* CreateThreadPort(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& ip, const int port, const int backlog);
	virtual fastcgiserver::FastCGIServerThread* CreateThreadSocket(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const std::string& filename, const int backlog);
};

}
