/* *
 * @file QueryServer.cpp
 * @author Moritz Wagner
 * @date 10.01.2015
 */

#include "QueryServer.h"

namespace queryserver {

QueryServer::QueryServer() {
}

QueryServer::~QueryServer() {
}

bool QueryServer::StartServer(int argc, char** argv){
	return false;
}

void QueryServer::RegisterConfig(){
}

bool QueryServer::InitConfig(){
	return false;
}

fastcgiserver::FastCGIServerThread* QueryServer::CreateThreadPort(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const int port, const int backlog){
	return 0;
}

fastcgiserver::FastCGIServerThread* QueryServer::CreateThreadSocket(database::DatabaseConfig* databaseConfig, threading::Mutex* acceptMutex, const std::string& filename, const int backlog){
	return 0;
}

}
