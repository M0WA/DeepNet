/**
 * @file MySQLInsertOrUpdateStatement.h
 * @author Moritz Wagner
 * @date 01.05.2012
 */

#pragma once

#include <string>

#include "Statement.h"

namespace database {
class DatabaseConnection;
class InsertOrUpdateStatement;

/**
 * @brief implementation of a insert or update statement for MySQL servers
 */
class MySQLInsertOrUpdateStatement {
public:
	MySQLInsertOrUpdateStatement(const InsertOrUpdateStatement& stmt);
	virtual ~MySQLInsertOrUpdateStatement();

public:
	/**
	 * gets sql equivalent of this statement.
	 * @param db database connection.
	 * @return sql string.
	 */
	std::string ToSQL( DatabaseConnection* db ) const;

private:
	const InsertOrUpdateStatement& orgStatement;
};

}

