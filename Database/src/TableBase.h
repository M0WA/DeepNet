/**
 * @file TableBase.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#pragma once

#include <string>
#include <vector>

#include "UpdateStatement.h"

namespace database {

class TableColumn;
class TableColumnDefinition;
class TableDefinition;
class TableDefinitionCreateParam;
class TableBaseUpdateParam;
class DatabaseConnection;

/**
 * @brief parameters used for update statements.
 * @see database::TableBase::Update
 */
class TableBaseUpdateParam {
public:
	TableBaseUpdateParam()
	: onlyDirtyColumns(true)
	, limit(0)
	{}

public:
	/**
	 * where conditions.
	 */
	std::vector<WhereConditionTableColumn*> whereCols;

	/**
	 * order by clauses.
	 */
	std::vector<OrderByColumn> orderCols;

	/**
	 * true: only update columns that changed.
	 */
	bool onlyDirtyColumns;

	/**
	 * maximum number of affected rows.
	 * used in "LIMIT" part of sql statement.
	 */
	int limit;
};

/**
 * @brief implements generic table row class.
 * acts as a base class for all tables rows.
 */
class TableBase {

protected:
	/**
	 * construct empty table row.
	 */
	TableBase();

	/**
	 * construct from table definition.
	 * @param definition table definition.
	 */
	TableBase(TableDefinition* definition);

private:
	TableBase(const TableBase& base);

public:
	virtual ~TableBase();

	/**
	 * gets const table definition.
	 * @return table definition.
	 */
	const TableDefinition* GetConstTableDefinition() const;

	/**
	 * gets table definition.
	 * @return table definition.
	 */
	TableDefinition* GetTableDefinition();

	/**
	 * finds column by it's name.
	 * @param columnName column name.
	 * @return NULL if not found, column otherwise.
	 */
	const TableColumn* GetConstColumnByName(std::string columnName) const;

	/**
	 * finds column by it's name.
	 * @param columnName column name.
	 * @return NULL if not found, column otherwise.
	 */
	TableColumn* GetColumnByName(std::string columnName);

	/**
	 * gets list of columns.
	 * @return list of columns.
	 */
	std::vector< TableColumn* >&       GetColumns();

	/**
	 * gets const list of columns.
	 * @return list of columns.
	 */
	const std::vector< TableColumn* >& GetConstColumns() const;

	/**
	 * sets alias name.
	 * @param tableAlias table name alias.
	 */
	void SetTableAlias(const std::string& tableAlias) { this->tableAlias = tableAlias; }

	/**
	 * gets alias name.
	 * @return tableAlias table name alias.
	 */
	const std::string& GetTableAlias() const { return this->tableAlias; }

	/**
	 * inserts this table.
	 * @param db database connection.
	 */
	void Insert(DatabaseConnection* db);

	/**
	 * inserts or updates this table.
	 * @param db database connection.
	 */
	void InsertOrUpdate(DatabaseConnection* db);

	/**
	 * inserts or updates this table adding SUM()-type columns.
	 * @param db database connection.
	 * @param sumColumn columns to replace with sum instead of new value.
	 */
	void InsertOrUpdate(
			DatabaseConnection* db,
			TableColumnDefinition* sumColumn);

	/**
	 * inserts or updates this table adding SUM()-type columns.
	 * @param db database connection.
	 * @param sumColumn columns to replace with sum instead of new value.
	 */
	void InsertOrUpdate(
			DatabaseConnection* db,
			const std::vector< TableColumnDefinition*>& sumColumn);

	/**
	 * updates this table.
	 * @param db database connection.
	 * @param param update parameters.
	 */
	void Update(
			DatabaseConnection* db,
			const TableBaseUpdateParam& param) const;

public:
	/**
	 * factory function for this class.
	 * @param param table definition creation parameter.
	 * @return NULL on error, table base on success.
	 */
	static TableBase* CreateInstance(const TableDefinitionCreateParam& param);

public:
	/**
	 * copies column definitions and values from another table.
	 * @param base table to copy from.
	 */
	void CopyColumns(const TableBase* base);

protected:
	/**
	 * creates columns according to database::TableBase::definition.
	 */
	void CreateColumns();

private:
	static void StartTransaction(DatabaseConnection* db);
	static void CommitTransaction(DatabaseConnection* db);
	static void RollbackTransaction(DatabaseConnection* db);

private:
	void CleanUp();
	void CheckInitialization() const;

private:
	TableDefinition* definition;
	std::vector<TableColumn*> columns;
	std::string tableAlias;
};

}

