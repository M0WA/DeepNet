/*
 * URLInvalidUrlIDException.cpp
 *
 *  Created on: 23.08.2012
 *      Author: Moritz Wagner
 */

#include "URLInvalidUrlIDException.h"

#include <StringTools.h>

namespace caching {

URLInvalidUrlIDException::URLInvalidUrlIDException(
		const std::string& file,
		const int line,
		const std::string& function,
		const long long& urlID)
: errors::Exception( file,line,function,"caching","URLInvalidUrlIDException", "invalid url id: " + tools::StringTools::TransformString(urlID)) {
}

URLInvalidUrlIDException::~URLInvalidUrlIDException() {
}

}
