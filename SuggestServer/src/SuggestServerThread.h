/*
 * SuggestServerThread.h
 *
 *  Created on: 12.06.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <FastCGIServerThread.h>
#include "SuggestServerRequest.h"
#include "SuggestServerResponse.h"

namespace suggestserver {

class SuggestServerThread : public fastcgiserver::FastCGIServerThread {
public:
	SuggestServerThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket);
	virtual ~SuggestServerThread();

private:
	virtual fastcgiserver::FastCGIRequest*  CreateRequest() { return new SuggestServerRequest(this); }
	virtual fastcgiserver::FastCGIResponse* CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request) { return new SuggestServerResponse(dbHelper, static_cast<SuggestServerRequest*>(request)); }
	virtual const char* GetThreadName() const { return "SuggestServerThread"; }
};

}
