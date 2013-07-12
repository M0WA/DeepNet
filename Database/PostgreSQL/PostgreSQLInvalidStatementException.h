/**
 *
 * @file PostgreSQLInvalidStatementException.h
 * @author Moritz Wagner
 * @date 13.06.2013
 *
 */

#pragma once

#include "DatabaseException.h"

namespace database {

class PostgreSQLInvalidStatementException: public database::DatabaseException {
public:
	PostgreSQLInvalidStatementException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& stmt);

	virtual ~PostgreSQLInvalidStatementException();
};

}
