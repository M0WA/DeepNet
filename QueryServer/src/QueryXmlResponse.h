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
	class searchqueryresultTableBase;
	template <class T> class  SelectResultContainer;
}

namespace queryserver {

	class QueryThreadManager;
	class QueryXmlRequest;
	class QueryThreadResultEntry;

/**
 * @brief encapsulates a xml query request and also implements fastcgiserver::FastCGIResponse
 */
class QueryXmlResponse: public fastcgiserver::FastCGIResponse {
public:
	QueryXmlResponse(
		QueryThreadManager& queryManager,
		QueryXmlRequest* xmlQueryRequest);

	virtual ~QueryXmlResponse();

private:
	virtual bool Process(FCGX_Request& request);

private:
	bool LoadQuery(
		const long long& queryId,
		const std::string& sessionID,
		const std::string& rawQueryString);

	bool CreateQuery(
		long long& queryId,
		const std::string& sessionID,
		const std::string& rawQueryString);

	void MergeDuplicateURLs(
		const std::vector<const QueryThreadResultEntry*>& threadResults,
		std::vector<QueryXmlResponseResultEntry>& responseEntries);

	void MergeDuplicateSecondLevel(
		std::vector<QueryXmlResponseResultEntry>& responseEntries);

	void SortResults(
		std::vector<QueryXmlResponseResultEntry>& responseEntries);

	void InsertResults(
		long long& queryId,
		const std::string& sessionID,
		const std::string& rawQueryString,
		const std::vector<QueryXmlResponseResultEntry>& responseEntries);

	bool ResultToXML(
		const database::searchqueryresultTableBase* curTbl,
		std::string& entryXML);

	void AssembleXMLResult(
		const database::SelectResultContainer<database::searchqueryresultTableBase>& queryResults,
		const size_t& total,
		const long long& queryId);

	bool ValidateQueryData(
		const std::string& sessionID,
		const std::string& rawQueryString);

private:
	QueryThreadManager& queryManager;
	QueryXmlRequest* xmlQueryRequest;
};

}

