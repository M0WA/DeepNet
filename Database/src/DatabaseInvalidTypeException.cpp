/*
 * DatabaseInvalidTypeException.cpp
 *
 *  Created on: 10.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseInvalidTypeException.h"

namespace database {

DatabaseInvalidTypeException::DatabaseInvalidTypeException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"DatabaseInvalidTypeException", "invalid type conversion") {
}

DatabaseInvalidTypeException::~DatabaseInvalidTypeException() {
}

}
