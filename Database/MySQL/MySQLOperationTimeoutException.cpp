/*
 * MySQLOperationTimeoutException.cpp
 *
 *  Created on: 15.08.2012
 *      Author: Moritz Wagner
 */

#include "MySQLOperationTimeoutException.h"

namespace database {

MySQLOperationTimeoutException::MySQLOperationTimeoutException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"MySQLOperationTimeoutException","operation timed out or is dead locked"){
}

MySQLOperationTimeoutException::~MySQLOperationTimeoutException() {
}

}
