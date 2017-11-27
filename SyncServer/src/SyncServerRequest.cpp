/*
 * @file SyncServerRequest.cpp
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#include "SyncServerRequest.h"

#include <Logging.h>

namespace syncserver {

SyncServerRequest::SyncServerRequest(fastcgiserver::FastCGIServerThread* serverThread)
: fastcgiserver::FastCGIRequest(serverThread) {
}

SyncServerRequest::~SyncServerRequest() {
}

void SyncServerRequest::OnHandle(FCGX_Request& request)
{
	if(rawPostData==0) {
		log::Logging::LogWarn("no post data received, ommitting...");
		return;	}

    std::list<std::string> crawlerid;
	if( !Xpath(crawlerid, rawPostData, (xmlChar*)"/request/crawlerid/text()")) {
		log::Logging::LogError("could not parse xml crawler request");
		return; }
}

}
