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
#include <map>

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
 * @brief encapsulates key type for a queryserver::QueryThreadResult
 */
class QueryThreadResultKey{
public:
	bool operator< (const QueryThreadResultKey& rhs) const {
		return
			this->urlId < rhs.urlId &&
			this->urlStageId < rhs.urlStageId;
	}

public:
	long long urlId;
	long long urlStageId;
};

/**
 * @brief encapsulates one result entry from a QueryThread
 */
class QueryThreadResultEntry {

public:
	typedef struct _PointerComparator {
	  bool operator() (const QueryThreadResultEntry* i,const QueryThreadResultEntry* j) const {
		  return i->GetTotalRelevance() < j->GetTotalRelevance(); }
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
	QueryThreadResultEntry(
			const QueryThreadResultType& type,
			const long long& urlID,
			const long long& urlStageID,
			const size_t&    keywordPos,
			const long long& occurrences,
			const double&    relevance);
	 */

	/**
	 * creates a result entry
	 * @param type origin type of this result
	 * @param urlID url id
	 * @param urlStageID url stage id
	 * @param keywordPos position of this keyword in query
	 * @param occurrences position of this keyword in query
	 * @param relevance relevance of this entry
	 * @param found found date of URL
	QueryThreadResultEntry(
			const QueryThreadResultType& type,
			const long long& urlID,
			const long long& urlStageID,
			const size_t&    keywordPos,
			const long long& occurrences,
			const double&    relevance,
			const struct tm& found);
	 */

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

	Relevance GetTotalRelevance() const;

	void AddRelevanceForType(const QueryThreadResultType& type,const Relevance& r);

public:
	static std::string ResultTypeToString(const QueryThreadResultType& type);

public:
	/**
	 * types and their relevances of this result
	 */
	std::map<QueryThreadResultType,Relevance> relevances;

	/**
	 * url id
	 */
	long long urlID;

	/**
	 * url stage id
	 */
	long long urlStageID;

	/**
	 * second level domain id
	 */
	long long secondLvlDomainId;

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
};

}
