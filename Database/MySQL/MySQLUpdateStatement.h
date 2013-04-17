/**
 * @file MySQLUpdateStatement.h
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#pragma once

#include <string>

namespace database {
class DatabaseConnection;
class UpdateStatement;

/**
 * @brief implementation of an update statement for MySQL servers
 */
class MySQLUpdateStatement {
public:
	MySQLUpdateStatement(const UpdateStatement* stmt);
	virtual ~MySQLUpdateStatement();

public:
	/**
	 * gets sql equivalent of this statement.
	 * @param db database connection.
	 * @return sql string.
	 */
	std::string ToSQL( DatabaseConnection* db ) const;

private:
	const UpdateStatement* orgStatement;
};

}
