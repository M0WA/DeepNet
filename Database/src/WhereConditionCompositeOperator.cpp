/**
 * @file WhereConditionCompositeOperator.cpp
 * @author Moritz Wagner
 * @date 19.08.2012
 */

#include "WhereConditionCompositeOperator.h"

#include "DatabaseInvalidOperatorTypeException.h"

namespace database {

WhereConditionCompositeOperator::WhereConditionCompositeOperator(const WhereConditionCompositeOperatorType& type)
: type(type) {
}

WhereConditionCompositeOperator::~WhereConditionCompositeOperator() {
}

std::string WhereConditionCompositeOperator::ToString(void) const {

	return OperatorToString(type);
}

WhereConditionCompositeOperatorType WhereConditionCompositeOperator::GetType(void) const {
	return type;
}

std::string WhereConditionCompositeOperator::OperatorToString(const WhereConditionCompositeOperatorType& op) {

	switch(op) {

	case AND:
		return " AND ";

	case OR:
		return " OR ";

	case INITIAL_COMPOSITE_OPERATOR_TYPE:
		return " ";

	default:
		THROW_EXCEPTION(DatabaseInvalidOperatorTypeException);
	}
}

}
