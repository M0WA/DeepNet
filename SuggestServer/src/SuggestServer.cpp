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

fastcgiserver::FastCGIServerThread* SuggestServer::CreateThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket)
{
	return new SuggestServerThread( databaseConfig, acceptMutex, socket);
}

}
