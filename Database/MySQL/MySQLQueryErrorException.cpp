/*
 * MySQLQueryErrorException.cpp
 *
 *  Created on: 15.08.2012
 *      Author: Moritz Wagner
 */

#include "MySQLQueryErrorException.h"

#include <sstream>

namespace database {

MySQLQueryErrorException::MySQLQueryErrorException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& MySQLerror,
		const std::string& stmt)
: DatabaseException(file,line,function,"MySQLQueryErrorException","error while executing statement:\n" + stmt + "\nMySQL error: " + MySQLerror){
}

MySQLQueryErrorException::~MySQLQueryErrorException() {
}

}
