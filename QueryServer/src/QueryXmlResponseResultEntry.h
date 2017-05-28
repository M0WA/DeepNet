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
	 * appends this result as XML string to given stream xml
	 * @param db database connection
	 * @param query associated query
	 * @param resultID result id
	 * @param xml stream to write to
	 */
	void AppendToXML(database::DatabaseConnection* db,const Query& query,const size_t resultID,std::ostringstream& xml) const;

	/**
	 * gets urlID for this result
	 */
	long long GetUrlID() const;

private:
	std::vector<const QueryThreadResultEntry*> threadResults;
	bool isSorted;
};

}

