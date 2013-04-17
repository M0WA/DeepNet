/*
 * NotImplementedException.h
 *
 *  Created on: 15.08.2012
 *      Author: Moritz Wagner
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

