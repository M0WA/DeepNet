/*
 * FastCGIServerSocketException.h
 *
 *  Created on: 08.11.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "FastCGIServerException.h"

namespace fastcgiserver {

class FastCGIServerSocketException: public FastCGIServerException {
public:
	FastCGIServerSocketException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& message);
	virtual ~FastCGIServerSocketException();
};

}

