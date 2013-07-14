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
class PostgreSQLInsertOrUpdateAffectedKeyStatement: public database::SelectStatement {
public:
	PostgreSQLInsertOrUpdateAffectedKeyStatement(const InsertOrUpdateStatement& stmt);
	virtual ~PostgreSQLInsertOrUpdateAffectedKeyStatement();

private:
	void InitSelectedFields();
	void InitWhereClause();

private:
	const InsertOrUpdateStatement& stmt;
};

}
