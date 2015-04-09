/*
 * main.cpp
 *
 *  Created on: 12.03.2012
 *      Author: Moritz Wagner
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <iostream>
#include <csignal>
#include <libxml/parser.h>
#include <curl/curl.h>

#include "QueryServer.h"
#include "QueryResultServer.h"

#include <Logging.h>
#include <Thread.h>
#include <DebuggingTools.h>
#include <Exception.h>

#include <vector>

volatile static bool run = true;
static threading::Mutex signalMutex;

static const int catchSignals[] =
{
		//TODO: fcgi http://www.fastcgi.com/docs/faq.html#Signals
		SIGTERM,
		SIGPIPE,
		SIGUSR1,

		SIGINT,
		SIGSEGV,
		SIGILL,
		SIGABRT,

		SIGHUP,
};

static const int catchSignalCount = sizeof(catchSignals) / sizeof(catchSignals[0]);

void SignalHandler(int signum, siginfo_t* info, void* ucontext)
{
	threading::AutoMutex autoMutex(signalMutex);

	tools::DebuggingTools::SignalInfos signalInfo(tools::DebuggingTools::GetSignalInfos(signum, info, ucontext));

	switch(signum)
	{
	//none graceful shutdown
	case SIGSEGV:
	case SIGABRT:
	case SIGILL:
		log::Logging::LogUnlimited(log::Logging::LOGLEVEL_ERROR,signalInfo.infoText);
		log::Logging::LogError("killing none gracefully");
		exit(1);
		break;

	//graceful shutdown
	case SIGTERM:
	case SIGINT:
		run = false;
		log::Logging::LogUnlimited(log::Logging::LOGLEVEL_ERROR,signalInfo.infoText);
		log::Logging::LogError("killing gracefully");
		break;

	//graceful restart
	case SIGHUP:
	case SIGUSR1:
		log::Logging::LogError("restart gracefully");
		break;

	//client disconnected (if webserver support this signal)
	case SIGPIPE:
		log::Logging::LogWarn("client disconnected");
		break;

	//other signals
	default:
		log::Logging::LogUnlimited(log::Logging::LOGLEVEL_ERROR,signalInfo.infoText);
		break;
	}
}


bool RegisterSignalHandlers() {
	for(int i = 0; i < catchSignalCount;i++) {

		struct sigaction sigact;
		sigact.sa_sigaction = &SignalHandler;
		sigact.sa_flags = SA_RESTART | SA_SIGINFO;
		sigaction(catchSignals[i], &sigact, (struct sigaction *)NULL);
	}
	return true;
}

int main(int argc, char** argv) {

	xmlInitParser();
	curl_global_init(CURL_GLOBAL_ALL);

	RegisterSignalHandlers();

	pid_t childQuery(fork());
	if(!childQuery) {
		//in QueryServer child
		int rc(0);
		queryserver::QueryServer serverQuery;
		try {
			if( serverQuery.StartServer(argc,argv) ) {
				while(run)
					sleep(1);
			}
			else {
				rc = 1;
				log::Logging::LogError("fatal error while starting QueryServer");
			}
			serverQuery.StopServer();
		}
		catch(errors::Exception& ex) {
			serverQuery.OnException(ex);
			rc = 1;
		}
		exit(rc);
	}

	pid_t childResult(fork());
	if(!childResult) {
		//in QueryResultServer child
		int rc(0);
		queryserver::QueryResultServer serverResult;
		try {
			if(serverResult.StartServer(argc,argv) ) {
				while(run)
					sleep(1);
			}
			else {
				rc = 1;
				log::Logging::LogError("fatal error while starting QueryResultServer");
			}
			serverResult.StopServer();
		}
		catch(errors::Exception& ex) {
			serverResult.OnException(ex);
			rc = 1;
		}
		exit(rc);
	}

	while(childResult || childQuery) {
		int status(0);
		if(childResult) {
			if(!childQuery) {
				kill(childResult,SIGINT); }
			if( waitpid(childResult, &status, WNOHANG) == childResult) {
				if (WIFEXITED(status)) {
					childResult = 0;
				}
			}
		}
		if(childQuery) {
			if(!childResult) {
				kill(childQuery,SIGINT); }
			if( waitpid(childQuery, &status, WNOHANG) == childQuery) {
				if (WIFEXITED(status)) {
					childQuery = 0;
				}
			}
		}
		sleep(3);
	}

	curl_global_cleanup();
	xmlCleanupParser();

	return 0;
}
