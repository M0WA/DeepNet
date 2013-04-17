/*
 * FastCGIServerException.h
 *
 *  Created on: 08.11.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace fastcgiserver {

class FastCGIServerException: public errors::Exception {
public:
	FastCGIServerException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& exceptionName,
			const std::string& message);
	virtual ~FastCGIServerException();
};

}

