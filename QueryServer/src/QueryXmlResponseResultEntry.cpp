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
#include <ContainerTools.h>

#include "Query.h"
#include "QueryThreadResultEntry.h"

namespace queryserver {

QueryXmlResponseResultEntry::QueryXmlResponseResultEntry(const QueryThreadResultEntry* result)
: queryserver::Relevance(result->relevance) {
	threadResults.push_back(result);
}

QueryXmlResponseResultEntry::~QueryXmlResponseResultEntry() {
}

bool QueryXmlResponseResultEntry::operator< (const QueryXmlResponseResultEntry& rhs) const {

	return dynamic_cast<const Relevance&>(*this) < dynamic_cast<const Relevance&>(rhs);
}

void QueryXmlResponseResultEntry::AddResult(const QueryXmlResponseResultEntry& result) {

	threadResults.insert(threadResults.end(),result.threadResults.begin(),result.threadResults.end());

	(*this) += dynamic_cast<const Relevance&>(result);
}

void QueryXmlResponseResultEntry::AddResult(const QueryThreadResultEntry* result) {

	threadResults.push_back(result);

	(*this) += dynamic_cast<const Relevance&>(*result);
}

void QueryXmlResponseResultEntry::AppendToXML(database::DatabaseConnection* db,const Query& query,const size_t resultID,std::ostringstream& xml) const {

	std::vector<std::string> keywordsStrings;
	query.GetKeywords(keywordsStrings);
	tools::ContainerTools::MakeUniqueVector(keywordsStrings,true);

	std::ostringstream keywordsPart;
	std::vector<std::string>::iterator iKey(keywordsStrings.begin());
	for(;iKey!=keywordsStrings.end();++iKey) {
		network::HttpUrlParser::EncodeUrl(*iKey);
		keywordsPart << "<keyword>" << *iKey << "</keyword>"; }

	std::map<QueryThreadResultType,size_t> typeCounts;
	std::vector<const QueryThreadResultEntry*>::const_iterator iRes(threadResults.begin());
	for(;iRes != threadResults.end(); ++iRes) {
		const QueryThreadResultEntry* res((*iRes));
		typeCounts[res->type]++; }

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

long long QueryXmlResponseResultEntry::GetUrlID() const {

	return threadResults.at(0)->urlID;
}

}
