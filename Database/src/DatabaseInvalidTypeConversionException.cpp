/*
 * DatabaseInvalidTypeConversionException.cpp
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseInvalidTypeConversionException.h"

namespace database {

DatabaseInvalidTypeConversionException::DatabaseInvalidTypeConversionException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"DatabaseInvalidTypeConversionException", "error while converting datatypes") {
}

DatabaseInvalidTypeConversionException::~DatabaseInvalidTypeConversionException() {
}

}
