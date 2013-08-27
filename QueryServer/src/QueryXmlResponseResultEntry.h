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

class QueryXmlResponseResultEntry : public queryserver::Relevance {
public:
	QueryXmlResponseResultEntry(const QueryThreadResultEntry* result);
	virtual ~QueryXmlResponseResultEntry();
	bool operator< (const QueryXmlResponseResultEntry& rhs) const;

public:
	void AddResult(const QueryXmlResponseResultEntry& result);
	void AppendToXML(database::DatabaseConnection* db,const Query& query,const size_t resultID,std::ostringstream& xml) const;
	void SortResultsByRelevance();
	const QueryThreadResultEntry* GetMostRelevantResult();

private:
	std::vector<const QueryThreadResultEntry*> threadResults;
	bool isSorted;
};

}

