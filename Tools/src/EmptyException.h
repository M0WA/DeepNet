/**
 *
 * @file EmptyException.h
 * @author Moritz Wagner
 * @date 20.11.2012
 *
 */

#pragma once

#include "Exception.h"

namespace errors {

/**
 * @brief represents empty or unknown exception
 */
class EmptyException : public Exception{
public:
	EmptyException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~EmptyException();
};

}

