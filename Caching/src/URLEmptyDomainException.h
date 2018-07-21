/*
 * URLEmptyDomainException.h
 *
 *  Created on: 19.11.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace caching {

class DatabaseUrl;

class URLEmptyDomainException: public errors::Exception {
public:
	URLEmptyDomainException(
			const std::string& file,
			const int line,
			const std::string& function,
			const DatabaseUrl& url);
	virtual ~URLEmptyDomainException();
};

}
