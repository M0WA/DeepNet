/**
 * @file WhereConditionCompositeOperator.h
 * @author Moritz Wagner
 * @date 19.08.2012
 */

#pragma once

#include <string>
#include "WhereConditionCompositeOperatorType.h"

namespace database {

/**
 * @brief composite operator container for where conditions.
 */
class WhereConditionCompositeOperator {
public:
	/**
	 * construct from composite operator type.
	 * @param type composite operator type.
	 */
	WhereConditionCompositeOperator(const WhereConditionCompositeOperatorType& type);

	virtual ~WhereConditionCompositeOperator();

public:
	/**
	 * gets sql equivalent of this operator.
	 * @return sql string.
	 */
	std::string ToString(void) const;

	/**
	 * gets type of this composite operator.
	 * @return composite operator type.
	 */
	WhereConditionCompositeOperatorType GetType(void) const;

public:
	/**
	 * converts composite operator type to string
	 * @param op composite operator type.
	 * @return composite operator.
	 */
	static std::string OperatorToString(const WhereConditionCompositeOperatorType& op);

private:
	WhereConditionCompositeOperatorType type;
};

}

