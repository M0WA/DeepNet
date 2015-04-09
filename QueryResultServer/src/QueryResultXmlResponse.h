/**
 * @file QueryResultXmlResponse.h
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#pragma once

#include <FastCGIResponse.h>

namespace database {
	class DatabaseConnection;
	class queryresultsTableBase;
	template <class T> class  SelectResultContainer;
}

namespace queryserver {

class QueryResultXmlRequest;

/**
 * @brief encapsulates a xml query request and also implements fastcgiserver::FastCGIResponse
 */
class QueryResultXmlResponse : public fastcgiserver::FastCGIResponse {
public:
	QueryResultXmlResponse(QueryResultXmlRequest* xmlQueryResultRequest);
	virtual ~QueryResultXmlResponse();

private:
	virtual bool Process(FCGX_Request& request);

private:
	void AssembleXMLResult(
			const database::SelectResultContainer<database::queryresultsTableBase>& queryResults,
			const size_t& total,
			const long long& queryId,
			const long long& pageNo);

	bool LoadQuery(
			const long long& queryId,
			const std::string& sessionID,
			long long& total,
			long long& finished);

	bool LoadResults(
			database::SelectResultContainer<database::queryresultsTableBase>& queryResults,
			const long long& queryId,
			const long long& pageNo,
			const long long& maxResults);
private:
	QueryResultXmlRequest* xmlQueryResultRequest;
};

}
