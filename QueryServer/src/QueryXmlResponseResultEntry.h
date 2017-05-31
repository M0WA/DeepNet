/**
 *
 * @file QueryXmlResponseResultEntry.h
 * @author Moritz Wagner
 * @date 27.08.2013
 *
 */

#pragma once

#include <sstream>
#include <vector>

#include "Relevance.h"

namespace database {
	class DatabaseConnection;
}

namespace queryserver {

	class Query;
	class QueryThreadResultEntry;

/**
 * @brief encapsulates a single result for the query which may contain multiple matches ( queryserver::QueryThreadResultEntry )
 */
class QueryXmlResponseResultEntry : public queryserver::Relevance {
public:
	typedef enum _RESULTINFO_TYPE {

		RESULTINFO_INVALID    = -1,

		RESULTINFO_TYPECOUNT  = 0,
		RESULTINFO_RELEVANCY  = 1,
		RESULTINFO_WRELEVANCY = 2,
		RESULTINFO_WEIGHT     = 3,

		RESULTINFO_MAX

	} RESULTINFO_TYPE;

public:
	QueryXmlResponseResultEntry(const QueryThreadResultEntry* result);
	virtual ~QueryXmlResponseResultEntry();
	bool operator< (const QueryXmlResponseResultEntry& rhs) const;

public:
	/**
	 * add/merge a result to this entry
	 * @param result result to add/merge
	 */
	void AddResult(const QueryThreadResultEntry* result);

	/**
	 * add/merge a result to this entry
	 * @param result result to add/merge
	 */
	void AddResult(const QueryXmlResponseResultEntry& result);

	/**
	 * insert this result to a database
	 * @param db database connection
	 * @param queryId associated query id
	 * @param position position
	 */
	void Insert(database::DatabaseConnection* db,const long long& queryId,const size_t& position) const;

	/**
	 * gets urlID for this result
	 */
	long long GetUrlID() const;

public:
	static bool ParseTypeCount(const std::string& parse, std::string& type, size_t& count);

private:
	std::vector<const QueryThreadResultEntry*> threadResults;
};

}

