/*
 * DatabaseNotNullableException.cpp
 *
 *  Created on: 10.08.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseNotNullableException.h"

namespace database {

DatabaseNotNullableException::DatabaseNotNullableException(
		const std::string& file,
		const int line,
		const std::string& function)
: DatabaseException(file,line,function,"DatabaseNotNullableException", "error while trying to null a non-nullable column"){
}

DatabaseNotNullableException::~DatabaseNotNullableException() {
}

}
