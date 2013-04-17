/*
 * UrlParserDecodeException.cpp
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#include "UrlParserDecodeException.h"

namespace htmlparser {

UrlParserDecodeException::UrlParserDecodeException(
	const std::string& file,
	const int line,
	const std::string& function,
	const std::string& url)
: errors::Exception(file,line,function,"htmlparser", "UrlParserDecodeException", "cannot decode url: " + url) {
}

UrlParserDecodeException::~UrlParserDecodeException() {
}

}
