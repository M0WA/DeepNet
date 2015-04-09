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
: fastcgiserver::FastCGIServer()
, requery_after(120) {
}

QueryResultServer::~QueryResultServer() {
}

bool QueryResultServer::StartServer(int argc, char** argv) {
	bool success(fastcgiserver::FastCGIServer::StartServer(argc, argv));
	log::Logging::SetApplicationName("QueryResultServer");
	log::Logging::LogTrace("QueryResultServer::StartServer() returns %d",success);
	return success;
}

bool QueryResultServer::StopServer() {
	bool success(fastcgiserver::FastCGIServer::StopServer());
	return success;
}

void QueryResultServer::RegisterConfig() {
	std::string defaultRequeryAfter = "120";
	Config().RegisterParam("requery_after", "requery user after n seconds", false, &defaultRequeryAfter );
}

bool QueryResultServer::InitConfig() {
	if(!Config().GetValue("requery_after", requery_after)) {
		log::Logging::LogError("missing requery_after parameter");
		return false; }
	return true;
}

fastcgiserver::FastCGIServerThread* QueryResultServer::CreateThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket) {
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
			new QueryResultServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, socket));
}

}
