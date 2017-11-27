/**
 * @file main.cpp
 * @author Moritz Wagner
 * @date 11.27.2017
 */

#include "SyncServer.h"

#include <Exception.h>
#include <Logging.h>
#include <Thread.h>
#include <DebuggingTools.h>

#include <iostream>
#include <csignal>

volatile static bool run = true;
static threading::Mutex signalMutex;
static syncserver::SyncServer serverSync;

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

int main(int argc, char** argv) {
	try {
		RegisterSignalHandlers();

		bool bSuccess = true;
		bSuccess &= serverSync.StartServer(argc,argv);

		if( bSuccess ) {
			while(run)
				sleep(1);
		}
		else {
			std::cerr << "fatal error while starting server";
		}

		serverSync.StopServer();
	}
	CATCH_EXCEPTION(errors::Exception,ex,1)
		serverSync.OnException(ex);
		return 1;
	}
	return 0;
}
