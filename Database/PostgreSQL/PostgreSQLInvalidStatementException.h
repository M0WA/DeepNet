/**
 *
 * @file PostgreSQLInvalidStatementException.h
 * @author Moritz Wagner
 * @date 13.06.2013
 *
 */

#pragma once

#include "PostgreSQLException.h"

namespace database {

class PostgreSQLInvalidStatementException: public database::PostgreSQLException {
public:
	PostgreSQLInvalidStatementException(
			const std::string& file,
			const int line,
			const std::string& function,
			PGconn* connection,
			const std::string& stmt);

	virtual ~PostgreSQLInvalidStatementException();
};

}
