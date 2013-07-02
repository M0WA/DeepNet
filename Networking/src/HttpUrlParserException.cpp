/*
 * HttpUrlParserException.cpp
 *
 *  Created on: Dec 23, 2012
 *      Author: Moritz Wagner
 */

#include "HttpUrlParserException.h"

namespace network {

HttpUrlParserException::HttpUrlParserException(
	const std::string& file,
	const int line,
	const std::string& function,
	const std::string& exceptionName,
	const std::string& message,
	const bool logException)
: errors::Exception(file,line,function,"HttpUrlParser", exceptionName, message,logException) {
}

HttpUrlParserException::~HttpUrlParserException() {
}

}
