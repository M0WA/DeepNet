/*
 * DatabaseLoggingNotInitializedException.h
 *
 *  Created on: 22.09.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace log {

class DatabaseLoggingNotInitializedException : public errors::Exception {
public:
	DatabaseLoggingNotInitializedException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& message);
	virtual ~DatabaseLoggingNotInitializedException();
};

}

