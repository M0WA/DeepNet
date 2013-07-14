/**
 *
 * @file PostgreSQLInsertOrUpdateStatement.h
 * @author Moritz Wagner
 * @date 13.07.2013
 *
 */

#pragma once

#include <string>

namespace database {

class InsertOrUpdateStatement;
class DatabaseConnection;

/**
 * @brief implementation of a insert or update statement for PostgreSQL servers
 */
class PostgreSQLInsertOrUpdateStatement {
public:
	PostgreSQLInsertOrUpdateStatement(const InsertOrUpdateStatement* stmt);
	virtual ~PostgreSQLInsertOrUpdateStatement();

public:
	/**
	 * gets sql equivalent of this statement.
	 * @param db database connection.
	 * @return sql string.
	 */
	std::string ToSQL( DatabaseConnection* db ) const;

private:
	std::string UpdateByPrimaryKey( DatabaseConnection* db ) const;
	std::string UpdateOrInsertByUniqueKeys( DatabaseConnection* db ) const;

private:
	const InsertOrUpdateStatement* orgStatement;
};

}
