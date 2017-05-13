/*
 * DatabaseInvalidTypeException.h
 *
 *  Created on: 10.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class DatabaseInvalidTypeException: public database::DatabaseException {
public:
	DatabaseInvalidTypeException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~DatabaseInvalidTypeException();
};

}

