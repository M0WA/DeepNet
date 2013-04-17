/**
 * @file DeleteStatement.h
 * @author Moritz Wagner
 * @date 04.05.2012
 */

#pragma once

#include <string>

#include "WhereCondition.h"
#include "Statement.h"

namespace database {

class TableDefinition;
class TableBase;

/**
 * @brief implements generic sql delete statement.
 * @see database::MySQLDeleteStatement
 * @see database::DB2DeleteStatement
 */
class DeleteStatement : public Statement {
public:
	/**
	 * construct with a table definition.
	 * the given table definition is used in the "DELETE FROM <table>"
	 * part of the statement.
	 * @param tableDefinition table definition.
	 */
	DeleteStatement(TableDefinition* tableDefinition);

	virtual ~DeleteStatement();

	/**
	 * gets where condition for this statement.
	 * @return where condition.
	 */
	inline WhereCondition& Where(void) {return this->whereCondition;}

public:
	virtual InnerJoinCondition& InnerJoin();
	virtual std::string ToSQL(database::DatabaseConnection* db) const;

private:
	WhereCondition whereCondition;
};

}
