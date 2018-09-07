/*
 * @file SyncServer.cpp
 * @author Moritz Wagner
 * @date 11.27.2017
 */

#include "SyncServer.h"

#include "SyncServerThread.h"

#include <Logging.h>

namespace syncserver {

SyncServer::SyncServer()
: crawler_sync_pass("") {
}

SyncServer::~SyncServer() {
}

bool SyncServer::StartServer(int argc, char** argv)
{
	return fastcgiserver::FastCGIServer::StartServer(argc, argv);
}

void SyncServer::RegisterConfig()
{
	Config().RegisterParam("crawler_sync_pass", "password for sync clients", true, &crawler_sync_pass);
}

bool SyncServer::InitConfig()
{
	log::Logging::SetApplicationName("SyncServer");

	if( !Config().GetValue( "crawler_sync_pass", crawler_sync_pass) ) {
        log::Logging::LogError("missing parameter crawler_sync_pass");
		return false;
    }
	return true;
}

fastcgiserver::FastCGIServerThread* SyncServer::CreateThreadPort(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const std::string& ip, const int port, const int backlog)
{
	return new SyncServerThread(crawler_sync_pass, databaseConfig, acceptMutex, ip, port, backlog);
}

fastcgiserver::FastCGIServerThread* SyncServer::CreateThreadSocket(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const std::string& filename, const int backlog) 
{
	return new SyncServerThread(crawler_sync_pass, databaseConfig, acceptMutex, filename, backlog);
}

}
