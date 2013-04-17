/*
 * UrlParserEncodeException.cpp
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#include "UrlParserEncodeException.h"

namespace htmlparser {

UrlParserEncodeException::UrlParserEncodeException(
	const std::string& file,
	const int line,
	const std::string& function,
	const std::string& url)
: errors::Exception(file,line,function,"htmlparser", "UrlParserEncodeException", "cannot encode url: " + url) {
}

UrlParserEncodeException::~UrlParserEncodeException() {
}

}
