/**
 *
 * @file PostgreSQLException.h
 * @author Moritz Wagner
 * @date 14.07.2013
 *
 */

#pragma once

#include "DatabaseException.h"
#include <libpq-fe.h>

namespace database {

class PostgreSQLException: public database::DatabaseException {
public:
	PostgreSQLException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& exceptionName,
			PGconn* connection,
			const std::string& msg);
	virtual ~PostgreSQLException();

private:
	static std::string GetCombinedMessage(PGconn* connection,const std::string& msg);
};

}
