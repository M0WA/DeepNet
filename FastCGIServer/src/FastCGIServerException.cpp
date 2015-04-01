/*
 * FastCGIServerException.cpp
 *
 *  Created on: 08.11.2012
 *      Author: Moritz Wagner
 */

#include "FastCGIServerException.h"

namespace fastcgiserver {

FastCGIServerException::FastCGIServerException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& exceptionName,
		const std::string& message)
: errors::Exception(file,line,function,"FastCGIServer", exceptionName, message) {
}

FastCGIServerException::~FastCGIServerException() {
}

}
