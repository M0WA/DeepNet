/*
 * URLInvalidSubdomainIDException.h
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace caching {

class URLInvalidSubdomainIDException: public errors::Exception {
public:
	URLInvalidSubdomainIDException(
			const std::string& file,
			const int line,
			const std::string& function,
			const long long& subdomainID,
			const long long& urlID);
	virtual ~URLInvalidSubdomainIDException();
};

}
