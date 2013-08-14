/*
 * QueryServer.cpp
 *
 *  Created on: 12.03.2012
 *      Author: Moritz Wagner
 */

#include "QueryServer.h"

#include <Logging.h>

#define QUERY_SERVER_THREAD_NEW
#ifndef QUERY_SERVER_THREAD_NEW
	#include "XMLQueryServerThread.h"
#else
	#include "QueryServerThread.h"
#endif

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
#ifndef QUERY_SERVER_THREAD_NEW
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
			new XMLQueryServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, port, backlog));
#else
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
			new QueryServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, port, backlog));
#endif

}

fastcgiserver::FastCGIServerThread* QueryServer::CreateThreadSocket(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog)
{
#ifndef QUERY_SERVER_THREAD_NEW
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
			new XMLQueryServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, filename, backlog));
#else
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
			new QueryServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, filename, backlog));
#endif

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
