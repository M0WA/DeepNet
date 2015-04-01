/**
 *
 * @file PostgreSQLUpdateStatement.h
 * @author Moritz Wagner
 * @date 18.07.2013
 *
 */

#pragma once

#include <string>

namespace database {

class DatabaseConnection;
class UpdateStatement;

/**
 * @brief implementation of an update statement for PostgreSQL servers
 */
class PostgreSQLUpdateStatement {
public:
	PostgreSQLUpdateStatement(const UpdateStatement& stmt);
	virtual ~PostgreSQLUpdateStatement();

public:
	/**
	 * gets sql equivalent of this statement.
	 * @param db database connection.
	 * @return sql string.
	 */
	std::string ToSQL(database::DatabaseConnection* db) const;

private:
	const UpdateStatement& orgStmt;
};

}
