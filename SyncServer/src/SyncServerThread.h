/*
 * @file SyncServerThread.h
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <FastCGIServerThread.h>

namespace syncserver {

/**
 * @brief fastcgi main server thread for sync server
 * @see fastcgiserver::FastCGIServerThread
 * @see syncserver::SyncServer
 */
class SyncServerThread: public fastcgiserver::FastCGIServerThread {
public:
	SyncServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& ip, const int port, const int backlog);
	SyncServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog);
	virtual ~SyncServerThread();

public:
	database::DatabaseConfig* databaseConfig;

private:
	virtual fastcgiserver::FastCGIRequest*  CreateRequest();
	virtual fastcgiserver::FastCGIResponse* CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request);
	virtual const char* GetThreadName() const { return "SyncServerThread"; }
};

}
