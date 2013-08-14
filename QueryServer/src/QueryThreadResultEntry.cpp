/**
 *
 * @file QueryThreadResultEntry.cpp
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#include "QueryThreadResultEntry.h"

#include <StringTools.h>
#include <TimeTools.h>
#include <Pointer.h>

#include <DatabaseLayer.h>
#include <CacheDatabaseUrl.h>
#include <DatabaseUrl.h>
#include <HttpUrlParser.h>

namespace queryserver {

QueryThreadResultEntry::QueryThreadResultEntry(
	const QueryThreadResultType& type,
	const long long& urlID,
	const long long& urlStageID,
	const size_t&    keywordPos,
	const long long& occurences,
	const double&    relevance)
: queryserver::Relevance(relevance)
, type(type)
, urlID(urlID)
, urlStageID(urlStageID)
, keywordPos(keywordPos)
, occurences(occurences){
	tools::TimeTools::InitTm(found);
}

QueryThreadResultEntry::QueryThreadResultEntry(
	const QueryThreadResultType& type,
	const long long& urlID,
	const long long& urlStageID,
	const size_t&    keywordPos,
	const long long& occurences,
	const double&    relevance,
	const struct tm& found)
: queryserver::Relevance(relevance)
, type(type)
, urlID(urlID)
, urlStageID(urlStageID)
, keywordPos(keywordPos)
, occurences(occurences)
, found(found){
}

QueryThreadResultEntry::~QueryThreadResultEntry() {
}

void QueryThreadResultEntry::AppendToXML(database::DatabaseConnection* db,const size_t resultID,std::ostringstream& xml) const {

	tools::Pointer<htmlparser::DatabaseUrl> dbUrl;
	caching::CacheDatabaseUrl::GetByUrlID(db,urlID,dbUrl);

	std::string encodedURL(dbUrl.GetConst()->GetFullUrl());
	network::HttpUrlParser::EncodeUrl(encodedURL);

	std::string
			lastVisitedString(tools::TimeTools::DumpTm(found)),
			encodedTitle,
			encodedDescription,
			dumpEncoded;

	xml <<
	"<result id=\"" << resultID << "\">"
	"<url id=\"" << urlID << "\">" << encodedURL << "</url>"
	"<title>" << encodedTitle << "</title>"
	"<description>" << encodedDescription << "</description>"
	"<lastVisited>" << lastVisitedString << "</lastVisited>"
	"<lastChanged></lastChanged>"
	"<keywords>" << dumpEncoded << "</keywords>"
	"<relevancyWeighted>" << GetWeightedRelevance() << "</relevancyWeighted>\n"
	"<relevancy>" << GetRelevance() << "</relevancy>\n"
	"<weight>" << GetWeight() << "</weight>\n"
	"</result>";
}

}
