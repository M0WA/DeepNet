/*
 * DatabaseNoPrimaryKeyException.cpp
 *
 *  Created on: 12.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseNoPrimaryKeyException.h"

namespace database {

DatabaseNoPrimaryKeyException::DatabaseNoPrimaryKeyException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"DatabaseNoPrimaryKeyException", "no primary key found") {
}

DatabaseNoPrimaryKeyException::~DatabaseNoPrimaryKeyException() {
}

}
