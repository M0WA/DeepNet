/**
 *
 * @file PostgreSQLInsertStatement.h
 * @author Moritz Wagner
 * @date 16.07.2013
 *
 */

#pragma once

#include <string>

namespace database {

class InsertStatement;
class PostgreSQLConnection;
class DatabaseConnection;

/**
 * @brief implementation of an insert for PostgreSQL servers
 */
class PostgreSQLInsertStatement {

	friend class PostgreSQLConnection;

private:
	PostgreSQLInsertStatement(const InsertStatement& orgStmt);
public:
	virtual ~PostgreSQLInsertStatement();

public:
	/**
	 * gets sql equivalent of this statement.
	 * @param db database connection.
	 * @return sql string.
	 */
	std::string ToSQL( DatabaseConnection* db ) const;

private:
	const InsertStatement& orgStmt;
};

}
