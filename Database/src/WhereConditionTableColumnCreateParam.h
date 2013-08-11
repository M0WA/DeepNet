/**
 * @file WhereConditionTableColumnCreateParam.h
 * @author Moritz Wagner
 * @date 19.08.2012
 */

#pragma once

#include <string>

#include "WhereConditionOperator.h"
#include "WhereConditionCompositeOperator.h"

namespace database {

/**
 * @brief create parameters for where columns.
 * @see database::WhereCondition
 */
class WhereConditionTableColumnCreateParam {
public:
	/**
	 * construct using operator and composite operator.
	 * @param op operator.
	 * @param compOp composite operator.
	 */
	WhereConditionTableColumnCreateParam(const WhereConditionOperator& op, const WhereConditionCompositeOperator& compOp);

	/**
	 * construct using operator, composite operator and table alias.
	 * @param op operator.
	 * @param compOp composite operator.
	 * @param tableAlias table alias
	 */
	WhereConditionTableColumnCreateParam(const WhereConditionOperator& op, const WhereConditionCompositeOperator& compOp, const std::string& tableAlias);

	virtual ~WhereConditionTableColumnCreateParam();

public:
	/**
	 * condition operator.
	 */
	WhereConditionOperator op;

	/**
	 * composite operator.
	 */
	WhereConditionCompositeOperator compOp;

	/**
	 * alias column name.
	 */
	std::string columnNameAlias;

	/**
	 * alias table name.
	 */
	std::string tableNameAlias;
};

}

