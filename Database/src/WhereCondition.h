/**
 * @file WhereCondition.h
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#pragma once

#include <string>
#include <vector>

#include "WhereConditionOperator.h"
#include "WhereConditionCompositeOperator.h"
#include "WhereConditionTableColumnContainer.h"

namespace database {

class TableColumn;
class WhereConditionTableColumn;
class DatabaseConnection;

/**
 * @brief container for WHERE conditions of an sql statement.
 */
class WhereCondition {
private:
	WhereCondition(const WhereCondition& copy);

public:
	WhereCondition();
	virtual ~WhereCondition();

public:
	static WhereConditionOperator Equals() { return WhereConditionOperator(EQUALS); }
	static WhereConditionOperator NotEquals() { return WhereConditionOperator(NOT_EQUALS); }
	static WhereConditionOperator Greater() { return WhereConditionOperator(GREATER); }
	static WhereConditionOperator GreaterOrEqual() { return WhereConditionOperator(GREATER_EQUAL); }
	static WhereConditionOperator Smaller() { return WhereConditionOperator(SMALLER); }
	static WhereConditionOperator SmallerOrEqual() { return WhereConditionOperator(SMALLER_EQUAL); }
	static WhereConditionOperator Like() { return WhereConditionOperator(LIKE); }

	static WhereConditionCompositeOperator InitialComp() { return WhereConditionCompositeOperator(INITIAL_COMPOSITE_OPERATOR_TYPE); }
	static WhereConditionCompositeOperator And() { return WhereConditionCompositeOperator(AND); }
	static WhereConditionCompositeOperator Or() { return WhereConditionCompositeOperator(OR);  }

public:
	/**
	 * add a where condition for a column
	 * @param col where condition for column.
	 */
	void AddColumn(WhereConditionTableColumn* col) { columns.Add(col); }

	/**
	 * add multiple where conditions for multiple columns.
	 * @param cols where conditions columns.
	 */
	void AddColumns(const std::vector<WhereConditionTableColumn*>& cols) { columns.Add(cols); }

	/**
	 * gets sql equivalent of where conditions for this statement.
	 * @param db database connection.
	 * @return sql string.
	 */
	std::string ToString(database::DatabaseConnection* db) const;

private:
	WhereConditionTableColumnContainer columns;
};

}
