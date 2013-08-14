/**
 *
 * @file QueryThreadResultEntry.cpp
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#include "QueryThreadResultEntry.h"

#include <TimeTools.h>

namespace queryserver {

QueryThreadResultEntry::QueryThreadResultEntry(
	const QueryThreadResultType& type,
	const long long& urlID,
	const long long& urlStageID,
	const long long& keywordID,
	const long long& occurences,
	const double&    relevance)
: queryserver::Relevance(relevance)
, type(type)
, urlID(urlID)
, urlStageID(urlStageID)
, keywordID(keywordID)
, occurences(occurences){
	tools::TimeTools::InitTm(found);
}

QueryThreadResultEntry::QueryThreadResultEntry(
	const QueryThreadResultType& type,
	const long long& urlID,
	const long long& urlStageID,
	const long long& keywordID,
	const long long& occurences,
	const double&    relevance,
	const struct tm& found)
: queryserver::Relevance(relevance)
, type(type)
, urlID(urlID)
, urlStageID(urlStageID)
, keywordID(keywordID)
, occurences(occurences)
, found(found){
}

QueryThreadResultEntry::~QueryThreadResultEntry() {
}

void QueryThreadResultEntry::AppendToXML(std::ostringstream& xml) const {
/*
	xml <<
	"<result id=\"" << i << "\">"
	"<url id=\"" << urlID << "\">" << encodedURL << "</url>"
	"<title>" << encodedTitle << "</title>"
	"<description>" << encodedDescription << "</description>"
	"<lastVisited>" << lastVisitedString << "</lastVisited>"
	"<lastChanged>" << lastChangedString << "</lastChanged>"
	"<keywords>" << dumpEncoded << "</keywords>"
//		"\t<relevancyWeighted>" << urlStageEntry.GetTotalRelevance().GetWeightedRelevance() << "</relevancyWeighted>\n"
//		"\t<relevancy>" << urlStageEntry.GetTotalRelevance().GetRelevance() << "</relevancy>\n"
//		"\t<weight>" << urlStageEntry.GetTotalRelevance().GetWeight() << "</weight>\n"
	"</result>";
*/
}

}
