/**
 * @file WhereConditionOperator.cpp
 * @author Moritz Wagner
 * @date 11.08.2012
 */

#include "WhereConditionOperator.h"

#include "DatabaseInvalidOperatorTypeException.h"

namespace database {

WhereConditionOperator::WhereConditionOperator(const WhereConditionOperatorType& type)
: type(type){
}

bool WhereConditionOperator::operator<(const WhereConditionOperator& rhs) const
{
	return (this->type < rhs.type);
}

bool WhereConditionOperator::operator==(const WhereConditionOperator& rhs) const
{
	return (this->type == rhs.type);
}

std::string WhereConditionOperator::ToString(void) const{

	return OperatorToString(type);
}

WhereConditionOperatorType WhereConditionOperator::GetType(void) const {

	return type;
}

std::string WhereConditionOperator::OperatorToString(const WhereConditionOperatorType& op) {

	switch(op)
	{
	case EQUALS:
		return "=";
	case NOT_EQUALS:
		return "!=";
	case GREATER:
		return ">";
	case GREATER_EQUAL:
		return ">=";
	case SMALLER:
		return "<";
	case SMALLER_EQUAL:
		return "<=";
	case LIKE:
		return "LIKE";
	default:
		THROW_EXCEPTION(DatabaseInvalidOperatorTypeException);
	}
}

}
