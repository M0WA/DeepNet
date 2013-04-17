/**
 * @file TableColumn.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#pragma once

#include <string>
#include <ctime>

#include <StringTools.h>
#include <ContainerTools.h>

#include "TableColumnValue.h"
#include "DatabaseInvalidTypeException.h"

namespace database {

class TableColumnDefinition;

/**
 * @brief implements generic table column.
 * acts as a base class for all columns.
 */
class TableColumn {

private:
	TableColumn(const TableColumn& copyCol);
	TableColumn(TableColumnDefinition* definition);

public:
	virtual ~TableColumn();

public:
	/**
	 * gets column name.
	 * @return column name.
	 */
	const std::string& GetColumnName() const;

	/**
	 * gets const column definition.
	 * @return column definition.
	 */
	const TableColumnDefinition* GetConstColumnDefinition() const;

	/**
	 * gets column definition.
	 * @return column definition.
	 */
	TableColumnDefinition* GetColumnDefinition() { return columnDefinition; }

	/**
	 * copy value from another column.
	 * @param col column to copy from.
	 */
	void CopyValue(const TableColumn* col);

	/**
	 * checks if column has changed.
	 * @return false if unchanged, true if changed.
	 */
	bool IsDirty() const { return isDirty; }

	/**
	 * checks if column has NULL value.
	 * @return false if non-NULL, true if NULL.
	 * @return
	 */
	bool IsNull()  const { return isNull;  }

	/**
	 * sets columns value to NULL (undefined value).
	 */
	void SetNull();

	/**
	 * sets columns value as dirty.
	 */
	void SetDirty();

	/**
	 * sets column value as non-dirty
	 */
	void SetClean();

	/**
	 * sets alias name of column.
	 * @param tableAlias column name alias.
	 */
	void SetColumnAlias(const std::string tableAlias) { this->columnAlias = columnAlias; }

	/**
	 * gets alias name of column.
	 * @return column name alias.
	 */
	const std::string& GetColumnAlias() const { return this->columnAlias; }

	/**
	 * sets the value of the column.
	 * @param value new value.
	 */
	template <class T>
	void Set(const T& value)
	{
		isNull  = false;
		isDirty = true;
		columnValue->Set(value);
	}

	/**
	 * gets the value of the column.
	 * @param out column value.
	 */
	template <class T>
	void Get(T& out) const
	{
		columnValue->Get(out);
	}

	/**
	 * gets the value of the column.
	 * @return column value.
	 */
	template <class T>
	T Get() const
	{
		T out;
		columnValue->Get(out);
		return out;
	}

	/**
	 * gets escaped value of the column.
	 * @return column value.
	 */
	std::string GetForSQL(DatabaseConnection* db) const;

public:
	/**
	 * factory function to create column from string value.
	 * @param colDef column definition.
	 * @param value value of column.
	 * @return NULL on error, table column on success.
	 */
	static TableColumn* CreateInstanceFromValue(const TableColumnDefinition* colDef, const std::string& value);

	/**
	 * factory function to create column from struct tm value.
	 * @param colDef column definition.
	 * @param value value of column.
	 * @return NULL on error, table column on success.
	 */
	static TableColumn* CreateInstanceFromValue(const TableColumnDefinition* colDef, const struct tm& value);

	/**
	 * factory function to create column from long long (int) value.
	 * @param colDef column definition.
	 * @param value value of column.
	 * @return NULL on error, table column on success.
	 */
	static TableColumn* CreateInstanceFromValue(const TableColumnDefinition* colDef, const long long& value);

	/**
	 * factory function to create column from double (decimal) value.
	 * @param colDef column definition.
	 * @param value value of column.
	 * @return NULL on error, table column on success.
	 */
	static TableColumn* CreateInstanceFromValue(const TableColumnDefinition* colDef, const double& value);

	/**
	 * factory function to create multiple columns from a list of values.
	 * @param colDef column definition.
	 * @param values list of new column values.
	 * @return list of created columns.
	 */
	template <class T>
	static std::vector<TableColumn*> CreateInstancesFromValues(const TableColumnDefinition* colDef, const std::vector<T>& values) {

		std::vector<TableColumn*> out;
		typename std::vector<T>::const_iterator iterVal = values.begin();
		for(;iterVal != values.end();++iterVal) {
			out.push_back( CreateInstanceFromValue(colDef, *iterVal) );	}
		return out;
	}

	/**
	 * factory function to create multiple const columns from a list of values.
	 * @param colDef column definition.
	 * @param values list of new column values.
	 * @return list of created columns.
	 */
	template <class T>
	static std::vector<const TableColumn*> CreateConstInstancesFromValues(const TableColumnDefinition* colDef, const std::vector<T>& values) {

		std::vector<const TableColumn*> vecOut;
		tools::ContainerTools::ToConstVector(CreateInstancesFromValues(colDef, values),vecOut);
		return vecOut;
	}

	/**
	 * factory function to create column from a column definition.
	 * @param definition column definition.
	 * @return NULL on error, table column on success.
	 */
	static TableColumn* CreateInstance(TableColumnDefinition* definition);

private:
	void CleanUp();
	void InitFromDefinition();

private:
	TableColumnValue* columnValue;
	TableColumnDefinition* columnDefinition;
	std::string columnAlias;
	bool isNull;
	bool isDirty;

};

}

