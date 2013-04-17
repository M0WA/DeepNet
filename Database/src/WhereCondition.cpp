/**
 * @file WhereCondition.cpp
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#include "WhereCondition.h"

#include <sstream>

#include <Logging.h>
#include <NotImplementedException.h>

#include "TableColumn.h"
#include "WhereConditionTableColumn.h"
#include "DatabaseHelper.h"

#include "DatabaseValueNotSpecifiedException.h"
#include "DatabaseInvalidOperatorTypeException.h"

namespace database {

WhereCondition::WhereCondition() {
}

WhereCondition::WhereCondition(const WhereCondition& copy) {

	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy WhereCondition");
}

WhereCondition::~WhereCondition() {

}

std::string WhereCondition::ToString(database::DatabaseConnection* db) const
{
	if(columns.Size() == 0)
		return "";

	std::stringstream whereCondition;
	columns.ResetIter();
	for(int condCol = 0;!columns.IsIterEnd();columns.Next(), condCol++) {
		whereCondition << columns.GetConstIter()->ToString(db); }

	std::string whereCond = whereCondition.str();
	if(!whereCond.empty()){
		whereCond = " WHERE " + whereCond; }
	return whereCond;
}

}
