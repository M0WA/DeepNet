/*
 * UrlParserInvalidUrlException.cpp
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#include "UrlParserInvalidUrlException.h"

namespace htmlparser {

UrlParserInvalidUrlException::UrlParserInvalidUrlException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& url,
		const std::string& urlBase)
: HtmlParserException(file,line,function,"UrlParserInvalidUrlException", "cannot parse url:\n" + url + "\nbaseUrl: " + urlBase) {
}

UrlParserInvalidUrlException::~UrlParserInvalidUrlException() {
}

}
