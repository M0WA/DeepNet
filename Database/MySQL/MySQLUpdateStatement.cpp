/**
 * @file MySQLUpdateStatement.cpp
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#include "MySQLUpdateStatement.h"

#include "UpdateStatement.h"

namespace database {

MySQLUpdateStatement::MySQLUpdateStatement(const UpdateStatement* stmt)
: orgStatement(stmt)
{
}

MySQLUpdateStatement::~MySQLUpdateStatement() {
}

std::string MySQLUpdateStatement::ToSQL( DatabaseConnection* db ) const {
	return orgStatement->ToSQL(db);
}

}
