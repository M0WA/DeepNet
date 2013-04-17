/*
 * DatabaseInvalidOperatorTypeException.cpp
 *
 *  Created on: 11.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseInvalidOperatorTypeException.h"

namespace database {

DatabaseInvalidOperatorTypeException::DatabaseInvalidOperatorTypeException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"DatabaseInvalidOperatorTypeException", "invalid operator type") {
}

DatabaseInvalidOperatorTypeException::~DatabaseInvalidOperatorTypeException() {
}

}
