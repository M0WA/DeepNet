/*
 * DatabaseInvalidColumnNameException.h
 *
 *  Created on: 10.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class DatabaseInvalidColumnNameException : public database::DatabaseException {
public:
	DatabaseInvalidColumnNameException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& columnName);
	virtual ~DatabaseInvalidColumnNameException();
};

}

