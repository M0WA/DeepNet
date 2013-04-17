/*
 * SuggestServerRequest.cpp
 *
 *  Created on: 12.06.2012
 *      Author: Moritz Wagner
 */

#include "SuggestServerRequest.h"
#include <Logging.h>

namespace suggestserver {

SuggestServerRequest::SuggestServerRequest(fastcgiserver::FastCGIServerThread* serverThread)
: fastcgiserver::FastCGIRequest(serverThread)
{
}

SuggestServerRequest::~SuggestServerRequest()
{
}

void SuggestServerRequest::OnHandle(FCGX_Request& request)
{
	if(rawPostData==0) {
		log::Logging::Log(log::Logging::LOGLEVEL_WARN,"no post data received, ommitting...");
		return;	}

	if( !Xpath(queryParts, rawPostData, (xmlChar*)"/request/query/querypart/text()")) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR, "could not parse xml suggest request");
		return; }
}

}
