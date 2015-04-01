/*
 * HttpUrlParserInvalidUrlException.cpp
 *
 *  Created on: Dec 23, 2012
 *      Author: Moritz Wagner
 */

#include "HttpUrlParserInvalidUrlException.h"

namespace network {

HttpUrlParserInvalidUrlException::HttpUrlParserInvalidUrlException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& url,
		const std::string& urlBase,
		const bool logException)
: HttpUrlParserException(file,line,function,"HttpUrlParserInvalidUrlException", "cannot parse url:\n" + url + "\nbaseUrl: " + urlBase, logException) {
}

HttpUrlParserInvalidUrlException::~HttpUrlParserInvalidUrlException() {
}

}
