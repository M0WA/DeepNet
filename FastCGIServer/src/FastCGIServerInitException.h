/*
 * FastCGIServerInitException.h
 *
 *  Created on: 08.11.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "FastCGIServerException.h"

namespace fastcgiserver {

class FastCGIServerInitException: public FastCGIServerException {
public:
	FastCGIServerInitException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& message);
	virtual ~FastCGIServerInitException();
};

}

