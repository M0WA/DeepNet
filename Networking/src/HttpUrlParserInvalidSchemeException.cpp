/*
 * URLInvalidSchemeException.cpp
 *
 *  Created on: 22.08.2012
 *      Author: Moritz Wagner
 */

#include "HttpUrlParserInvalidSchemeException.h"

namespace network {

HttpUrlParserInvalidSchemeException::HttpUrlParserInvalidSchemeException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& url)
: HttpUrlParserException( file,line,function,"HttpUrlParserInvalidSchemeException","invalid scheme in url " + url) {

}

HttpUrlParserInvalidSchemeException::~HttpUrlParserInvalidSchemeException() {
}

}
