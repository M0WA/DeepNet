/**
 *
 * @file PostgreSQLInsertOrUpdateAffectedKeyStatement.h
 * @author Moritz Wagner
 * @date 14.07.2013
 *
 */

#pragma once

#include "SelectStatement.h"

namespace database {

class InsertOrUpdateStatement;
class PostgreSQLConnection;

/**
 * @brief used internally only by database::PostgreSQLConnection for database::InsertOrUpdateStatement
 * @see database::InsertOrUpdateStatement
 * @see database::PostgreSQLConnection
 */
class PostgreSQLInsertOrUpdateAffectedKeyStatement: public database::SelectStatement {

	friend class PostgreSQLConnection;

private:
	PostgreSQLInsertOrUpdateAffectedKeyStatement(const InsertOrUpdateStatement& stmt);
public:
	virtual ~PostgreSQLInsertOrUpdateAffectedKeyStatement();

private:
	void InitSelectedFields();
	void InitWhereClause();

private:
	const InsertOrUpdateStatement& stmt;
};

}
