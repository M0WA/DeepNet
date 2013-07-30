/**
 * @file TableDefinitionCreateParam.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */


#pragma once

#include <vector>
#include <string>

namespace database {
class TableColumnDefinition;

/**
 * @brief create parameters for table definitions.
 * @see database::TableDefinition
 */
class TableDefinitionCreateParam {
public:
	/**
	 * construct from existing definition.
	 * @param copy copy source.
	 */
	TableDefinitionCreateParam(const TableDefinitionCreateParam& copy);

	/**
	 * construct by database and table name.
	 * @param databaseName database name.
	 * @param tableName table name.
	 */
	TableDefinitionCreateParam(const std::string& databaseName, const std::string& tableName);
	virtual ~TableDefinitionCreateParam();

public:
	/**
	 * database name.
	 */
	std::string databaseName;

	/**
	 * table name.
	 */
	std::string tableName;

	/**
	 * column definitions.
	 */
	std::vector<TableColumnDefinition*> columnDefinitions;

	/**
	 * column names of combined unique keys
	 */
	std::vector< std::vector<std::string> > combinedUniqueKeys;

private:
	void CopyColumns(const TableDefinitionCreateParam& copy);
};

}

