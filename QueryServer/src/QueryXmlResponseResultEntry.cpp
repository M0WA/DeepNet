/**
 *
 * @file QueryXmlResponseResultEntry.cpp
 * @author Moritz Wagner
 * @date 27.08.2013
 *
 */

#include "QueryXmlResponseResultEntry.h"

#include <algorithm>

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

void QueryXmlResponseResultEntry::AddResult(const QueryThreadResultEntry* result) {

	isSorted = false;
	threadResults.push_back(result);
	(*this) += result->relevance;
}

void QueryXmlResponseResultEntry::SortResultsByRelevance(){

	if(!isSorted) {
		QueryThreadResultEntry::PointerComparator relevanceComp;
		std::sort(threadResults.begin(),threadResults.end(), relevanceComp);
		isSorted = true; }
}

void QueryXmlResponseResultEntry::AppendToXML(database::DatabaseConnection* db,const Query& query,const size_t resultID,std::ostringstream& xml) const {

	std::ostringstream alternativeResultPart;
	std::vector<const QueryThreadResultEntry*>::const_iterator iRes(threadResults.begin());
	std::advance(iRes,1);
	for(;iRes != threadResults.end(); ++iRes) {
		const QueryThreadResultEntry* res((*iRes));
		std::string encodedKeyword(query.GetKeywordByPosition(res->keywordPos));
		network::HttpUrlParser::EncodeUrl(encodedKeyword);
		alternativeResultPart << "<alternativeResult><keyword>" << encodedKeyword << "</keyword>";
		res->AppendToXML(db,query,resultID,alternativeResultPart);
		alternativeResultPart << "</alternativeResult>";
	}

	xml <<
	"<result id=\"" << resultID << "\">";

	threadResults.at(0)->AppendToXML(db,query,resultID,xml);

	xml <<
	"<alternativeResults>" << alternativeResultPart.str() << "</alternativeResults>"
	"<keywords><keyword></keyword></keywords>"
	"<relevancyWeighted>" << GetWeightedRelevance() << "</relevancyWeighted>"
	"<relevancy>" << GetRelevance() << "</relevancy>"
	"<weight>" << GetWeight() << "</weight>"
	"</result>";
}

}
