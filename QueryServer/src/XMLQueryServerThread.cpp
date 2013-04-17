/*
 * XMLQueryServerThread.cpp
 *
 *  Created on: 16.03.2012
 *      Author: Moritz Wagner
 */

#include "XMLQueryServerThread.h"

namespace queryserver {

XMLQueryServerThread::XMLQueryServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, const int port, const int backlog)
: FastCGIServerThread(databaseConfig,acceptMutex,port,backlog)
, requestXSD(requestXSD)
, responseXSD(responseXSD)
{
}

XMLQueryServerThread::XMLQueryServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, const std::string& filename, const int backlog)
: FastCGIServerThread(databaseConfig,acceptMutex,filename,backlog)
, requestXSD(requestXSD)
, responseXSD(responseXSD)
{

}

XMLQueryServerThread::~XMLQueryServerThread() {
}

}
