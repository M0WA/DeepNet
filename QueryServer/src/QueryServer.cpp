/**
 *
 * @file QueryServer.cpp
 * @author Moritz Wagner
 * @date 12.03.2012
 *
 */

#include "QueryServer.h"

#include <Logging.h>

#include "QueryServerThread.h"

namespace queryserver {

QueryServer::QueryServer()
: fastcgiserver::FastCGIServer()
{
}

QueryServer::~QueryServer()
{
}

fastcgiserver::FastCGIServerThread* QueryServer::CreateThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket)
{
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
			new QueryServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, socket));
}

bool QueryServer::StartServer(int argc, char** argv)
{
	bool success(fastcgiserver::FastCGIServer::StartServer(argc, argv));
	log::Logging::SetApplicationName("QueryServer");
	log::Logging::LogTrace("QueryServer::StartServer() returns %d",success);
	return success;
}

bool QueryServer::StopServer()
{
	return fastcgiserver::FastCGIServer::StopServer();
}

void QueryServer::RegisterConfig()
{
}

bool QueryServer::InitConfig()
{
	return true;
}

}
