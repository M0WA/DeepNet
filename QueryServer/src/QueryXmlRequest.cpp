/**
 *
 * @file QueryXmlRequest.cpp
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#include "QueryXmlRequest.h"

#include "QueryFactory.h"

#include <FastCGIServerThread.h>
#include <Logging.h>
#include <InvalidOperationException.h>

#include <string>

namespace queryserver {

QueryXmlRequest::QueryXmlRequest(fastcgiserver::FastCGIServerThread* serverThread)
: fastcgiserver::FastCGIRequest(serverThread){
}

QueryXmlRequest::~QueryXmlRequest() {
}

queryserver::Query& QueryXmlRequest::GetQuery(void) {
	if(queryPtr.IsNull()) {
		THROW_EXCEPTION(errors::InvalidOperationException,"queryserver::QueryXmlRequest::GetQuery");	}
	return reinterpret_cast<queryserver::Query&>(*(queryPtr.Get()));
}

void QueryXmlRequest::OnHandle(FCGX_Request& request) {

	if(rawPostData==0) {
		log::Logging::LogWarn("no post data received, ommitting...");
		return;	}

	//
	//TODO: need to make this better => buffer overflow ???
	//
	std::string xml = static_cast<const char*>(rawPostData);

	queryserver::QueryFactory fact;
	if( !fact.CreateQueryFromXML(xml, queryPtr) ) {
		queryPtr.Release();
		log::Logging::LogWarn("invalid post data received, ommitting...");
		return;	}
}

}
