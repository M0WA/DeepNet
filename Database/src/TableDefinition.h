/**
 * @file TableDefinition.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#pragma once

#include <vector>
#include <string>
#include "TableDefinitionCreateParam.h"

namespace database {
class TableColumnDefinition;

/**
 * @brief class containing definition of a Tablebase.
 * definition used in Tablebase class.
 */
class TableDefinition {
private:
	TableDefinition(const TableDefinition& copy);

private:
	TableDefinition(const TableDefinitionCreateParam& param);
public:
	virtual ~TableDefinition();

public:
	/**
	 * factory function for a table definition.
	 * @param param create parameters.
	 * @return table definition.
	 */
	static TableDefinition* CreateInstance(const TableDefinitionCreateParam& param);

public:
	/**
	 * gets database name.
	 * @return database name.
	 */
	const std::string& DatabaseName() const { return definition.databaseName; }

	/**
	 * gets table name.
	 * @return table name.
	 */
	const std::string& TableName() const { return definition.tableName; }

	/**
	 * gets const column definitions of this table.
	 * @return column definitions.
	 */
	const std::vector< TableColumnDefinition* >& GetConstColumnDefinitions() const { return definition.columnDefinitions; }

	/**
	 * gets column definitions of this table.
	 * @return column definitions.
	 */
	std::vector<TableColumnDefinition*>& GetColumnDefinitions() { return definition.columnDefinitions; }

	/**
	 * gets const create parameters of this table.
	 * @return create parameters.
	 */
	const TableDefinitionCreateParam& GetConstCreateParam() const { return definition; }

	/**
	 * gets create parameters of this table.
	 * @return create parameters.
	 */
	TableDefinitionCreateParam& GetCreateParam(){ return definition; }

	/**
	 * gets fully qualified table name.
	 * @return fully qualified table name.
	 */
	std::string GetFullQualifiedTableName(void) const;

	/**
	 * gets column definition of this table's primary key.
	 * @return column definition of this table's primary key.
	 */
	const TableColumnDefinition* GetPrimaryKeyColumnDefinition() const;

	/**
	 * gets column definition by name.
	 * @return column definition.
	 */
	const TableColumnDefinition* GetConstColumnDefinitionByName(const std::string& columnName) const;

private:
	TableDefinitionCreateParam definition;
};

}

