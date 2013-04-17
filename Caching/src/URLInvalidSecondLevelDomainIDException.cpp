/*
 * URLInvalidSecondLevelDomainIDException.cpp
 *
 *  Created on: 22.08.2012
 *      Author: Moritz Wagner
 */

#include "URLInvalidSecondLevelDomainIDException.h"

#include <StringTools.h>

URLInvalidSecondLevelDomainIDException::URLInvalidSecondLevelDomainIDException(
		const std::string& file,
		const int line,
		const std::string& function,
		const long long& sndLvlID,
		const long long& urlID)
: errors::Exception( file,line,function,"caching","URLInvalidTopLevelDomainIDException","invalid secondleveldomain id: " + tools::StringTools::TransformString(sndLvlID) + " in url id: " + tools::StringTools::TransformString(urlID)){

}

URLInvalidSecondLevelDomainIDException::~URLInvalidSecondLevelDomainIDException() {
}
