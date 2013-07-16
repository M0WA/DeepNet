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
 * @see database::MySQLInsertOrUpdateStatement
 * @see database::DB2InsertOrUpdateStatement
 */
class InsertOrUpdateStatement : public InsertStatement {
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

public:
	virtual std::string ToSQL( DatabaseConnection* db ) const;

public:
	tools::PointerContainer<TableColumnDefinition> sumColumns;
};

}

