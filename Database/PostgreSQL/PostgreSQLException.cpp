/**
 *
 * @file PostgreSQLException.cpp
 * @author Moritz Wagner
 * @date 14.07.2013
 *
 */

#include "PostgreSQLException.h"

namespace database {

PostgreSQLException::PostgreSQLException(
	const std::string& file,
	const int line,
	const std::string& function,
	const std::string& exceptionName,
	PGconn* connection,
	const std::string& msg)
: database::DatabaseException(file,line,function,exceptionName,GetCombinedMessage(connection,msg)) {
}

PostgreSQLException::~PostgreSQLException() {
}

std::string PostgreSQLException::GetCombinedMessage(PGconn* connection,const std::string& msg) {

	std::string exMsg("\nserver message:");
	if(connection)
		exMsg += PQerrorMessage(connection);
	else
		exMsg += "na\n";
	exMsg += "query/msg: " + msg;
	return exMsg;
}

}
