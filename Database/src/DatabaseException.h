/*
 * DatabaseException.h
 *
 *  Created on: 10.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace database {

class DatabaseException : public errors::Exception {
public:
	DatabaseException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& exceptionName,
		const std::string& message);
	virtual ~DatabaseException();
};

}

