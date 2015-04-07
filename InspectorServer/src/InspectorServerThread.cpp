/*
 * InspectorServerThread.cpp
 *
 *  Created on: 06.05.2012
 *      Author: Moritz Wagner
 */

#include "InspectorServerThread.h"

namespace inspectorserver {

InspectorServerThread::InspectorServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex, socket)
{
}

InspectorServerThread::~InspectorServerThread()
{
}

}
