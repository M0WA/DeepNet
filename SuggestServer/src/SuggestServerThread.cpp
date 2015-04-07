/*
 * SuggestServerThread.cpp
 *
 *  Created on: 12.06.2012
 *      Author: Moritz Wagner
 */

#include "SuggestServerThread.h"

namespace suggestserver {

SuggestServerThread::SuggestServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex, socket)
{
}

SuggestServerThread::~SuggestServerThread()
{
}

}
