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
	class queryresultsTableBase;
	template <class T> class  SelectResultContainer;

}

namespace queryserver {

	class QueryXmlRequest;
	class QueryThreadResultEntry;

/**
 * @brief encapsulates a xml query request and also implements fastcgiserver::FastCGIResponse
 */
class QueryXmlResponse : public fastcgiserver::FastCGIResponse {
public:
	QueryXmlResponse(
		QueryXmlRequest* xmlQueryRequest);

	virtual ~QueryXmlResponse();

private:
	virtual bool Process(FCGX_Request& request);

private:
	bool GetSimilarQuery(
		long long& queryId,
		const std::string& sessionID);

	bool AssembleResponse(
		const long long& relevantQueryID);

	bool ValidateQueryData(
		const std::string& sessionID,
		const std::string& rawQueryString);

	void InsertQuery(
		long long& queryId,
		const std::string& sessionID,
		const std::string& rawQueryString);

private:
	QueryXmlRequest* xmlQueryRequest;
};

}

