/*
 * FastCGIServerThread.cpp
 *
 *  Created on: 13.03.2012
 *      Author: Moritz Wagner
 */

#include "FastCGIServerThread.h"

#include <TLD.h>
#include <Logging.h>

#include "FastCGIRequest.h"
#include "FastCGIResponse.h"
#include "FastCGIServerInitException.h"

namespace fastcgiserver {

FastCGIServerThread::FastCGIServerThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex,const int port, const int backlog)
: threading::Thread((threading::Thread::ThreadFunction)&(FastCGIServerThread::FastCGIServerThreadFunc))
, databaseConfig(databaseConfig)
, fcgiSocket(port,backlog)
, isFileSocket(false)
, port(port)
, backlog(backlog)
, filename("")
, acceptMutex(acceptMutex)
{
}

FastCGIServerThread::FastCGIServerThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex,const std::string& filename, const int backlog)
: threading::Thread((threading::Thread::ThreadFunction)&(FastCGIServerThread::FastCGIServerThreadFunc))
, databaseConfig(databaseConfig)
, fcgiSocket(filename,backlog)
, isFileSocket(true)
, port(-1)
, backlog(backlog)
, filename(filename)
, acceptMutex(acceptMutex)
{
}

FastCGIServerThread::~FastCGIServerThread()
{
}

void* FastCGIServerThread::FastCGIServerThreadFunc(threading::Thread::THREAD_PARAM* threadParam)
{
	FastCGIServerThread* instance(dynamic_cast<FastCGIServerThread*>(threadParam->instance));

	database::DatabaseConnection* conn(instance->DB().CreateConnection(instance->databaseConfig));
	if(!conn) {
		THROW_EXCEPTION(FastCGIServerException,"FastCGIServerException","could not establish database connection"); }

	FastCGIRequest* fcgiRequest(0);
	FastCGIResponse* fcgiResponse(0);

	int initSuccess(FCGX_InitRequest(&instance->request, instance->fcgiSocket.Socket(), FCGI_FAIL_ACCEPT_ON_INTR));
	if(initSuccess != 0) {
		THROW_EXCEPTION(FastCGIServerInitException,"could not initialize fastcgi request");	}

	while(!instance->ShallEnd()) {

		instance->acceptMutex->Lock();
		bool isAcceptWaiting(false);
		while( !instance->ShallEnd() ) {
			isAcceptWaiting = false;
			if( (isAcceptWaiting = instance->fcgiSocket.WaitForAccept()) ) {
				break;	}
		}

		int rc = -1;
		if(isAcceptWaiting)
			rc = FCGX_Accept_r(&instance->request);
		instance->acceptMutex->Unlock();

		if(rc != 0)	{
			if(isAcceptWaiting) {
				log::Logging::LogError("error while accepting client ( %d )",rc);}

			goto END_OF_REQUEST;
		}

		if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("client accepted");

		fcgiRequest = instance->CreateRequest();
		fcgiRequest->Handle(instance->request);

		if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("client handled: %s", fcgiRequest->GetClientAddress().c_str());

		if(!fcgiRequest->IsComplete()) {
			if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("error in client request");
			goto END_OF_REQUEST; }

		if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("client request completed");

		fcgiResponse = instance->CreateResponse(instance->DB(),fcgiRequest);
		fcgiResponse->Process(instance->request);
		if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("client response sent");

END_OF_REQUEST:
		FCGX_Finish_r(&instance->request);

		delete fcgiRequest;
		fcgiRequest = NULL;

		delete fcgiResponse;
		fcgiResponse = NULL;

		if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("client finished");
	}

	FCGX_Free(&instance->request, 1);

	instance->DB().DestroyConnection();
	return 0;
}

}
