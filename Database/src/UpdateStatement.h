/**
 * @file UpdateStatement.h
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#pragma once

#include <string>
#include <vector>

#include "WhereCondition.h"
#include "OrderByClause.h"
#include "Statement.h"

namespace database {

class TableBase;
class TableColumn;
class DatabaseConnection;
class PostgreSQLUpdateStatement;

/**
 * @brief implements generic sql update statement.
 */
class UpdateStatement : public Statement {

	friend class PostgreSQLUpdateStatement;

public:
	/**
	 * construct update statement.
	 * @param tableBase table for update statement
	 * @param whereCols where columns and their conditions
	 * @param orderCols orderby columns
	 * @param onlyDirty update dirty values only
	 */
	UpdateStatement(
		const TableBase* tableBase,
		const std::vector<WhereConditionTableColumn*>& whereCols,
		const std::vector<OrderByColumn>& orderCols,
		const bool onlyDirty);

	virtual ~UpdateStatement();

	/**
	 * gets where condition.
	 * @return where clause.
	 */
	WhereCondition& Where  () { return this->whereCondition; }

	/**
	 * gets const where condition.
	 * @return where clause.
	 */
	const WhereCondition& ConstWhere() const { return this->whereCondition; }

	/**
	 * gets order by clause.
	 * @return order by clause.
	 */
	OrderByClause&  OrderBy() { return this->orderByClause;  }

	/**
	 * gets const order by clause.
	 * @return order by clause.
	 */
	const OrderByClause& ConstOrderBy() const { return this->orderByClause;  }

public:
	virtual InnerJoinCondition& InnerJoin();
	virtual std::string ToSQL(database::DatabaseConnection* db) const;

private:
	WhereCondition         whereCondition;
	OrderByClause          orderByClause;

	const TableBase*	   tableBase;
	bool  onlyDirty;
};

}
