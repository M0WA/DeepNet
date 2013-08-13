/**
 *
 * @file QueryXmlResponse.h
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#pragma once

#include <FastCGIResponse.h>

namespace queryserver {

	class QueryThreadManager;
	class QueryXmlRequest;

class QueryXmlResponse: public fastcgiserver::FastCGIResponse {
public:
	QueryXmlResponse(QueryThreadManager& queryManager,QueryXmlRequest* xmlQueryRequest);
	virtual ~QueryXmlResponse();

	virtual bool Process(FCGX_Request& request);

private:
	QueryThreadManager& queryManager;
	const QueryXmlRequest* xmlQueryRequest;
};

}

