/*
 * URLInvalidSchemeException.h
 *
 *  Created on: 22.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

class URLInvalidSchemeException: public errors::Exception {
public:
	URLInvalidSchemeException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& url);
	virtual ~URLInvalidSchemeException();
};

