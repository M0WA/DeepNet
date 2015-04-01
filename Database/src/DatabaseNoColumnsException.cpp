/*
 * DatabaseNoColumnsException.cpp
 *
 *  Created on: 11.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseNoColumnsException.h"

namespace database {

DatabaseNoColumnsException::DatabaseNoColumnsException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"DatabaseNoColumnsException", "no columns specified") {
}

DatabaseNoColumnsException::~DatabaseNoColumnsException() {
}

}
