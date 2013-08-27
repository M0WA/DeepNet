/**
 *
 * @file QueryXmlResponse.h
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#pragma once

#include <vector>
#include <map>

#include "QueryXmlResponseResultEntry.h"

#include <FastCGIResponse.h>

namespace database {
	class DatabaseConnection;
}

namespace queryserver {

	class QueryThreadManager;
	class QueryXmlRequest;
	class QueryThreadResultEntry;

/**
 * @brief encapsulates a xml query request
 */
class QueryXmlResponse: public fastcgiserver::FastCGIResponse {
public:
	QueryXmlResponse(QueryThreadManager& queryManager,QueryXmlRequest* xmlQueryRequest);
	virtual ~QueryXmlResponse();

private:
	virtual bool Process(FCGX_Request& request);

private:
	void AssembleXMLResult(const std::vector<QueryXmlResponseResultEntry>& results);
	void MergeDuplicateURLs(std::vector<QueryXmlResponseResultEntry>& responseEntries);
	void MergeDuplicateSecondLevel(database::DatabaseConnection* db, std::vector<QueryXmlResponseResultEntry>& responseEntries);
	void SortResults(std::vector<QueryXmlResponseResultEntry>& responseEntries);

private:
	QueryThreadManager& queryManager;
	QueryXmlRequest* xmlQueryRequest;
};

}

