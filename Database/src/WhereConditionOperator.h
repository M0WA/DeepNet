/**
 * @file WhereConditionOperator.h
 * @author Moritz Wagner
 * @date 11.08.2012
 */

#pragma once

#include <string>
#include "WhereConditionOperatorType.h"

namespace database {

/**
 * @brief operator container for where conditions.
 */
class WhereConditionOperator
{
public:
	/**
	 * constructs operator from type.
	 * @param type operator type.
	 */
	WhereConditionOperator(const WhereConditionOperatorType& type);

	bool operator<(const WhereConditionOperator& rhs) const;
	bool operator==(const WhereConditionOperator& rhs) const;

public:
	/**
	 * gets textual representation.
	 * @return operator as string.
	 */
	std::string ToString(void) const;

	/**
	 * gets oeprator type.
	 * @return operator type.
	 */
	WhereConditionOperatorType GetType(void) const;

public:
	/**
	 * converts operator type to string
	 * @param op operator type
	 * @return operator string.
	 */
	static std::string OperatorToString(const WhereConditionOperatorType& op);

private:
	WhereConditionOperatorType type;
};

}

