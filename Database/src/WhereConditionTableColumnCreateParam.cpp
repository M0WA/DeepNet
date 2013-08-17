/**
 * @file WhereConditionTableColumnCreateParam.cpp
 * @author Moritz Wagner
 * @date 19.08.2012
 */

#include "WhereConditionTableColumnCreateParam.h"

namespace database {

WhereConditionTableColumnCreateParam::WhereConditionTableColumnCreateParam(
	const WhereConditionOperator& op,
	const WhereConditionCompositeOperator& compOp)
: op(op)
, compOp(compOp)
, wildcardFlag(WILDCARD_NONE) {
}

WhereConditionTableColumnCreateParam::WhereConditionTableColumnCreateParam(
	const WhereConditionOperator& op,
	const WhereConditionCompositeOperator& compOp,
	const std::string& tableAlias)
: op(op)
, compOp(compOp)
, wildcardFlag(WILDCARD_NONE)
, tableNameAlias(tableAlias){
}

WhereConditionTableColumnCreateParam::WhereConditionTableColumnCreateParam(
	const WhereConditionOperator& op,
	const WhereConditionCompositeOperator& compOp,
	const WhereConditionWildcardType& wildcardFlag)
: op(op)
, compOp(compOp)
, wildcardFlag(wildcardFlag) {
}

WhereConditionTableColumnCreateParam::WhereConditionTableColumnCreateParam(
	const WhereConditionOperator& op,
	const WhereConditionCompositeOperator& compOp,
	const WhereConditionWildcardType& wildcardFlag,
	const std::string& tableAlias)
: op(op)
, compOp(compOp)
, wildcardFlag(wildcardFlag)
, tableNameAlias(tableAlias) {
}

WhereConditionTableColumnCreateParam::~WhereConditionTableColumnCreateParam() {
}

}
