/*
 * UrlParserEncodeException.h
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "HttpUrlParserException.h"

namespace network {

class HttpUrlParserEncodeException: public HttpUrlParserException {
public:
	HttpUrlParserEncodeException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& url);
	virtual ~HttpUrlParserEncodeException();
};

}
