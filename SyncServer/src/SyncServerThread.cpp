/*
 * @file SyncServerThread.cpp
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#include "SyncServerThread.h"
#include "SyncServerRequest.h"
#include "SyncServerResponse.h"

namespace syncserver {

SyncServerThread::SyncServerThread(const std::string& crawler_sync_pass, database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& ip, const int port, const int backlog)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex, ip, port, backlog)
, databaseConfig(databaseConfig)
, crawler_sync_pass(crawler_sync_pass) {
}

SyncServerThread::SyncServerThread(const std::string& crawler_sync_pass, database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex, filename, backlog)
, databaseConfig(databaseConfig)
, crawler_sync_pass(crawler_sync_pass) {
}

SyncServerThread::~SyncServerThread() {
}

fastcgiserver::FastCGIRequest*  SyncServerThread::CreateRequest() {
	return new SyncServerRequest(this,crawler_sync_pass);
}

fastcgiserver::FastCGIResponse* SyncServerThread::CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request) {
	return new SyncServerResponse(dbHelper, static_cast<SyncServerRequest*>(request));
}

}
