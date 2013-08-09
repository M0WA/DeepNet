/**
 *
 * @file DatabaseColumnDatasizeExceededException.h
 * @author Moritz Wagner
 * @date 09.08.2013
 *
 */

#pragma once

#include <string>

#include "DatabaseException.h"

namespace database {

class DatabaseColumnDatasizeExceededException: public database::DatabaseException {
public:
	DatabaseColumnDatasizeExceededException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~DatabaseColumnDatasizeExceededException();
};

}
