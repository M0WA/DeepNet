/**
 * @file MySQLInsertStatement.h
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#pragma once

#include <string>

namespace database {

class DatabaseConnection;
class InsertStatement;

/**
 * @brief implementation of a insert statement for MySQL servers
 */
class MySQLInsertStatement{
public:
	MySQLInsertStatement(const InsertStatement* stmt);
	virtual ~MySQLInsertStatement();

public:
	/**
	 * gets sql equivalent of this statement.
	 * @param db database connection.
	 * @return sql string.
	 */
	std::string ToSQL( DatabaseConnection* db ) const;

private:
	const InsertStatement* orgStatement;
};

}
