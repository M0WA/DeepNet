/*
 * URLStoreException.h
 *
 *  Created on: 23.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace caching {

class URLStoreException: public errors::Exception {
public:
	URLStoreException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& url);
	virtual ~URLStoreException();
};

}
