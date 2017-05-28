/*
 * InspectorServerThread.h
 *
 *  Created on: 06.05.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <FastCGIServerThread.h>
#include "InspectorServerRequest.h"
#include "InspectorServerResponse.h"

namespace inspectorserver {

class InspectorServerThread : public fastcgiserver::FastCGIServerThread {
public:
	InspectorServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& ip, const int port, const int backlog);
	InspectorServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog);
	virtual ~InspectorServerThread();

private:
	virtual fastcgiserver::FastCGIRequest*  CreateRequest() { return new InspectorServerRequest(this); }
	virtual fastcgiserver::FastCGIResponse* CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request) { return new InspectorServerResponse(dbHelper, static_cast<InspectorServerRequest*>(request)); }
	virtual const char* GetThreadName() const { return "InspectorServerThread"; }
};

}

