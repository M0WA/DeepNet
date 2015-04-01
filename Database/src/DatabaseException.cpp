/*
 * DatabaseException.cpp
 *
 *  Created on: 10.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseException.h"

namespace database {

DatabaseException::DatabaseException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& exceptionName,
		const std::string& message)
: Exception(file,line,function,"database", exceptionName, message){
}

DatabaseException::~DatabaseException() {
}

}
