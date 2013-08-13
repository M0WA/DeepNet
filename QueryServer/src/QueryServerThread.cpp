/**
 *
 * @file QueryServerThread.cpp
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#include "QueryServerThread.h"

#include "QueryXmlRequest.h"
#include "QueryXmlResponse.h"

namespace queryserver {

QueryServerThread::QueryServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, const int port, const int backlog)
: FastCGIServerThread(databaseConfig,acceptMutex,port,backlog)
, requestXSD(requestXSD)
, responseXSD(responseXSD)
, threadManager(QueryThreadManager(databaseConfig)){
}

QueryServerThread::QueryServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, const std::string& filename, const int backlog)
: FastCGIServerThread(databaseConfig,acceptMutex,filename,backlog)
, requestXSD(requestXSD)
, responseXSD(responseXSD)
, threadManager(QueryThreadManager(databaseConfig)) {
}

QueryServerThread::~QueryServerThread() {
}

fastcgiserver::FastCGIRequest* QueryServerThread::CreateRequest() {
	return dynamic_cast<fastcgiserver::FastCGIRequest*>(new QueryXmlRequest(threadManager,dynamic_cast<fastcgiserver::FastCGIServerThread*>(this)));
}

fastcgiserver::FastCGIResponse* QueryServerThread::CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request) {
	return dynamic_cast<fastcgiserver::FastCGIResponse*>(new QueryXmlResponse(threadManager, dynamic_cast<QueryXmlRequest*>(request)));
}

}
