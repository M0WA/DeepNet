/**
 * @file MySQLSelectStatement.h
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#pragma once

#include <string>

namespace database {

class DatabaseConnection;
class SelectStatement;

/**
 * @brief implementation of a select statement for MySQL servers
 */
class MySQLSelectStatement {
public:
	MySQLSelectStatement(const SelectStatement* orgStatement);
	virtual ~MySQLSelectStatement();

public:
	/**
	 * gets sql equivalent of this statement.
	 * @param db database connection.
	 * @return sql string.
	 */
	std::string ToSQL( DatabaseConnection* db ) const;

private:
	const SelectStatement* orgStatement;
};

}
