/*
 * QueryServer.cpp
 *
 *  Created on: 12.03.2012
 *      Author: Moritz Wagner
 */

#include "QueryServer.h"
#include <sstream>

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
	return new XMLQueryServerThread( databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, port, backlog);
}

fastcgiserver::FastCGIServerThread* QueryServer::CreateThreadSocket(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog)
{
	return new XMLQueryServerThread( databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, filename, backlog);
}

bool QueryServer::StartServer(int argc, char** argv)
{
	return fastcgiserver::FastCGIServer::StartServer(argc, argv);
}

void QueryServer::RegisterConfig()
{
}

bool QueryServer::InitConfig()
{
	return true;
}

}
