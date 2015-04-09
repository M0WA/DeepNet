/**
 * @file QueryResultServer.cpp
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#include "QueryResultServer.h"
#include "QueryResultServerThread.h"

#include <Logging.h>

namespace queryserver {

QueryResultServer::QueryResultServer()
: fastcgiserver::FastCGIServer(){
}

QueryResultServer::~QueryResultServer() {
}

bool QueryResultServer::StartServer(int argc, char** argv) {
	bool success(fastcgiserver::FastCGIServer::StartServer(argc, argv));
	log::Logging::LogTrace("QueryResultServer::StartServer() returns %d",success);
	return success;
}

bool QueryResultServer::StopServer() {
	bool success(fastcgiserver::FastCGIServer::StopServer());
	return success;
}

void QueryResultServer::RegisterConfig() {
}

bool QueryResultServer::InitConfig() {

	log::Logging::SetApplicationName("QueryServer");

	//we need to set a port range different from
	//query server here, so we start at
	// baseport + number of queryserver threads
	//to make make sure those are not colliding

	std::string socketType = "port";
	if ( !Config().GetValue("socket_type",socketType) ) {
		socketType = "port"; }
	else {
		return false; }

	int threadCount = 1;
	if ( !Config().GetValue("threads",threadCount) )
		threadCount = 1;

	if(socketType.compare("port") == 0) {
		int basePort(0);
		if ( !Config().GetValue("base_port",basePort) )
			return false;

		basePort += threadCount;
		Config().SetValue("base_port",basePort);
	}

	std::string configFileName;
	if(Config().GetValue("logfile",configFileName)) {
		configFileName = configFileName + ".result.log";
		Config().SetValue("logfile",configFileName); }

	return true;
}

fastcgiserver::FastCGIServerThread* QueryResultServer::CreateThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket) {
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
			new QueryResultServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, socket));
}

}
