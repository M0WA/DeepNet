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

namespace database {
	class DatabaseConnection;
}

namespace queryserver {

	class Query;

typedef enum {

	UNKNOWN_RESULT_TYPE = 0,

	CONTENT_RESULT,
	META_RESULT,
	SUBDOMAIN_RESULT,
	SECONDLEVELDOMAIN_RESULT,
	URLPATH_RESULT,

	MAX_RESULT_TYPE,

} QueryThreadResultType;

/**
 * @brief encapsulates one result entry from a QueryThread
 */
class QueryThreadResultEntry {

public:
	typedef struct _PointerComparator {
	  bool operator() (const QueryThreadResultEntry* i,const QueryThreadResultEntry* j) {
		  return i->relevance < j->relevance;
	  }
	} PointerComparator;

public:
	/**
	 * creates a result entry with unknown found date
	 * @param type origin type of this result
	 * @param urlID url id
	 * @param urlStageID url stage id
	 * @param keywordPos position of this keyword in query
	 * @param occurrences position of this keyword in query
	 * @param relevance relevance of this entry
	 */
	QueryThreadResultEntry(
			const QueryThreadResultType& type,
			const long long& urlID,
			const long long& urlStageID,
			const size_t&    keywordPos,
			const long long& occurrences,
			const double&    relevance);

	/**
	 * creates a result entry
	 * @param type origin type of this result
	 * @param urlID url id
	 * @param urlStageID url stage id
	 * @param keywordPos position of this keyword in query
	 * @param occurrences position of this keyword in query
	 * @param relevance relevance of this entry
	 * @param found found date of URL
	 */
	QueryThreadResultEntry(
			const QueryThreadResultType& type,
			const long long& urlID,
			const long long& urlStageID,
			const size_t&    keywordPos,
			const long long& occurrences,
			const double&    relevance,
			const struct tm& found);

	virtual ~QueryThreadResultEntry();

public:
	/**
	 * appends entry to output xml
	 * @param db database connection
	 * @param query original query
	 * @param resultID result id
	 * @param xml stream to append to
	 */
	void AppendToXML(database::DatabaseConnection* db,const Query& query,const size_t resultID,std::ostringstream& xml) const;

public:
	/**
	 * relevance of this result
	 */
	Relevance relevance;

	/**
	 * origin type of this result
	 */
	QueryThreadResultType type;

	/**
	 * url id
	 */
	long long urlID;

	/**
	 * url stage id
	 */
	long long urlStageID;

	/**
	 * position of this keyword in query
	 */
	size_t keywordPos;

	/**
	 * occurrences of this keyword in url
	 */
	long long occurrences;

	/**
	 * description
	 */
	std::string urlDescription;

	/**
	 * summary
	 */
	std::string urlSummary;

	/**
	 * found date of URL
	 */
	struct tm found;

private:
	static std::string ResultTypeToString(const QueryThreadResultType& type);
};

}
