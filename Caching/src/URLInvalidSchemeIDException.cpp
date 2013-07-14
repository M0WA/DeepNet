/*
 * URLInvalidSchemeIDException.cpp
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#include "URLInvalidSchemeIDException.h"

#include <StringTools.h>

namespace caching {

URLInvalidSchemeIDException::URLInvalidSchemeIDException(
		const std::string& file,
		const int line,
		const std::string& function,
		const long long& schemeID,
		const long long& urlID)
: errors::Exception( file,line,function,"caching","URLInvalidSchemeIDException","invalid scheme id: " + tools::StringTools::TransformString(schemeID) + " in url id: " + tools::StringTools::TransformString(urlID) ){
}

URLInvalidSchemeIDException::~URLInvalidSchemeIDException() {
}

}
