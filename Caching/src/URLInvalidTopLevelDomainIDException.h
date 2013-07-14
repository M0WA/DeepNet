/*
 * URLInvalidTopLevelDomainIDException.h
 *
 *  Created on: 22.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace caching {

class URLInvalidTopLevelDomainIDException: public errors::Exception {
public:
	URLInvalidTopLevelDomainIDException(
		const std::string& file,
		const int line,
		const std::string& function,
		const long long& tldID,
		const long long& urlID);
	virtual ~URLInvalidTopLevelDomainIDException();
};

}
