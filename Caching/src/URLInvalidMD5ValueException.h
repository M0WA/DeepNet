/*
 * URLInvalidMD5ValueException.h
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

#include <string>

namespace caching {

class DatabaseUrl;

class URLInvalidMD5ValueException: public errors::Exception {
public:
	URLInvalidMD5ValueException(
		const std::string& file,
		const int line,
		const std::string& function,
		const DatabaseUrl& url);
	virtual ~URLInvalidMD5ValueException();
};

}
