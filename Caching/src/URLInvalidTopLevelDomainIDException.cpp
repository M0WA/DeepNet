/*
 * URLInvalidTopLevelDomainIDException.cpp
 *
 *  Created on: 22.08.2012
 *      Author: Moritz Wagner
 */

#include "URLInvalidTopLevelDomainIDException.h"

#include <StringTools.h>

URLInvalidTopLevelDomainIDException::URLInvalidTopLevelDomainIDException(
	const std::string& file,
	const int line,
	const std::string& function,
	const long long& tldID,
	const long long& urlID)
: errors::Exception( file,line,function,"caching","URLInvalidTopLevelDomainIDException","invalid topleveldomain id: " + tools::StringTools::TransformString(tldID) + " in url id: " + tools::StringTools::TransformString(urlID)){

}

URLInvalidTopLevelDomainIDException::~URLInvalidTopLevelDomainIDException() {
}
