/*
 * InspectorServerThread.cpp
 *
 *  Created on: 06.05.2012
 *      Author: Moritz Wagner
 */

#include "InspectorServerThread.h"

namespace inspectorserver {

InspectorServerThread::InspectorServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& ip, const int port, const int backlog)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex, ip, port, backlog)
{
}

InspectorServerThread::InspectorServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex, filename, backlog)
{
}

InspectorServerThread::~InspectorServerThread()
{
}

}
