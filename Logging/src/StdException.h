/*
 * StdException.h
 *
 *  Created on: 17.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "Exception.h"

namespace errors {

class StdException: public errors::Exception {
public:
	StdException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::exception& ex,
			const std::string& backtrace,
			const bool logException = true);

	StdException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::exception& ex,
			const bool logException = true);

	virtual ~StdException();
};

}

