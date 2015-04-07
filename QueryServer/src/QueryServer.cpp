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
			new QueryServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, socket, requery_after));
}

bool QueryServer::StartServer(int argc, char** argv)
{
	bool success(fastcgiserver::FastCGIServer::StartServer(argc, argv));
	return success;
}

void QueryServer::RegisterConfig()
{
	std::string defaultRequeryAfter = "120";
	Config().RegisterParam("requery_after", "requery user after n seconds", false, &defaultRequeryAfter );
}

bool QueryServer::InitConfig()
{
	log::Logging::SetApplicationName("QueryServer");
	if(!Config().GetValue("requery_after", requery_after)) {
		return false; }
	return true;
}

}
