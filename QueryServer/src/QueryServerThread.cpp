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

QueryServerThread::QueryServerThread(database::DatabaseConfig* databaseConfig, const std::string& requestXSD, const std::string responseXSD, threading::Mutex* acceptMutex, fastcgiserver::FastCGISocket* socket)
: fastcgiserver::FastCGIServerThread(databaseConfig,acceptMutex,socket)
, requestXSD(requestXSD)
, responseXSD(responseXSD)
, threadManager(QueryThreadManager(databaseConfig)){
}

QueryServerThread::~QueryServerThread() {
}

fastcgiserver::FastCGIRequest* QueryServerThread::CreateRequest() {
	return dynamic_cast<fastcgiserver::FastCGIRequest*>(new QueryXmlRequest(dynamic_cast<fastcgiserver::FastCGIServerThread*>(this)));
}

fastcgiserver::FastCGIResponse* QueryServerThread::CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request) {
	return dynamic_cast<fastcgiserver::FastCGIResponse*>(new QueryXmlResponse(threadManager, dynamic_cast<QueryXmlRequest*>(request)));
}

}
