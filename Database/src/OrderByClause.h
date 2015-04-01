/**
 * @file OrderByClause.h
 * @author Moritz Wagner
 * @date 22.05.2012
 */

#pragma once

#include <vector>
#include <string>

#include "OrderByClauseDirection.h"

namespace database {

class DatabaseConnection;
class TableColumnDefinition;

/**
 * @brief container for all order by related information.
 */
class OrderByColumn {

public:
	/**
	 * table name alias.
	 */
	std::string tableAlias;

	/**
	 * column name alias.
	 */
	std::string columnAlias;

	/**
	 * column definition.
	 */
	TableColumnDefinition* colDef;

	/**
	 * direction for ordering (ascending/descending).
	 */
	OrderByClauseDirection dir;
};

/**
 * @brief implements generic sql "ORDER BY" parts.
 * implements generic sql "ORDER BY" parts for sql statements.
 */
class OrderByClause {
public:
	OrderByClause();
	virtual ~OrderByClause();

	/**
	 * add column to order by.
	 * @param colDef column to order by.
	 * @param dir ascending/descending order.
	 * @return false on error, true on success.
	 */
	bool AddColumn(
			TableColumnDefinition* colDef,
			const OrderByClauseDirection& dir);

	/**
	 * add column to order by using aliases.
	 * @param colDef column to order by.
	 * @param dir ascending/descending order.
	 * @param tableAlias table name alias.
	 * @param columnAlias column name alias.
	 * @return false on error, true on success.
	 */
	bool AddColumn(
		TableColumnDefinition* colDef,
		const OrderByClauseDirection& dir,
		const std::string& tableAlias,
		const std::string& columnAlias);

	/**
	 * gets sql equivalent of this order by part.
	 * @param db database connection.
	 * @return sql string.
	 */
	std::string ToString(database::DatabaseConnection* db) const;

private:
	std::vector<OrderByColumn> orderByFields;
};

}
