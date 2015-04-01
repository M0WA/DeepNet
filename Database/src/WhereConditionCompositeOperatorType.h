/**
 * @file WhereConditionCompositeOperatorType.h
 * @author Moritz Wagner
 * @date 19.08.2012
 */

#pragma once

namespace database {

/**
 * @enum WhereConditionCompositeOperatorType
 * @brief types for where condition composite operators.
 */
enum WhereConditionCompositeOperatorType {

	/**
	 * used for first where condition
	 */
	INITIAL_COMPOSITE_OPERATOR_TYPE,

	/**
	 * sql "AND"
	 */
	AND,

	/**
	 * sql "OR"
	 */
	OR,

	/**
	 * do not use
	 */
	MAX_WHERE_CONDITION_COMPOSITE_OPERATOR_TYPE,
};

}
