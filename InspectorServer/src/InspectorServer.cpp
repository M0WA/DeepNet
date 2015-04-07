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

fastcgiserver::FastCGIServerThread* InspectorServer::CreateThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket)
{
	return new InspectorServerThread( databaseConfig, acceptMutex, socket);
}

}
