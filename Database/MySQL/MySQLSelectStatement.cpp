/**
 * @file MySQLSelectStatement.cpp
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#include "MySQLSelectStatement.h"
#include "SelectStatement.h"

namespace database {

MySQLSelectStatement::MySQLSelectStatement(const SelectStatement* stmt)
: orgStatement(stmt)
{
}

MySQLSelectStatement::~MySQLSelectStatement()
{
}

std::string MySQLSelectStatement::ToSQL( DatabaseConnection* db ) const {
	return orgStatement->ToSQL(db);
}

}
