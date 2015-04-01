/**
 *
 * @file PostgreSQLUniqueKeyIsSumColumnException.h
 * @author Moritz Wagner
 * @date 14.07.2013
 *
 */

#pragma once

#include "PostgreSQLException.h"

namespace database {

/**
 * @brief error when an unique key is a sum column
 */
class PostgreSQLUniqueKeyIsSumColumnException: public database::PostgreSQLException {
public:
	PostgreSQLUniqueKeyIsSumColumnException(
		const std::string& file,
		const int line,
		const std::string& function,
		PGconn* connection,
		const std::string& msg);
	virtual ~PostgreSQLUniqueKeyIsSumColumnException();
};

}
