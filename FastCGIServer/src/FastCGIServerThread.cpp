/**
 * @file FastCGIServerThread.cpp
 * @author Moritz Wagner
 * @date 13.03.2012
 */

#include "FastCGIServerThread.h"

#include <TLD.h>
#include <Logging.h>

#include "FastCGIRequest.h"
#include "FastCGIResponse.h"
#include "FastCGIServerInitException.h"

namespace fastcgiserver {

FastCGIServerThread::FastCGIServerThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const std::string& ip,const int port, const int backlog)
: threading::Thread((threading::Thread::ThreadFunction)&(FastCGIServerThread::FastCGIServerThreadFunc))
, databaseConfig(databaseConfig)
, fcgiSocket(ip,port,backlog)
, isFileSocket(false)
, port(port)
, backlog(backlog)
, filename(ip)
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
	log::Logging::RegisterThreadID(instance->GetThreadName());

	database::DatabaseConnection* conn(instance->DB().CreateConnection(instance->databaseConfig));
	if(!conn) {
		THROW_EXCEPTION(FastCGIServerException,"FastCGIServerException","could not establish database connection"); }

	FastCGIRequest* fcgiRequest(0);
	FastCGIResponse* fcgiResponse(0);

	int initSuccess(FCGX_InitRequest(&instance->request, instance->fcgiSocket.Socket(), FCGI_FAIL_ACCEPT_ON_INTR));
	if(initSuccess != 0) {
		THROW_EXCEPTION(FastCGIServerInitException,"could not initialize fastcgi request");	}

	if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("ready for processing fastcgi requests");

	while(!instance->ShallEnd()) {

		/*
		if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("waiting for fastcgi accept mutex");
		instance->acceptMutex->Lock();
		if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("aquired fastcgi accept mutex");
		*/

		if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("waiting for fastcgi accept");

		bool isAcceptWaiting(false);
		while( !instance->ShallEnd() ) {
			isAcceptWaiting = false;
			if( (isAcceptWaiting = instance->fcgiSocket.WaitForAccept()) ) {
				break;	}
		}

		if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("fastcgi accept ready: %d",isAcceptWaiting);

		int rc = -1;
		if(isAcceptWaiting)
			rc = FCGX_Accept_r(&instance->request);

		/*
		if(log::Logging::IsLogLevelTrace())	log::Logging::LogTrace("unlocking fastcgi accept mutex");
		instance->acceptMutex->Unlock();
		*/

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

		if(log::Logging::IsLogLevelTrace()) {
			std::string envstring = FastCGIRequest::DumpEnv(instance->request);
			log::Logging::LogTrace("client request received: %s",envstring.c_str());
		}

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
