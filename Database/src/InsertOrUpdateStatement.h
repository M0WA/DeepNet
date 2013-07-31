/**
 * @file InsertOrUpdateStatement.h
 * @author Moritz Wagner
 * @date 12.08.2012
 */

#pragma once

#include <string>
#include <vector>

#include <PointerContainer.h>

#include "InsertStatement.h"

namespace database {

class TableBase;
class TableColumnDefinition;
class DatabaseConnection;

/**
 * @brief implements generic sql insert or update statement (also known as upsert).
 * To use upsert statements for a certain table, the table itself has to have at least
 * one (combined) unique key. All values have to filled in correctly, as if you were doing
 * a simple insert. First the row is tried to be inserted, if a unique key collision occures,
 * the affected row is updated.
 * @see database::MySQLInsertOrUpdateStatement
 * @see database::DB2InsertOrUpdateStatement
 */
class InsertOrUpdateStatement : public Statement {
public:
	/**
	 * construct with existing table.
	 * values of existing table are inserted or replaced replaced.
	 * @param tableBase existing table.
	 */
	InsertOrUpdateStatement(TableBase* tableBase);

	virtual ~InsertOrUpdateStatement();

public:
	/**
	 * set values for certain columns to be summed up instead of replacing the old value.
	 * @param colDef column definition for column to be summed up.
	 */
	void AddSumUpColumn (TableColumnDefinition* colDef);

	/**
	 * set values for mulitple columns to be summed up instead of replacing the old value.
	 * @param colDefs list of column definitions for columns to be summed up.
	 */
	void AddSumUpColumns(std::vector<TableColumnDefinition*> colDefs);

	/**
	 * checks if a certain column is a "sum" column.
	 * @param columnName column name to check
	 * @return true if "sum" column, false if not
	 */
	bool IsSumColumn(const std::string& columnName) const;

	/**
	 * gets table base for this statement
	 * @return table base
	 */
	const TableBase* GetConstTableBase() const { return tableBase; }

public:
	virtual InnerJoinCondition& InnerJoin();
	virtual std::string ToSQL( DatabaseConnection* db ) const;

public:
	/**
	 * sum columns
	 */
	tools::PointerContainer<TableColumnDefinition> sumColumns;

protected:
	/**
	 * base table for this statement
	 */
	TableBase* tableBase;
};

}

