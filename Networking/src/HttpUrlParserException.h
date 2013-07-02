/*
 * HttpUrlParserException.h
 *
 *  Created on: Dec 23, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "Exception.h"

namespace network {

class HttpUrlParserException: public errors::Exception {
public:
	HttpUrlParserException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& exceptionName,
			const std::string& message,
			const bool logException = true);
	virtual ~HttpUrlParserException();
};

}
