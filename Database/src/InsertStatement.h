/**
 * @file InsertStatement.h
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#pragma once

#include <string>
#include <vector>
#include <map>

#include "Statement.h"

namespace database {

class TableBase;
class DatabaseConnection;

/**
 * @brief implements generic sql insert statement.
 * @see database::MySQLInsertStatement
 * @see database::DB2InsertStatement
 */
class InsertStatement : public Statement {
public:
	/**
	 * construct with existing table filled with values to insert.
	 * @param tableBase existing table.
	 */
	InsertStatement(TableBase* tableBase);
	virtual ~InsertStatement();

public:
	/**
	 * gets table base for this statement
	 * @return table base
	 */
	const TableBase* GetConstTableBase() const { return tableBase; }

public:
	virtual InnerJoinCondition& InnerJoin();
	virtual std::string ToSQL( DatabaseConnection* db ) const;

protected:
	TableBase* tableBase;
};

}
