/*
 * FastCGIServerThread.h
 *
 *  Created on: 13.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "FastCGISocket.h"
#include "FastCGIRequest.h"
#include "FastCGIResponse.h"

#include <DatabaseLayer.h>
#include <Thread.h>
#include <Mutex.h>
#include <SpellChecking.h>


namespace fastcgiserver {

class FastCGIServerThread : public threading::Thread
{
public:
	FastCGIServerThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const int port, const int backlog = 0);
	FastCGIServerThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const std::string& filename, const int backlog = 0);
	virtual ~FastCGIServerThread();

public:
	database::DatabaseHelper& DB() {return dbHelper;}
	tools::SpellChecking& SpellChecker() { return spellChecker; }

private:
	virtual FastCGIRequest*  CreateRequest()=0;
	virtual FastCGIResponse* CreateResponse(database::DatabaseHelper& dbHelper,FastCGIRequest* request)=0;
	static void* FastCGIServerThreadFunc(threading::Thread::THREAD_PARAM* param);

private:
	tools::SpellChecking spellChecker;
	database::DatabaseHelper dbHelper;
	database::DatabaseConfig* databaseConfig;

	FCGX_Request request;
	FastCGISocket fcgiSocket;

	bool isFileSocket;
	int port;
	int backlog;
	std::string filename;
	threading::Mutex* acceptMutex;
};

}
