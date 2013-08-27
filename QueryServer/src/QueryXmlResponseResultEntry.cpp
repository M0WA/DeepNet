/**
 *
 * @file QueryXmlResponseResultEntry.cpp
 * @author Moritz Wagner
 * @date 27.08.2013
 *
 */

#include "QueryXmlResponseResultEntry.h"

#include <algorithm>
#include <map>

#include <HttpUrlParser.h>

#include "Query.h"
#include "QueryThreadResultEntry.h"

namespace queryserver {

QueryXmlResponseResultEntry::QueryXmlResponseResultEntry(const QueryThreadResultEntry* result)
: queryserver::Relevance(result->relevance)
, isSorted(true) {
	threadResults.push_back(result);
}

QueryXmlResponseResultEntry::~QueryXmlResponseResultEntry() {
}

bool QueryXmlResponseResultEntry::operator< (const QueryXmlResponseResultEntry& rhs) const {

	return dynamic_cast<const Relevance&>(*this) < dynamic_cast<const Relevance&>(rhs);
}

void QueryXmlResponseResultEntry::AddResult(const QueryXmlResponseResultEntry& result) {

	isSorted = false;

	threadResults.insert(threadResults.end(),result.threadResults.begin(),result.threadResults.end());

	(*this) += dynamic_cast<const Relevance&>(result);
}

void QueryXmlResponseResultEntry::SortResultsByRelevance(){

	if(!isSorted) {
		QueryThreadResultEntry::PointerComparator relevanceComp;
		std::sort(threadResults.begin(),threadResults.end(), relevanceComp);
		isSorted = true; }
}

const QueryThreadResultEntry* QueryXmlResponseResultEntry::GetMostRelevantResult() {

	SortResultsByRelevance();
	return threadResults.at(0);
}

void QueryXmlResponseResultEntry::AppendToXML(database::DatabaseConnection* db,const Query& query,const size_t resultID,std::ostringstream& xml) const {

	std::map<QueryThreadResultType,size_t> typeCounts;
	typeCounts[threadResults.at(0)->type]++;

	std::ostringstream keywordsPart;
	std::vector<const QueryThreadResultEntry*>::const_iterator iRes(threadResults.begin());
	std::advance(iRes,1);
	for(;iRes != threadResults.end(); ++iRes) {
		const QueryThreadResultEntry* res((*iRes));

		typeCounts[res->type]++;

		std::string encodedKeyword(query.GetKeywordByPosition(res->keywordPos));
		network::HttpUrlParser::EncodeUrl(encodedKeyword);
		keywordsPart << "<keyword>" << encodedKeyword << "</keyword>";
	}

	std::ostringstream typesPart;
	std::map<QueryThreadResultType,size_t>::const_iterator iTypes(typeCounts.begin());
	for(;iTypes!= typeCounts.end();++iTypes) {
		typesPart << "<type count=\""<< iTypes->second << "\">" << QueryThreadResultEntry::ResultTypeToString(iTypes->first) << "</type>";}

	xml <<
	"<result id=\"" << resultID << "\">";

	threadResults.at(0)->AppendToXML(db,query,resultID,xml);

	xml <<
	"<types>" << typesPart.str() << "</types>"
	"<keywords>" << keywordsPart.str() << "</keywords>"
	"<relevancyWeighted>" << GetWeightedRelevance() << "</relevancyWeighted>"
	"<relevancy>" << GetRelevance() << "</relevancy>"
	"<weight>" << GetWeight() << "</weight>"
	"</result>";
}

}
