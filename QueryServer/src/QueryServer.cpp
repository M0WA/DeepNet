/**
 *
 * @file QueryServer.cpp
 * @author Moritz Wagner
 * @date 12.03.2012
 *
 */

#include "QueryServer.h"

#include <Logging.h>

#include "QueryServerThread.h"

namespace queryserver {

QueryServer::QueryServer()
: fastcgiserver::FastCGIServer()
, requery_after(120)
{
}

QueryServer::~QueryServer()
{
}

fastcgiserver::FastCGIServerThread* QueryServer::CreateThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket)
{
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
			new QueryServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, socket));
}

bool QueryServer::StartServer(int argc, char** argv)
{
	bool success(fastcgiserver::FastCGIServer::StartServer(argc, argv));
	log::Logging::SetApplicationName("QueryServer");
	log::Logging::LogTrace("QueryServer::StartServer() returns %d",success);
	return success;
}

bool QueryServer::StopServer()
{
	return fastcgiserver::FastCGIServer::StopServer();
}

void QueryServer::RegisterConfig()
{
	std::string defaultRequeryAfter = "120";
	Config().RegisterParam("requery_after", "requery user after n seconds", false, &defaultRequeryAfter );
}

bool QueryServer::InitConfig()
{
	if(!Config().GetValue("requery_after", requery_after)) {
		log::Logging::LogError("missing requery_after parameter");
		return false; }

	std::string configFileName;
	if(Config().GetValue("logfile",configFileName)) {
		configFileName = configFileName + ".query.log";
		Config().SetValue("logfile",configFileName); }

	return true;
}

}
