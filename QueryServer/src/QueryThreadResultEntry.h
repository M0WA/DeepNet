/**
 *
 * @file QueryThreadResultEntry.h
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#pragma once

#include <ctime>
#include <string>
#include <sstream>

#include "Relevance.h"

namespace queryserver {

typedef enum {

	UNKNOWN_RESULT_TYPE = 0,

	CONTENT_RESULT,
	META_RESULT,
	SUBDOMAIN_RESULT,
	SECONDLEVELDOMAIN_RESULT,
	URLPATH_RESULT,

	MAX_RESULT_TYPE,

} QueryThreadResultType;

class QueryThreadResultEntry : public queryserver::Relevance {
public:
	QueryThreadResultEntry(
			const QueryThreadResultType& type,
			const long long& urlID,
			const long long& urlStageID,
			const size_t&    keywordPos,
			const long long& occurences,
			const double&    relevance);

	QueryThreadResultEntry(
			const QueryThreadResultType& type,
			const long long& urlID,
			const long long& urlStageID,
			const size_t&    keywordPos,
			const long long& occurences,
			const double&    relevance,
			const struct tm& found);

	virtual ~QueryThreadResultEntry();

public:
	void AppendToXML(std::ostringstream& xml) const;

public:
	QueryThreadResultType type;
	long long urlID;
	long long urlStageID;
	size_t    keywordPos;
	long long occurences;

	std::string urlDescription;
	std::string urlSummary;

	struct tm found;
};

}
