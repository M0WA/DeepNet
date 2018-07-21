/*
 * @file SyncServer.cpp
 * @author Moritz Wagner
 * @date 11.27.2017
 */

#include "SyncServer.h"

#include "SyncServerThread.h"

#include <Logging.h>

namespace syncserver {

SyncServer::SyncServer() {
}

SyncServer::~SyncServer() {
}

bool SyncServer::StartServer(int argc, char** argv)
{
	return fastcgiserver::FastCGIServer::StartServer(argc, argv);
}

void SyncServer::RegisterConfig()
{
}

bool SyncServer::InitConfig()
{
	log::Logging::SetApplicationName("SyncServer");
	return true;
}

fastcgiserver::FastCGIServerThread* SyncServer::CreateThreadPort(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const std::string& ip, const int port, const int backlog)
{
	return new SyncServerThread( databaseConfig, acceptMutex, ip, port, backlog);
}

fastcgiserver::FastCGIServerThread* SyncServer::CreateThreadSocket(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const std::string& filename, const int backlog) {
	return new SyncServerThread( databaseConfig, acceptMutex, filename, backlog);
}

}
