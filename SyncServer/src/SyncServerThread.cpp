/*
 * @file SyncServerThread.cpp
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#include "SyncServerThread.h"
#include "SyncServerRequest.h"
#include "SyncServerResponse.h"

namespace syncserver {

SyncServerThread::SyncServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& ip, const int port, const int backlog)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex, ip, port, backlog) {
}

SyncServerThread::SyncServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex, filename, backlog) {
}

SyncServerThread::~SyncServerThread() {
}

fastcgiserver::FastCGIRequest*  SyncServerThread::CreateRequest() {
	return new SyncServerRequest(this);
}

fastcgiserver::FastCGIResponse* SyncServerThread::CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request) {
	return new SyncServerResponse(dbHelper, static_cast<SyncServerRequest*>(request));
}

}
