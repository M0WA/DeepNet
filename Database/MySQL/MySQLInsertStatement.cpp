/**
 * @file MySQLInsertStatement.cpp
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#include "MySQLInsertStatement.h"

#include <sstream>

#include "InsertStatement.h"

namespace database {

MySQLInsertStatement::MySQLInsertStatement(const InsertStatement* stmt)
: orgStatement(stmt) {
}

MySQLInsertStatement::~MySQLInsertStatement() {
}

std::string MySQLInsertStatement::ToSQL( DatabaseConnection* db ) const {
	return orgStatement->ToSQL(db);
}

}
