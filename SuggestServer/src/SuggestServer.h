/*
 * SuggestServer.h
 *
 *  Created on: 12.06.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <FastCGIServer.h>

namespace suggestserver {

class SuggestServer : public fastcgiserver::FastCGIServer {
public:
	SuggestServer();
	virtual ~SuggestServer();

	virtual bool StartServer(int argc, char** argv);

private:
	virtual void RegisterConfig();
	virtual bool InitConfig();

	virtual fastcgiserver::FastCGIServerThread* CreateThreadPort(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const int port, const int backlog = 0);
	virtual fastcgiserver::FastCGIServerThread* CreateThreadSocket(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog = 0);
};

}
