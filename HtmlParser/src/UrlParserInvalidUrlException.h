/*
 * UrlParserInvalidUrlException.h
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace htmlparser {

class UrlParserInvalidUrlException: public errors::Exception {
public:
	UrlParserInvalidUrlException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& url,
			const std::string& urlBase);
	virtual ~UrlParserInvalidUrlException();
};

}
