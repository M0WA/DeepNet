/*
 * URLEmptyDomainException.h
 *
 *  Created on: 19.11.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace htmlparser {
	class DatabaseUrl;
}

namespace caching {

class URLEmptyDomainException: public errors::Exception {
public:
	URLEmptyDomainException(
			const std::string& file,
			const int line,
			const std::string& function,
			const htmlparser::DatabaseUrl& url);
	virtual ~URLEmptyDomainException();
};

}
