/*
 * UrlParserDecodeException.cpp
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#include "HttpUrlParserDecodeException.h"

namespace network {

HttpUrlParserDecodeException::HttpUrlParserDecodeException(
	const std::string& file,
	const int line,
	const std::string& function,
	const std::string& url)
: HttpUrlParserException(file,line,function,"HttpUrlParserDecodeException", "cannot decode url: " + url) {
}

HttpUrlParserDecodeException::~HttpUrlParserDecodeException() {
}

}
