/*
 * DatabaseNotNullableException.h
 *
 *  Created on: 10.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class DatabaseNotNullableException: public database::DatabaseException {
public:
	DatabaseNotNullableException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~DatabaseNotNullableException();
};

}

