/*
 * DatabaseInvalidTypeConversionException.h
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class DatabaseInvalidTypeConversionException: public database::DatabaseException {

public:
	DatabaseInvalidTypeConversionException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~DatabaseInvalidTypeConversionException();
};

}

