/*
 * URLInvalidSchemeException.cpp
 *
 *  Created on: 22.08.2012
 *      Author: Moritz Wagner
 */

#include "URLInvalidSchemeException.h"

namespace caching {

URLInvalidSchemeException::URLInvalidSchemeException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& url)
: errors::Exception( file,line,function,"caching","URLInvalidSchemeException","invalid scheme in url " + url) {

}

URLInvalidSchemeException::~URLInvalidSchemeException() {
}

}
