/*
 * URLInvalidUrlIDException.h
 *
 *  Created on: 23.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace caching {

class URLInvalidUrlIDException: public errors::Exception {
public:
	URLInvalidUrlIDException(
			const std::string& file,
			const int line,
			const std::string& function,
			const long long& urlID);
	virtual ~URLInvalidUrlIDException();
};

}
