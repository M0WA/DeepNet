/*
 * XMLQueryServerThread.h
 *
 *  Created on: 16.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <FastCGIServerThread.h>
#include "XMLQueryRequest.h"
#include "XMLQueryResponse.h"
#include <string>

namespace queryserver {

class XMLQueryServerThread : public fastcgiserver::FastCGIServerThread {
public:
	XMLQueryServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, const int port, const int backlog = 0);
	XMLQueryServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, const std::string& filename, const int backlog = 0);

	virtual ~XMLQueryServerThread();

private:
	virtual fastcgiserver::FastCGIRequest*  CreateRequest() { return new XMLQueryRequest(this); }
	virtual fastcgiserver::FastCGIResponse* CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request) { return new XMLQueryResponse(dbHelper, static_cast<XMLQueryRequest*>(request)); }

	std::string requestXSD;
	std::string responseXSD;
};

}
