/**
 * @file SelectStatement.h
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#pragma once

#include <vector>
#include <string>
#include <map>

#include "InnerJoinCondition.h"
#include "WhereCondition.h"
#include "OrderByClause.h"
#include "GroupByClause.h"
#include "Statement.h"

namespace database {

class TableColumnDefinition;
class TableDefinition;

/**
 * @brief container for a "selected" column.
 * container for information needed for a "selected" column.
 */
class SelectColumn {
public:
	SelectColumn() : colDef(0), isCountColumn(false), doDelete(true) {}

public:
	/**
	 * column definition.
	 */
	TableColumnDefinition* colDef;

	/**
	 * column alias.
	 */
	std::string columnAlias;

	/**
	 * table alias.
	 */
	std::string tableAlias;

	/**
	 * true if column is a COUNT() column.
	 */
	bool isCountColumn;

	/**
	 * internal state, do not mess with it ;)
	 */
	bool doDelete;
};

/**
 * @brief implements generic sql select statement.
 */
class SelectStatement : public Statement {
public:
	/**
	 * construct with a table definition and a table alias.
	 * the given table definition is used in the "SELECT ... FROM <table>"
	 * part of the statement.
	 * @param definition table definition.
	 * @param tableAlias table name alias.
	 */
	SelectStatement(const TableDefinition* definition, const std::string& tableAlias);

	/**
	 * construct with a table definition.
	 * the given table definition is used in the "SELECT ... FROM <table>"
	 * part of the statement.
	 * @param definition table definition.
	 */
	SelectStatement(const TableDefinition* definition);

	virtual ~SelectStatement();

public:
	/**
	 * selects all columns of statement's table.
	 */
	void SelectAllColumns();

	/**
	 * creates a COUNT(column) column.
	 * @param column column of which count() should be done.
	 * @param tableAlias table alias of column of which count() should be done.
	 * @param columnAlias alias of column of which count() should be done.
	 */
	void SelectAddCountColumn(TableColumnDefinition* column, const std::string& tableAlias, const std::string& columnAlias);

	/**
	 * adds single column.
	 * @param column column to add.
	 */
	void SelectAddColumn(TableColumnDefinition* column);

	/**
	 * adds single column with table- and column alias.
	 * @param column column to be added.
	 * @param tableAlias table alias of column to be added.
	 * @param columnAlias alias of column to be added.
	 */
	void SelectAddColumn(TableColumnDefinition* column, const std::string& tableAlias, const std::string& columnAlias);

	/**
	 * adds single column with column alias.
	 * @param column column to be added.
	 * @param columnAlias alias of column to be added.
	 */
	void SelectAddColumnAlias(TableColumnDefinition* column, const std::string& columnAlias);

public:
	/**
	 * gets where condition of this statement.
	 * @return where condition.
	 */
	inline WhereCondition& Where    (void) { return whereCondition; }

	/**
	 * gets order by clause of this statement.
	 * @return order by clause.
	 */
	inline OrderByClause&  OrderBy  (void) { return orderByClause;  }

	/**
	 * gets group by clause of this statement.
	 * @return group by clause.
	 */
	inline GroupByClause&  GroupBy  (void) { return groupByClause;  }

public:
	virtual inline InnerJoinCondition& InnerJoin(void) { return innerJoin; }
	virtual std::string ToSQL(database::DatabaseConnection* db) const;

private:
	std::string CreateSelectColumnString() const;
	virtual std::string GetColumnAliasString(const std::string& columnAlias) const;

private:
	InnerJoinCondition		 innerJoin;
	WhereCondition           whereCondition;
	OrderByClause            orderByClause;
	GroupByClause			 groupByClause;

	std::vector<SelectColumn> selectColumns;
};

}
