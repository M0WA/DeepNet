/*
 * QueryServer.cpp
 *
 *  Created on: 12.03.2012
 *      Author: Moritz Wagner
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

fastcgiserver::FastCGIServerThread* QueryServer::CreateThreadPort(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const int port, const int backlog)
{
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
			new QueryServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, port, backlog));
}

fastcgiserver::FastCGIServerThread* QueryServer::CreateThreadSocket(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog)
{
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
			new QueryServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, filename, backlog));
}

bool QueryServer::StartServer(int argc, char** argv)
{
	bool success(fastcgiserver::FastCGIServer::StartServer(argc, argv));
	return success;
}

void QueryServer::RegisterConfig()
{
}

bool QueryServer::InitConfig()
{
	log::Logging::SetApplicationName("QueryServer");
	return true;
}

}
