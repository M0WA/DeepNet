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
#include "FastCGIServerThreadConfig.h"

namespace fastcgiserver {

FastCGIServerThread::FastCGIServerThread(FastCGIServerThreadConfig* config)
: threading::Thread((threading::Thread::ThreadFunction)&(FastCGIServerThread::FastCGIServerThreadFunc))
, config(config) {
}

FastCGIServerThread::~FastCGIServerThread() {
}

void* FastCGIServerThread::FastCGIServerThreadFunc(threading::Thread::THREAD_PARAM* threadParam) {
	FastCGIServerThread* instance(dynamic_cast<FastCGIServerThread*>(threadParam->instance));
	log::Logging::RegisterThreadID(instance->GetThreadName());

	database::DatabaseConnection* conn(instance->DB().CreateConnection(instance->config.GetConst()->GetDatabaseConfig()));
	if(!conn) {
		THROW_EXCEPTION(FastCGIServerException,"FastCGIServerException","could not establish database connection"); }

	FastCGIRequest* fcgiRequest(0);
	FastCGIResponse* fcgiResponse(0);

	int initSuccess(FCGX_InitRequest(&instance->request, instance->config.Get()->GetFastCGISocket().Socket(), FCGI_FAIL_ACCEPT_ON_INTR));
	if(initSuccess != 0) {
		THROW_EXCEPTION(FastCGIServerInitException,"could not initialize fastcgi request");	}

	while(!instance->ShallEnd()) {

		instance->config.Get()->GetAcceptMutex()->Lock();
		bool isAcceptWaiting(false);
		while( !instance->ShallEnd() ) {
			isAcceptWaiting = false;
			if( (isAcceptWaiting = instance->config.Get()->GetFastCGISocket().WaitForAccept()) ) {
				break;	}
		}

		int rc = -1;
		if(isAcceptWaiting)
			rc = FCGX_Accept_r(&instance->request);
		instance->config.Get()->GetAcceptMutex()->Unlock();

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
