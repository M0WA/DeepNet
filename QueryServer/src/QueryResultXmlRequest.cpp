/**
 * @file QueryResultXmlRequest.cpp
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#include "QueryResultXmlRequest.h"

#include <XmlTools.h>
#include <XmlDocument.h>
#include <Logging.h>

namespace queryserver {

QueryResultXmlRequest::QueryResultXmlRequest(fastcgiserver::FastCGIServerThread* serverThread)
: fastcgiserver::FastCGIRequest(serverThread)
, queryId(-1)
, pageNo(-1)
, maxResults(-1){
}

QueryResultXmlRequest::~QueryResultXmlRequest() {
}

void QueryResultXmlRequest::OnHandle(FCGX_Request& request) {

	if(rawPostData==0) {
		log::Logging::LogWarn("no post data received, ommitting...");
		return;	}

	tools::Pointer<tools::XmlDocument> pDoc;
	if(!tools::XmlTools::CreateDocument(rawPostData,strlen(rawPostData),pDoc)) {
		log::Logging::LogWarn("invalid post data received, ommitting...");
		log::Logging::LogTrace(rawPostData);
		return; }

	pDoc.Get()->XPathSingle("/request/queryresult/queryId/text()",queryId);
	pDoc.Get()->XPathSingle("/request/queryresult/pageNo/text()",pageNo);
	pDoc.Get()->XPathSingle("/request/queryresult/maxResults/text()",maxResults);
}

}
