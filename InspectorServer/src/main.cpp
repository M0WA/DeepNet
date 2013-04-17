/*
 * main.cpp
 *
 *  Created on: 12.03.2012
 *      Author: Moritz Wagner
 */

#include "InspectorServer.h"

#include <iostream>
#include <csignal>

#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/engine.h>
#include <openssl/conf.h>
#include <libxml/parser.h>
#include <curl/curl.h>

#include <Thread.h>
#include <DebuggingTools.h>
#include <Logging.h>
#include <Exception.h>

volatile static bool run = true;
static threading::Mutex signalMutex;
static inspectorserver::InspectorServer serverInspector;

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

	tools::DebuggingTools::SignalInfos signalInfo = tools::DebuggingTools::GetSignalInfos(signum, info, ucontext);
	int oldLen = log::Logging::GetMaxLogLength();
	log::Logging::SetMaxLogLength(0);

	switch(signum)
	{
	//none graceful shutdown
	case SIGSEGV:
	case SIGABRT:
	case SIGILL:
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,signalInfo.infoText);
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"killing none gracefully");
		exit(1);
		break;

	//graceful shutdown
	case SIGTERM:
	case SIGINT:
		run = false;
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,signalInfo.infoText);
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"killing gracefully");
		break;

	//graceful restart
	case SIGHUP:
	case SIGUSR1:
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"restart gracefully");
		break;

	//client disconnected (if webserver support this signal)
	case SIGPIPE:
		log::Logging::Log(log::Logging::LOGLEVEL_WARN,"client disconnected");
		break;

	//other signals
	default:
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,signalInfo.infoText);
		break;
	}

	log::Logging::SetMaxLogLength(oldLen);
}


bool RegisterSignalHandlers()
{
	for(int i = 0; i < catchSignalCount;i++)
	{
		struct sigaction sigact;
		sigact.sa_sigaction = &SignalHandler;
		sigact.sa_flags = SA_RESTART | SA_SIGINFO;
		sigaction(catchSignals[i], &sigact, (struct sigaction *)NULL);
	}
	return true;
}

int main(int argc, char** argv)
{
	curl_global_init(CURL_GLOBAL_ALL);
	xmlInitParser();
	SSL_library_init();
	SSL_load_error_strings();
	OpenSSL_add_all_algorithms();

	try {

		RegisterSignalHandlers();

		bool bSuccess = true;
		bSuccess &= serverInspector.StartServer(argc,argv);

		if( bSuccess ) {
			while(run)
				sleep(1);
		}
		else {
			std::cerr << "fatal error while starting server";
		}

		serverInspector.StopServer();
	}
	catch(errors::Exception& ex) {

		serverInspector.OnException(ex);
		return 1;
	}

	ENGINE_cleanup();
	CONF_modules_unload(1);
	ERR_free_strings();
	EVP_cleanup();
	CRYPTO_cleanup_all_ex_data();

	xmlCleanupParser();
	curl_global_cleanup();

	return 0;
}
