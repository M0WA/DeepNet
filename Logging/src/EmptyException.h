/*
 * EmptyException.h
 *
 *  Created on: 20.11.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "Exception.h"

namespace errors {

class EmptyException : public Exception{
public:
	EmptyException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~EmptyException();
};

}

