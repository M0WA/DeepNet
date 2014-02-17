/**
 *
 * @file InvalidOperationException.h
 * @author Moritz Wagner
 * @date 17.02.2014
 *
 */

#pragma once

#include "Exception.h"

namespace errors {

/**
 * @brief exception for invalid operations.
 */
class InvalidOperationException: public errors::Exception {
public:
	InvalidOperationException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& module);
	virtual ~InvalidOperationException();
};

}

