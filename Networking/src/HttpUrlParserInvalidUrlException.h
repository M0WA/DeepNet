/*
 * HttpUrlParserInvalidUrlException.h
 *
 *  Created on: Dec 23, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "HttpUrlParserException.h"

namespace network {

/**
 * @brief exception raised when an invalid url was parsed
 * this exception does NOT log by default
 */
class HttpUrlParserInvalidUrlException : public HttpUrlParserException {
public:
	HttpUrlParserInvalidUrlException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& url,
			const std::string& urlBase,
			const bool logException = false);
	virtual ~HttpUrlParserInvalidUrlException();
};

}
