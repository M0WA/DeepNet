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

QueryProcessManager QueryServer::queryProcessManager;

QueryServer::QueryServer()
: fastcgiserver::FastCGIServer()
, requery_after(120)
{
}

QueryServer::~QueryServer()
{
	if(!cleanupThread.IsNull()) {
		cleanupThread.Get()->SetShallEnd();
		cleanupThread.Get()->WaitForThread();
		cleanupThread.Release(); }
}

fastcgiserver::FastCGIServerThread* QueryServer::CreateThread(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket)
{
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
			new QueryServerThread(databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, socket));
}

bool QueryServer::StartServer(int argc, char** argv)
{
	bool success(fastcgiserver::FastCGIServer::StartServer(argc, argv));

	if(success) {
		cleanupThread.Set(new QueryResultCleanupThread(databaseConfig, requery_after),true);
		cleanupThread.Get()->StartThread(0);}

	return success;
}

bool QueryServer::StopServer()
{
	if(!cleanupThread.IsNull()) {
		cleanupThread.Get()->SetShallEnd();
		cleanupThread.Get()->WaitForThread();
		cleanupThread.Release(); }

	return fastcgiserver::FastCGIServer::StopServer();
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
