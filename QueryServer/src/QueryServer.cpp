/* *
 * @file QueryServer.cpp
 * @author Moritz Wagner
 * @date 10.01.2015
 */

#include "QueryServer.h"

#include <Logging.h>

#include "QueryServerThread.h"

namespace queryserver {

QueryServer::QueryServer() {
}

QueryServer::~QueryServer() {
}

bool QueryServer::StartServer(int argc, char** argv){
	return false;
}

void QueryServer::RegisterConfig(){
	std::string defaultValue = "10000";
	config.RegisterParam("hardlimit_meta", "hardlimit for meta info based results", false, &defaultValue);
	config.RegisterParam("hardlimit_secondleveldomain", "hardlimit for results based on secondlevel domain", false, &defaultValue);
	config.RegisterParam("hardlimit_urlpathpart", "hardlimit for results based on url path", false, &defaultValue);
}

bool QueryServer::InitConfig(){
	log::Logging::SetApplicationName("QueryServer");

	/*
	if( !config.GetValue("hardlimit_meta", queryserverConfig.hardlimit_meta) ) {
		log::Logging::LogInfo("missing hardlimit for meta results in config, defaulting to: &llu",queryserverConfig.hardlimit_meta); }

	if( !config.GetValue("hardlimit_secondleveldomain", queryserverConfig.hardlimit_secondleveldomain) ) {
		log::Logging::LogInfo("missing hardlimit for secondleveldomain results in config, defaulting to: &llu",queryserverConfig.hardlimit_secondleveldomain); }

	if( !config.GetValue("hardlimit_urlpathpart", queryserverConfig.hardlimit_urlpathpart) ) {
		log::Logging::LogInfo("missing hardlimit for urlpathpart results in config, defaulting to: &llu",queryserverConfig.hardlimit_urlpathpart); }
	*/
	return true;
}

fastcgiserver::FastCGIServerThread* QueryServer::CreateThreadPort(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const int port, const int backlog){
	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
				new QueryServerThread(QueryServerThreadConfig(databaseConfig, acceptMutex, xsdRequestContent, xsdResponseContent, port, backlog)));
}

fastcgiserver::FastCGIServerThread* QueryServer::CreateThreadSocket(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog){
/*

	return dynamic_cast<fastcgiserver::FastCGIServerThread*>(
				new QueryServerThread(queryserverConfig, databaseConfig, xsdRequestContent, xsdResponseContent, acceptMutex, filename, backlog));
				*/
	return 0;
}

}
