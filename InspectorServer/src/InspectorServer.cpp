/*
 * InspectorServer.cpp
 *
 *  Created on: 06.05.2012
 *      Author: Moritz Wagner
 */

#include "InspectorServer.h"
#include "InspectorServerThread.h"

namespace inspectorserver {

InspectorServer::InspectorServer()
: fastcgiserver::FastCGIServer()
{
}

InspectorServer::~InspectorServer()
{
}

bool InspectorServer::StartServer(int argc, char** argv)
{
	return fastcgiserver::FastCGIServer::StartServer(argc, argv);
}

void InspectorServer::RegisterConfig()
{
}

bool InspectorServer::InitConfig()
{
	return true;
}

fastcgiserver::FastCGIServerThread* InspectorServer::CreateThreadPort(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& ip, const int port, const int backlog)
{
	return new InspectorServerThread( databaseConfig, acceptMutex, ip, port, backlog);
}

fastcgiserver::FastCGIServerThread* InspectorServer::CreateThreadSocket(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog)
{
	return new InspectorServerThread( databaseConfig, acceptMutex, filename, backlog);
}

}
