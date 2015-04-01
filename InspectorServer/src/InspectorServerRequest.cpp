/*
 * InspectorServerRequest.cpp
 *
 *  Created on: 06.05.2012
 *      Author: Moritz Wagner
 */

#include "InspectorServerRequest.h"

#include <Logging.h>

namespace inspectorserver {

InspectorServerRequest::InspectorServerRequest(fastcgiserver::FastCGIServerThread* serverThread)
: fastcgiserver::FastCGIRequest(serverThread)
{
}

InspectorServerRequest::~InspectorServerRequest()
{
}

void InspectorServerRequest::OnHandle(FCGX_Request& request)
{
	if(rawPostData==0) {
		log::Logging::LogWarn("no post data received, ommitting...");
		return;	}

	if( !Xpath(htmlCodes, rawPostData, (xmlChar*)"/request/inspect/text()")){
		log::Logging::LogError("could not parse xml inspect request");
		return; }
}

}
