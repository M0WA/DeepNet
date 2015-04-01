/**
 *
 * @file DatabaseColumnDatasizeExceededException.cpp
 * @author Moritz Wagner
 * @date 09.08.2013
 *
 */

#include "DatabaseColumnDatasizeExceededException.h"

namespace database {

DatabaseColumnDatasizeExceededException::DatabaseColumnDatasizeExceededException(
	const std::string& file,
	const int line,
	const std::string& function)
: DatabaseException(file,line,function,"DatabaseColumnDatasizeExceededException","data value is too big"){
}

DatabaseColumnDatasizeExceededException::~DatabaseColumnDatasizeExceededException() {
}

}
