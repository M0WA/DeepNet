/**
 * @file FastCGIServerThread.h
 * @author Moritz Wagner
 * @date 13.03.2012
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

/**
 * @brief thread that manages a FastCGI instance listening on a socket
 */
class FastCGIServerThread : public threading::Thread
{
public:
	/**
	 * create FastCGI server thread using tcp by ip and port
	 * @param databaseConfig database config
	 * @param acceptMutex mutex for accept()
	 * @param ip ip for tcp socket (empty for all)
	 * @param port port for tcp socket
	 * @param backlog backlog of listen socket (0 for unlimited)
	 */
	FastCGIServerThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const std::string& ip, const int port, const int backlog);

	/**
	 * create FastCGI server thread using a unix file socket
	 * @param databaseConfig database config
	 * @param acceptMutex mutex for accept()
	 * @param filename filename for unix socket
	 * @param backlog backlog of listen socket (0 for unlimited)
	 */
	FastCGIServerThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const std::string& filename, const int backlog);

	virtual ~FastCGIServerThread();

public:
	/**
	 * gets database connection for this thread
	 * @return database connection
	 */
	database::DatabaseHelper& DB() {return dbHelper;}

	/**
	 * gets spellchecking instance for this thread
	 * @return spellchecking instance
	 */
	tools::SpellChecking& SpellChecker() { return spellChecker; }

private:
	/**
	 * creates returns a new request
	 * @return new request
	 */
	virtual FastCGIRequest* CreateRequest()=0;

	/**
	 * creates returns a new response
	 * @return new response
	 */
	virtual FastCGIResponse* CreateResponse(database::DatabaseHelper& dbHelper,FastCGIRequest* request)=0;

	/**
	 * gets this thread's name
	 * @return this thread's name
	 */
	virtual const char* GetThreadName() const =0;

private:
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
