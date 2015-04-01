/*
 * DatabaseEmptyDatabaseNameException.cpp
 *
 *  Created on: 11.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseEmptyDatabaseNameException.h"

namespace database {

DatabaseEmptyDatabaseNameException::DatabaseEmptyDatabaseNameException(
	const std::string& file,
	const int line,
	const std::string& function)
: DatabaseException(file,line,function,"DatabaseEmptyDatabaseNameException","empty database name specified") {
}

DatabaseEmptyDatabaseNameException::~DatabaseEmptyDatabaseNameException() {
}

}
