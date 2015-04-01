/**
 * @file FastCGIServerThread.h
 * @author Moritz Wagner
 * @date 13.03.2012
 */

#pragma once

#include "FastCGISocket.h"
#include "FastCGIRequest.h"
#include "FastCGIResponse.h"
#include "FastCGIServerThreadConfig.h"

#include <DatabaseLayer.h>
#include <Thread.h>
#include <Mutex.h>
#include <Pointer.h>
#include <SpellChecking.h>

namespace fastcgiserver {

/**
 * @brief thread that manages a FastCGI instance listening on a socket
 */
class FastCGIServerThread : public threading::Thread
{
public:
	FastCGIServerThread(FastCGIServerThreadConfig* config);
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

public:
	const unsigned long long& GetMaxPostSize() const;

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
	tools::Pointer<FastCGIServerThreadConfig> config;
	tools::SpellChecking spellChecker;
	database::DatabaseHelper dbHelper;
	FCGX_Request request;
};

}
