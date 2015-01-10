/**
 *
 * @file QueryXmlRequest.h
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#pragma once

#include "Query.h"

#include <FastCGIRequest.h>
#include <Pointer.h>

namespace queryserver {

class QueryServerThread;

/**
 * @brief encapsulates a xml query request and also implements fastcgiserver::FastCGIRequest
 */
class QueryXmlRequest: public fastcgiserver::FastCGIRequest {

public:
	/**
	 * creates from QueryThreadManager and FastCGIServerThread
	 * @param serverThread server thread
	 */
	QueryXmlRequest(QueryServerThread* serverThread);
	virtual ~QueryXmlRequest();

public:
	/**
	 * gets query associated with this request
	 * @return query
	 */
	queryserver::Query& GetQuery(void);

private:
	virtual void OnHandle(FCGX_Request& request);


private:
	tools::Pointer<queryserver::Query> queryPtr;
};

}

