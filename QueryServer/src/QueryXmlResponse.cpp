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

#include <CacheDatabaseUrl.h>
#include <DatabaseUrl.h>

namespace queryserver {

QueryXmlResponse::QueryXmlResponse(QueryThreadManager& queryManager,QueryXmlRequest* xmlQueryRequest)
: fastcgiserver::FastCGIResponse(dynamic_cast<fastcgiserver::FastCGIRequest*>(xmlQueryRequest))
, queryManager(queryManager)
, xmlQueryRequest(xmlQueryRequest){
}

QueryXmlResponse::~QueryXmlResponse() {
}

bool QueryXmlResponse::Process(FCGX_Request& request) {

	const Query& query(xmlQueryRequest->GetQuery());
	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	//container for final results
	std::vector<QueryXmlResponseResultEntry> responseEntries;

	//waiting for all results to arrive
	std::vector<const QueryThreadResultEntry*> results;
	queryManager.WaitForResults(results);

	//group results by secondlevel domain or url id
	if(query.properties.groupBySecondLevelDomain) {
		MergeDuplicateSecondLevel(db, results, responseEntries);}
	else {
		MergeDuplicateURLs(results,responseEntries); }

	//sort results
	SortResults(responseEntries);

	//assemble xml response string
	AssembleXMLResult(responseEntries);

	//releasing the query invalidates
	//all pointers to it's results
	results.clear();
	queryManager.ReleaseQuery();

	return FastCGIResponse::Process(request);
}

void QueryXmlResponse::SortResults(std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	//sort response entries by relevance
	std::sort(responseEntries.begin(), responseEntries.end());

	//resorting thread results in each response entry by relevance
	std::vector<QueryXmlResponseResultEntry>::iterator iResort(responseEntries.begin());
	for(;iResort!=responseEntries.end();++iResort) {
		iResort->SortResultsByRelevance(); }
}

void QueryXmlResponse::AssembleXMLResult(const std::vector<QueryXmlResponseResultEntry>& results) {

	const Query& query(xmlQueryRequest->GetQuery());
	database::DatabaseConnection* db(xmlQueryRequest->ServerThread()->DB().Connection());

	//assemble xml entries from results
	std::ostringstream xmlResultEntries;
	std::vector<QueryXmlResponseResultEntry>::const_iterator i(results.begin());
	for(size_t resultID(0);i!=results.end();++i,++resultID) {
		i->AppendToXML(db,query,resultID,xmlResultEntries); }

	//assemble complete xml response including header etc.
	std::ostringstream xmlResult;
	xmlResult <<
		"<?xml version=\"1.0\"?>\n"
		"<response>"
		"<queryId>" << query.queryId << "</queryId>"
		"<pageNo>" << query.pageNo << "</pageNo>"
		"<totalResults>" << results.size() << "</totalResults>" <<
		xmlResultEntries.str() <<
		"</response>\n";

	//set xml string as response's content
	content = xmlResult.str();
}

void QueryXmlResponse::MergeDuplicateSecondLevel(database::DatabaseConnection* db,const std::vector<const QueryThreadResultEntry*>& results, std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	std::map<long long,size_t> secondLvlIDPos;

	std::vector<const QueryThreadResultEntry*>::const_iterator i(results.begin());
	for(size_t pos(0);i!=results.end();++i) {

		tools::Pointer<htmlparser::DatabaseUrl> ptrUrl;
		caching::CacheDatabaseUrl::GetByUrlID(db,(*i)->urlID,ptrUrl);
		long long secondLevelID(ptrUrl.GetConst()->GetSecondLevelID());

		if(secondLvlIDPos.count(secondLevelID) > 0) {
			responseEntries.at(secondLvlIDPos[secondLevelID]).AddResult(*i);
		}
		else {
			responseEntries.push_back(QueryXmlResponseResultEntry(*i));
			secondLvlIDPos[secondLevelID]=pos;
			++pos;
		}
	}
}

void QueryXmlResponse::MergeDuplicateURLs(const std::vector<const QueryThreadResultEntry*>& results,std::vector<QueryXmlResponseResultEntry>& responseEntries) {

	std::map<long long,size_t> urlIDPos;
	std::vector<const QueryThreadResultEntry*>::const_iterator i(results.begin());

	for(size_t pos(0);i!=results.end();++i) {

		const long long& urlID((*i)->urlID);
		if(urlIDPos.count(urlID) > 0) {
			responseEntries.at(urlIDPos[urlID]).AddResult(*i);
		}
		else {
			responseEntries.push_back(QueryXmlResponseResultEntry(*i));
			urlIDPos[urlID]=pos;
			++pos;
		}
	}
}

}
