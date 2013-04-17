/*
 * DatabaseInvalidColumnNameException.cpp
 *
 *  Created on: 10.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseInvalidColumnNameException.h"

namespace database {

DatabaseInvalidColumnNameException::DatabaseInvalidColumnNameException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"DatabaseInvalidColumnNameException", "an invalid column name was specified") {
}

DatabaseInvalidColumnNameException::~DatabaseInvalidColumnNameException() {
}

}
