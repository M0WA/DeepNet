/*
 * UrlParserEncodeException.h
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace htmlparser {

class UrlParserEncodeException: public errors::Exception {
public:
	UrlParserEncodeException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& url);
	virtual ~UrlParserEncodeException();
};

}
