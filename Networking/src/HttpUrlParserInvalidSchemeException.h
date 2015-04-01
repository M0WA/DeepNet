/*
 * URLInvalidSchemeException.h
 *
 *  Created on: 22.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "HttpUrlParserException.h"

namespace network {

class HttpUrlParserInvalidSchemeException: public HttpUrlParserException {
public:
	HttpUrlParserInvalidSchemeException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& url);
	virtual ~HttpUrlParserInvalidSchemeException();
};

}
