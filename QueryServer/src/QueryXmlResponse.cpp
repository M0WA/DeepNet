/**
 *
 * @file QueryXmlResponse.cpp
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#include "QueryXmlResponse.h"

#include <algorithm>
#include <sstream>

#include "QueryXmlRequest.h"
#include "QueryThreadResultEntry.h"
#include "QueryThreadManager.h"
#include "Relevance.h"

#include <FastCGIRequest.h>
#include <FastCGIServerThread.h>

namespace queryserver {

QueryXmlResponse::QueryXmlResponse(QueryThreadManager& queryManager,QueryXmlRequest* xmlQueryRequest)
: fastcgiserver::FastCGIResponse(dynamic_cast<fastcgiserver::FastCGIRequest*>(xmlQueryRequest))
, queryManager(queryManager)
, xmlQueryRequest(xmlQueryRequest){
}

QueryXmlResponse::~QueryXmlResponse() {
}

bool QueryXmlResponse::Process(FCGX_Request& request) {

	//waiting for all results to arrive
	std::vector<const QueryThreadResultEntry*> results;
	queryManager.WaitForResults(results);

	//sorting results
	Relevance::RelevancePointerComparator comp;
	std::sort(results.begin(),results.end(), comp);

	//assemble xml response string
	AssembleXMLResult(results);

	//releasing the query invalidates
	//all pointers to it's results
	results.clear();
	queryManager.ReleaseQuery();

	return FastCGIResponse::Process(request);
}

void QueryXmlResponse::AssembleXMLResult(const std::vector<const QueryThreadResultEntry*>& results) {

	//assemble xml entries from results
	std::ostringstream xmlResultEntries;
	std::vector<const QueryThreadResultEntry*>::const_iterator i(results.begin());
	for(size_t resultID(0);i!=results.end();++i,++resultID) {
		(*i)->AppendToXML(xmlQueryRequest->ServerThread()->DB().Connection(),resultID,xmlResultEntries); }

	//assemble complete xml response including header etc.
	std::ostringstream xmlResult;
	xmlResult <<
		"<?xml version=\"1.0\"?>\n"
		"<response>"
		"<queryId>" << xmlQueryRequest->GetQuery().queryId << "</queryId>"
		"<pageNo>" << xmlQueryRequest->GetQuery().pageNo << "</pageNo>"
		"<totalResults>" << results.size() << "</totalResults>" <<
		xmlResultEntries.str() <<
		"</response>\n";

	//set xml string as response's content
	content = xmlResult.str();
}

}
