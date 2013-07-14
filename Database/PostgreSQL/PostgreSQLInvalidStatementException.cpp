/**
 *
 * @file PostgreSQLInvalidStatementException.cpp
 * @author Moritz Wagner
 * @date 13.06.2013
 *
 */

#include "PostgreSQLInvalidStatementException.h"

namespace database {

PostgreSQLInvalidStatementException::PostgreSQLInvalidStatementException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& stmt)
: database::DatabaseException(file,line,function,"PostgreSQLInvalidStatementException", stmt){
}

PostgreSQLInvalidStatementException::~PostgreSQLInvalidStatementException() {
}

}
