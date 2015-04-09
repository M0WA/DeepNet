/**
 * @file QueryResultXmlRequest.h
 * @author Moritz Wagner
 * @date Apr 7, 2015
 */

#pragma once

#include "FastCGIRequest.h"

namespace fastcgiserver {
	class FastCGIServerThread;
}

namespace queryserver {

/**
 * @brief encapsulates a xml query result request and also implements fastcgiserver::FastCGIRequest
 */
class QueryResultXmlRequest : public fastcgiserver::FastCGIRequest {
public:
	QueryResultXmlRequest(fastcgiserver::FastCGIServerThread* serverThread);
	virtual ~QueryResultXmlRequest();

public:
	long long QueryID() const { return queryId; }
	long long PageNo() const { return pageNo; }
	long long MaxResults() const { return maxResults; }

private:
	virtual void OnHandle(FCGX_Request& request);

private:
	long long queryId;
	long long pageNo;
	long long maxResults;
};

}
