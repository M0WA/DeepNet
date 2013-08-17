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
	WhereConditionTableColumnCreateParam(
		const WhereConditionOperator& op,
		const WhereConditionCompositeOperator& compOp);

	/**
	 * construct using operator, composite operator and a wildcarded value.
	 * @param op operator.
	 * @param compOp composite operator.
	 * @param wildcard wildcard type.
	 */
	WhereConditionTableColumnCreateParam(
		const WhereConditionOperator& op,
		const WhereConditionCompositeOperator& compOp,
		const WhereConditionWildcardType& wildcardFlag);

	/**
	 * construct using operator, composite operator, a wildcarded value and a table alias.
	 * @param op operator.
	 * @param compOp composite operator.
	 * @param wildcard wildcard type.
	 * @param tableAlias table alias.
	 */
	WhereConditionTableColumnCreateParam(
		const WhereConditionOperator& op,
		const WhereConditionCompositeOperator& compOp,
		const WhereConditionWildcardType& wildcardFlag,
		const std::string& tableAlias);

	/**
	 * construct using operator, composite operator and table alias.
	 * @param op operator.
	 * @param compOp composite operator.
	 * @param tableAlias table alias.
	 */
	WhereConditionTableColumnCreateParam(
		const WhereConditionOperator& op,
		const WhereConditionCompositeOperator& compOp,
		const std::string& tableAlias);

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
	 * wildcard type.
	 */
	WhereConditionWildcardType wildcardFlag;

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

