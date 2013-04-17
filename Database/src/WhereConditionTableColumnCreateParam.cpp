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
, compOp(compOp){
}

WhereConditionTableColumnCreateParam::~WhereConditionTableColumnCreateParam() {
}

}
