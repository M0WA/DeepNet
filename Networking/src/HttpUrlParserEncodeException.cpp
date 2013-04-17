/*
 * UrlParserEncodeException.cpp
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#include "HttpUrlParserEncodeException.h"

namespace network {

HttpUrlParserEncodeException::HttpUrlParserEncodeException(
	const std::string& file,
	const int line,
	const std::string& function,
	const std::string& url)
: HttpUrlParserException(file,line,function,"UrlParserEncodeException", "cannot encode url: " + url) {
}

HttpUrlParserEncodeException::~HttpUrlParserEncodeException() {
}

}
