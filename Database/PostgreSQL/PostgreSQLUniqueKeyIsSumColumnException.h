/**
 *
 * @file PostgreSQLUniqueKeyIsSumColumnException.h
 * @author Moritz Wagner
 * @date 14.07.2013
 *
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class PostgreSQLUniqueKeyIsSumColumnException: public database::DatabaseException {
public:
	PostgreSQLUniqueKeyIsSumColumnException(
		const std::string& file,
		const int line,
		const std::string& function);
	virtual ~PostgreSQLUniqueKeyIsSumColumnException();
};

}
