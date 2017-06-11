/*
 * SuggestServerThread.cpp
 *
 *  Created on: 12.06.2012
 *      Author: Moritz Wagner
 */

#include "SuggestServerThread.h"

namespace suggestserver {

SuggestServerThread::SuggestServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& ip, const int port, const int backlog)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex, ip, port, backlog)
{
}

SuggestServerThread::SuggestServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex, filename, backlog)
{
}

SuggestServerThread::~SuggestServerThread()
{
}

}
