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

}
