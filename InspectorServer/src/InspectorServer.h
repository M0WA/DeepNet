/*
 * InspectorServer.h
 *
 *  Created on: 06.05.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <FastCGIServer.h>

namespace inspectorserver {

class InspectorServer : public fastcgiserver::FastCGIServer {
public:
	InspectorServer();
	virtual ~InspectorServer();

	virtual bool StartServer(int argc, char** argv);

private:
	virtual void RegisterConfig();
	virtual bool InitConfig();

	virtual fastcgiserver::FastCGIServerThread* CreateThread(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket);
};

}
