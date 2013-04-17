/*
 * HttpUrlParserInvalidUrlException.h
 *
 *  Created on: Dec 23, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "HttpUrlParserException.h"

namespace network {

class HttpUrlParserInvalidUrlException : public HttpUrlParserException {
public:
	HttpUrlParserInvalidUrlException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& url,
			const std::string& urlBase);
	virtual ~HttpUrlParserInvalidUrlException();
};

}
