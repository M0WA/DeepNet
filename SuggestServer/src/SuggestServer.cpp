/*
 * SuggestServer.cpp
 *
 *  Created on: 12.06.2012
 *      Author: Moritz Wagner
 */

#include "SuggestServer.h"
#include "SuggestServerThread.h"

namespace suggestserver {

SuggestServer::SuggestServer()
: fastcgiserver::FastCGIServer()
{
}

SuggestServer::~SuggestServer()
{
}

bool SuggestServer::StartServer(int argc, char** argv)
{
	return fastcgiserver::FastCGIServer::StartServer(argc, argv);
}

void SuggestServer::RegisterConfig()
{
}

bool SuggestServer::InitConfig()
{
	return true;
}

fastcgiserver::FastCGIServerThread* SuggestServer::CreateThreadPort(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const int port, const int backlog)
{
	return new SuggestServerThread( databaseConfig, acceptMutex, port, backlog);
}

fastcgiserver::FastCGIServerThread* SuggestServer::CreateThreadSocket(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog)
{
	return new SuggestServerThread( databaseConfig, acceptMutex, filename, backlog);
}

}
