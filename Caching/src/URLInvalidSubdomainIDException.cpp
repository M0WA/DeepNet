/*
 * URLInvalidSubdomainIDException.cpp
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#include "URLInvalidSubdomainIDException.h"

#include <StringTools.h>

URLInvalidSubdomainIDException::URLInvalidSubdomainIDException(
	const std::string& file,
	const int line,
	const std::string& function,
	const long long& subdomainID,
	const long long& urlID)
: errors::Exception( file,line,function,"caching","URLInvalidSubdomainIDException","invalid subdomain id: " + tools::StringTools::TransformString(subdomainID) + " in url id: " + tools::StringTools::TransformString(urlID) ) {
}

URLInvalidSubdomainIDException::~URLInvalidSubdomainIDException() {
}
