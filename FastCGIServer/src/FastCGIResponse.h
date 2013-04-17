/**
 * @file FastCGIResponse.h
 * @author Moritz Wagner
 * @date 16.03.2012
 */

#pragma once

#include "FastCGIRequest.h"
#include "HttpHeader.h"

namespace fastcgiserver {

/**
 * @brief container for a fastcgi server response.
 */
class FastCGIResponse {
public:
	/**
	 * constructs response.
	 * @param fcgiRequest corresponding request.
	 */
	FastCGIResponse(FastCGIRequest* fcgiRequest);
	virtual ~FastCGIResponse();

public:
	/**
	 * processes fastcgi client request.
	 * @param request corresponding request.
	 * @return false on error, true on success.
	 */
	virtual bool Process(FCGX_Request& request);

	/**
	 * converts request to string
	 * @return request string.
	 */
	std::string ToString() { return (header.ToString(content.size()) + content); }

protected:
	/**
	 * corresponding request.
	 */
	FastCGIRequest* fcgiRequest;

	/**
	 * response header.
	 */
	HttpHeader header;

	/**
	 * content of response.
	 */
	std::string content;
};

}
