/**
 *
 * @file PostgreSQLUniqueKeyIsSumColumnException.cpp
 * @author Moritz Wagner
 * @date 14.07.2013
 *
 */

#include "PostgreSQLUniqueKeyIsSumColumnException.h"

namespace database {

PostgreSQLUniqueKeyIsSumColumnException::PostgreSQLUniqueKeyIsSumColumnException(
	const std::string& file,
	const int line,
	const std::string& function,
	PGconn* connection,
	const std::string& msg)
: database::PostgreSQLException(file,line,function,"PostgreSQLUniqueKeyIsSumColumnException",connection,"unique key cannot be a sum column") {
}

PostgreSQLUniqueKeyIsSumColumnException::~PostgreSQLUniqueKeyIsSumColumnException() {
}

}
