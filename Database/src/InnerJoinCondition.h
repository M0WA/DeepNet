/**
 * @file InnerJoinCondition.h
 * @author Moritz Wagner
 * @date 20.06.2012
 */

#pragma once

#include <string>
#include <vector>

#include "InnerJoinEntry.h"

namespace database {

class DatabaseConnection;
class TableDefinition;
class TableColumnDefinition;

/**
 * @brief implements generic sql "INNER JOIN" parts.
 * implements generic sql "INNER JOIN" parts for sql statements.
 */
class InnerJoinCondition {

public:
	InnerJoinCondition();
	virtual ~InnerJoinCondition();

	/**
	 * adds an inner join.
	 * i.e. "INNER JOIN joinTableDef ON joinTableDef.joinTableColumn = referencedTableDef.referencedColumnDef"
	 * @param joinTableDef table definition for table that should be joined.
	 * @param joinColumnDef column definition for table column that should be joined.
	 * @param referencedTableDef table definition for table that should be used as reference.
	 * @param referencedColumnDef column definition for table column that should be used as reference.
	 */
	void AddInnerJoin(
		database::TableDefinition* joinTableDef,
		database::TableColumnDefinition* joinColumnDef,
		database::TableDefinition* referencedTableDef,
		database::TableColumnDefinition* referencedColumnDef );

	/**
	 * adds an inner join using aliases for both tables.
	 * i.e. "INNER JOIN joinTableDef ON joinTableDef.joinTableColumn = referencedTableDef.referencedColumnDef"
	 * @param joinTableDef table definition for table that should be joined.
	 * @param joinColumnDef column definition for table column that should be joined.
	 * @param referencedTableDef table definition for table that should be used as reference.
	 * @param referencedColumnDef column definition for table column that should be used as reference.
	 * @param joinTableAlias alias of joined table.
	 * @param joinColumnAlias alias of joined table column.
	 * @param referencedTableAlias alias of referenced table.
	 * @param referencedColumnsAlias alias of referenced table column.
	 */
	void AddInnerJoin(
		database::TableDefinition* joinTableDef,
		database::TableColumnDefinition* joinColumnDef,
		database::TableDefinition* referencedTableDef,
		database::TableColumnDefinition* referencedColumnDef,
		const std::string& joinTableAlias,
		const std::string& joinColumnAlias,
		const std::string& referencedTableAlias,
		const std::string& referencedColumnsAlias );

	/**
	 * adds an inner join.
	 * @param entry prepared inner join entry.
	 */
	void AddInnerJoin(const InnerJoinEntry& entry) { entries.push_back(entry); }

	/**
	 * gets sql equivalent of this inner join part containing all added inner join entries.
	 * @param db database connection.
	 * @return sql string.
	 */
	std::string ToString(DatabaseConnection* db) const;

private:
	std::vector<InnerJoinEntry> entries;
};

}
