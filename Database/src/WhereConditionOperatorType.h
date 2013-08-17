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

enum WhereConditionWildcardType
{
	WILDCARD_NONE  = 0x00,
	WILDCARD_RIGHT = 0x01,
	WILDCARD_LEFT  = 0x02,
	WILDCARD_BOTH  = 0x03,

	MAX_WHERE_CONDITION_WILDCARD_TYPE = 0xff,
};

}
