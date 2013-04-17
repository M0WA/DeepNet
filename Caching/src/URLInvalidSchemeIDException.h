/*
 * URLInvalidSchemeIDException.h
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

class URLInvalidSchemeIDException: public errors::Exception {
public:
	URLInvalidSchemeIDException(
		const std::string& file,
		const int line,
		const std::string& function,
		const long long& schemeID,
		const long long& urlID);
	virtual ~URLInvalidSchemeIDException();
};

