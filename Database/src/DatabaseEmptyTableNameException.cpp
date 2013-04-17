/*
 * DatabaseEmptyTableNameException.cpp
 *
 *  Created on: 11.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseEmptyTableNameException.h"

namespace database {

DatabaseEmptyTableNameException::DatabaseEmptyTableNameException(
	const std::string& file,
	const int line,
	const std::string& function)
: DatabaseException(file,line,function,"DatabaseEmptyTableNameException", "empty table name specified") {
}

DatabaseEmptyTableNameException::~DatabaseEmptyTableNameException() {
}

}
