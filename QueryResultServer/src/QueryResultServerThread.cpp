/**
 * @file QueryResultServerThread.cpp
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#include "QueryResultServerThread.h"

#include "QueryResultXmlRequest.h"
#include "QueryResultXmlResponse.h"

namespace queryserver {

QueryResultServerThread::QueryResultServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex,socket) {
}

QueryResultServerThread::~QueryResultServerThread() {
}

fastcgiserver::FastCGIRequest*  QueryResultServerThread::CreateRequest() {
	return dynamic_cast<fastcgiserver::FastCGIRequest*>(new QueryResultXmlRequest(dynamic_cast<fastcgiserver::FastCGIServerThread*>(this)));
}

fastcgiserver::FastCGIResponse* QueryResultServerThread::CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request) {
	return dynamic_cast<fastcgiserver::FastCGIResponse*>(new QueryResultXmlResponse(dynamic_cast<QueryResultXmlRequest*>(request)));
}

}
