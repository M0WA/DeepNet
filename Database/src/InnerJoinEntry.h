/**
 * @file InnerJoinEntry.h
 * @author Moritz Wagner
 * @date 16.08.2012
 */

#pragma once

#include <string>

namespace database {

class TableDefinition;
class TableColumnDefinition;

/**
 * @brief implements container for an inner join condition.
 * container class for all relevant inner join condition information.
 */
class InnerJoinEntry {

public:
	/**
	 * constructs inner join condition.
	 * i.e. "INNER JOIN joinTableDef ON joinTableDef.joinTableColumn = referencedTableDef.referencedColumnDef"
	 * @param joinTableDef table definition for table that should be joined.
	 * @param joinColumnDef column definition for table column that should be joined.
	 * @param referencedTableDef table definition for table that should be used as reference.
	 * @param referencedColumnDef column definition for table column that should be used as reference.
	 */
	InnerJoinEntry(
		database::TableDefinition* joinTableDef,
		database::TableColumnDefinition* joinColumnDef,
		database::TableDefinition* referencedTableDef,
		database::TableColumnDefinition* referencedColumnDef);

	virtual ~InnerJoinEntry();

public:
	/**
	 * gets sql equivalent of this inner join condition.
	 * @return sql string.
	 */
	std::string ToString(void) const;

public:
	/**
	 * table definition for table that should be joined.
	 */
	database::TableDefinition* joinTableDef;

	/**
	 * column definition for table column that should be joined.
	 */
	database::TableColumnDefinition* joinColumnDef;

	/**
	 * table definition for table that should be used as reference.
	 */
	database::TableDefinition* referencedTableDef;

	/**
	 * column definition for table column that should be used as reference.
	 */
	database::TableColumnDefinition* referencedColumnDef;

	/**
	 * alias of joined table.
	 */
	std::string joinTableAlias;

	/**
	 * alias of joined table column.
	 */
	std::string joinColumnAlias;

	/**
	 * alias of referenced table.
	 */
	std::string referencedTableAlias;

	/**
	 * alias of referenced table column.
	 */
	std::string referencedColumnsAlias;
};

}

