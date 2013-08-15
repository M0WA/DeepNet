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

	//waiting for all results to arrive
	std::vector<const QueryThreadResultEntry*> results;
	queryManager.WaitForResults(results);

	//sorting all results by relevance
	Relevance::RelevancePointerComparator relevanceComp;
	std::sort(results.begin(),results.end(), relevanceComp);

	//merging duplicates
	MergeDuplicates(results);

	//group results
	if(query.properties.groupBySecondLevelDomain) {
		std::vector< std::vector<const QueryThreadResultEntry*> > groupedResults;

		SecondLevelDomainGroupByFunc groupBy(db,groupedResults);
		std::for_each(results.begin(),results.end(), groupBy);

		SelectFirstGroupedResultsFunc firstGroup(results);
		std::for_each(groupedResults.begin(),groupedResults.end(), firstGroup);
	}

	//assemble xml response string
	AssembleXMLResult(results);

	//releasing the query invalidates
	//all pointers to it's results
	results.clear();
	queryManager.ReleaseQuery();

	return FastCGIResponse::Process(request);
}

void QueryXmlResponse::AssembleXMLResult(const std::vector<const QueryThreadResultEntry*>& results) {

	const Query& query(xmlQueryRequest->GetQuery());

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
		"<queryId>" << query.queryId << "</queryId>"
		"<pageNo>" << query.pageNo << "</pageNo>"
		"<totalResults>" << results.size() << "</totalResults>" <<
		xmlResultEntries.str() <<
		"</response>\n";

	//set xml string as response's content
	content = xmlResult.str();
}

void QueryXmlResponse::MergeDuplicates(std::vector<const QueryThreadResultEntry*>& results) {

	std::map<long long,size_t> urlIDPos;
	std::vector<const QueryThreadResultEntry*>::iterator i(results.begin());
	for(size_t pos(0);i!=results.end();++i,++pos) {

		const long long& urlID((*i)->urlID);
		if(urlIDPos.count(urlID) > 0) {
			size_t pos(urlIDPos[urlID]);
			const QueryThreadResultEntry* entryAtPos(results.at(pos));
			const Relevance
				*rLeft(dynamic_cast<const Relevance*>(entryAtPos)),
				*rRight(dynamic_cast<const Relevance*>(*i));
			(*rLeft) += (*rRight);
			results.erase(i);
			i--;
			pos--;
		}
		else {
			urlIDPos[urlID]=pos;
		}
	}
}

QueryXmlResponse::SecondLevelDomainGroupByFunc::SecondLevelDomainGroupByFunc(database::DatabaseConnection* db,std::vector< std::vector<const QueryThreadResultEntry*> >& groupedResults)
: db(db)
, groupedResults(groupedResults) {
}

bool QueryXmlResponse::SecondLevelDomainGroupByFunc::operator() (const QueryThreadResultEntry*& entry) {

	tools::Pointer<htmlparser::DatabaseUrl> ptrUrl;
	caching::CacheDatabaseUrl::GetByUrlID(db,entry->urlID,ptrUrl);
	long long secondLevelID(ptrUrl.GetConst()->GetSecondLevelID());

	size_t pos(0);
	if(mapSecondlevelDomainPos.count(secondLevelID) > 0) {
		pos = mapSecondlevelDomainPos[secondLevelID]; }
	else {
		pos = mapSecondlevelDomainPos[secondLevelID] = groupedResults.size();
		groupedResults.push_back(std::vector<const QueryThreadResultEntry*>());	}

	groupedResults.at(pos).push_back(entry);
	return true;
}

QueryXmlResponse::SelectFirstGroupedResultsFunc::SelectFirstGroupedResultsFunc(std::vector<const QueryThreadResultEntry*>& results)
: results(results) {
	results.clear();
}

bool QueryXmlResponse::SelectFirstGroupedResultsFunc::operator() (const std::vector<const QueryThreadResultEntry*>& entry) {
	if(entry.size()) {
		results.push_back(entry.at(0));
	}
	return true;
}

}
