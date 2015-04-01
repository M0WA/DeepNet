/**
 * @file WhereConditionTableColumn.h
 * @author Moritz Wagner
 * @date 19.08.2012
 */

#pragma once

#include <string>
#include <vector>

#include "TableColumnArrayContainer.h"
#include "WhereConditionTableColumnCreateParam.h"

namespace database {

	class DatabaseConnection;
	class TableColumn;

/**
 * @brief wrapper for a column in a WhereCondition
 * @see database::WhereCondition
 */
class WhereConditionTableColumn {
private:
	WhereConditionTableColumn(const WhereConditionTableColumn& copy);
	WhereConditionTableColumn(const WhereConditionTableColumnCreateParam& createParam);

public:
	virtual ~WhereConditionTableColumn();

public:
	/**
	 * gets sql equivalent of this operator.
	 * @param db connection.
	 * @return sql string.
	 */
	std::string ToString(DatabaseConnection* db) const;

public:
	/**
	 * factory function creating a new where condition column from a TableColumn value.
	 * @param createParam create parameters.
	 * @param pCol column.
	 * @return
	 */
	static WhereConditionTableColumn* CreateInstance(
			const WhereConditionTableColumnCreateParam& createParam,
			TableColumn* pCol);

	/**
	 * factory function creating a multiple where condition column from multiple values.
	 * @param createParam create parameters.
	 * @param cols column.
	 * @return
	 */
	static WhereConditionTableColumn* CreateInstance(
			const WhereConditionTableColumnCreateParam& createParam,
			const std::vector<TableColumn*>& cols);

public:
	/**
	 * gets where condition operator for this column.
	 * @return where condition operator.
	 */
	const WhereConditionOperator& WhereOp() const { return createParam.op; }

	/**
	 * gets where condition composite operator for this column.
	 * @return where condition composite operator.
	 */
	const WhereConditionCompositeOperator& WhereCompOp() const { return createParam.compOp; }

	/**
	 * gets alias column name.
	 * @return alias column name.
	 */
	const std::string& ColumnAlias() const { return createParam.columnNameAlias; }

	/**
	 * gets alias table name.
	 * @return alias table name.
	 */
	const std::string& TableAlias() const { return createParam.tableNameAlias;  }

private:
	std::string GetColumnValue(DatabaseConnection* db,const TableColumn* col,const bool lowerVal) const;

private:
	TableColumnArrayContainer columnValues;
	WhereConditionTableColumnCreateParam createParam;
};

}

