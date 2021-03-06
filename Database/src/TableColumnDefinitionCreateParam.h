/**
 * @file TableColumnDefinitionCreateParam.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#pragma once

#include <string>
#include "TableColumnType.h"

namespace database {

/**
 * @brief create parameters for column definitions.
 * @see database::TableColumnDefinition
 */
class TableColumnDefinitionCreateParam {
public:
	TableColumnDefinitionCreateParam();
	virtual ~TableColumnDefinitionCreateParam();

	/**
	 * data type of column
	 */
	TableColumnType columnType;

	/**
	 * column name
	 */
	std::string columnName;

	/**
	 * table name
	 */
	std::string  tableName;

	/**
	 * database name
	 */
	std::string databaseName;

	/**
	 * primary key
	 */
	bool isPrimaryKey;

	/**
	 * column value is generated on insert (i.e. auto increment etc.)
	 */
	bool isAutoGenerated;

	/**
	 * column has a foreign key constraint
	 */
	bool isForeignKey;

	/**
	 * column has an unique key constraint
	 */
	bool isUniqueKey;

	/**
	 * column is part of a multi column unique key constraint
	 */
	bool isCombinedUniqueKey;

	/**
	 * column is indexed
	 */
	bool isIndex;

	/**
	 * column is nullable
	 */
	bool isNullable;

	/**
	 * column has a default value
	 */
	bool hasDefaultValue;

	/**
	 * max. data size (0: unlimited)
	 */
	size_t dataSize;
};

}
