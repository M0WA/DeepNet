/**
 *
 * @file NotImplementedException.h
 * @author Moritz Wagner
 * @date 15.08.2012
 *
 */

#pragma once

#include "Exception.h"

namespace errors {

class NotImplementedException: public errors::Exception {
public:
	NotImplementedException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& module);
	virtual ~NotImplementedException();
};

}

