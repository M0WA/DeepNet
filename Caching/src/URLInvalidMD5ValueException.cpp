/*
 * URLInvalidMD5ValueException.cpp
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#include "URLInvalidMD5ValueException.h"

#include <DatabaseUrl.h>

namespace caching {

URLInvalidMD5ValueException::URLInvalidMD5ValueException(
	const std::string& file,
	const int line,
	const std::string& function,
	const htmlparser::DatabaseUrl& url)
: errors::Exception( file,line,function,"caching","URLInvalidMD5ValueException","invalid url md5 value: " + url.Dump() ) {
}

URLInvalidMD5ValueException::~URLInvalidMD5ValueException() {
}

}
