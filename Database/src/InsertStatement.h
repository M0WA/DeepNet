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
	virtual InnerJoinCondition& InnerJoin();
	virtual std::string ToSQL( DatabaseConnection* db ) const;

public:
	const TableBase* GetConstTableBase() const { return tableBase; }

protected:
	const TableBase* tableBase;
};

}
