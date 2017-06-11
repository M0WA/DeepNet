/*
 * DatabaseEmptyDatabaseNameException.h
 *
 *  Created on: 11.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class DatabaseEmptyDatabaseNameException : public database::DatabaseException {
public:
	DatabaseEmptyDatabaseNameException(
		const std::string& file,
		const int line,
		const std::string& function);
	virtual ~DatabaseEmptyDatabaseNameException();
};

}

