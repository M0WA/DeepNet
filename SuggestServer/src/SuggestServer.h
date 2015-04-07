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

	virtual fastcgiserver::FastCGIServerThread* CreateThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket);
};

}
