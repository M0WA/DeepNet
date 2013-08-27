#pragma once

namespace database {

enum WhereConditionOperatorType
{
	EQUALS,
	NOT_EQUALS,
	GREATER,
	GREATER_EQUAL,
	SMALLER,
	SMALLER_EQUAL,
	LIKE,

	MAX_WHERE_CONDITION_OPERATOR_TYPE //do not use
};

}
