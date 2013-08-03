/**
 * @file WhereConditionTableColumn.cpp
 * @author Moritz Wagner
 * @date 19.08.2012
 */

#include "WhereCondition.h"

#include <sstream>

#include "DatabaseHelper.h"

#include "TableColumn.h"
#include "TableColumnContainer.h"
#include "TableColumnDefinition.h"

#include "WhereConditionTableColumn.h"
#include "WhereConditionOperator.h"
#include "WhereConditionCompositeOperator.h"

#include <NotImplementedException.h>
#include "DatabaseNoColumnsException.h"
#include "DatabaseInvalidOperatorTypeException.h"

namespace database {

WhereConditionTableColumn::WhereConditionTableColumn(const WhereConditionTableColumnCreateParam& createParam)
: createParam(createParam){
}

WhereConditionTableColumn::WhereConditionTableColumn(const WhereConditionTableColumn& copy)
: createParam(WhereConditionTableColumnCreateParam(copy.createParam.op,copy.createParam.compOp)) {

	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy WhereConditionTableColumn");
}

WhereConditionTableColumn::~WhereConditionTableColumn() {
}

WhereConditionTableColumn* WhereConditionTableColumn::CreateInstance(
		const WhereConditionTableColumnCreateParam& createParam,
		TableColumn* pCol) {

	WhereConditionTableColumn* pWhereCol = new WhereConditionTableColumn(createParam);
	pWhereCol->columnValues.Add(new TableColumnContainer(pCol));
	return pWhereCol;
}

WhereConditionTableColumn* WhereConditionTableColumn::CreateInstance(
		const WhereConditionTableColumnCreateParam& createParam,
		const std::vector<TableColumn*>& cols) {

	WhereConditionTableColumn* pWhereCol = new WhereConditionTableColumn(createParam);

	std::vector<TableColumn*>::const_iterator iterCols = cols.begin();
	for( ;iterCols != cols.end(); ++iterCols ) {
		pWhereCol->columnValues.Add(new TableColumnContainer((*iterCols))); }

	return pWhereCol;
}

std::string WhereConditionTableColumn::ToString(DatabaseConnection* db) const {

	if(columnValues.Size() == 0)
		THROW_EXCEPTION(DatabaseNoColumnsException);

	std::stringstream columnString;

	if(createParam.compOp.GetType() != INITIAL_COMPOSITE_OPERATOR_TYPE)
		columnString << " " << createParam.compOp.ToString() << " ";

	const TableColumnContainer* const colVal = columnValues.GetConstIter();
	std::string columnName = ( createParam.tableNameAlias.empty() ?	colVal->GetConstColumn()->GetConstColumnDefinition()->GetTableName() : createParam.tableNameAlias) +
		"." + colVal->GetConstColumn()->GetColumnName();

	columnString << " ( ";
	columnValues.ResetIter();
	if(columnValues.Size() == 1) {

		//LIKE keyword is case sensitive for PostGRESQL
		if(database::DatabaseHelper::GetDatabaseType() == database::DB_POSTGRESQL &&
		   createParam.op.GetType() == LIKE){
			columnName = "lower(" + columnName + ")"; }

		std::string opString(createParam.op.ToString());
		if(colVal->GetConstColumn()->IsNull()) {

			switch(createParam.op.GetType()) {

			case EQUALS:
				opString = "IS";
				break;
			case NOT_EQUALS:
				opString = " IS NOT";
				break;

			default:
				THROW_EXCEPTION(DatabaseInvalidOperatorTypeException);
				break;
			}
		}
		columnString << columnName << " " << opString << " " << colVal->GetConstColumn()->GetForSQL(db);
	}
	else if (createParam.op.GetType() != LIKE) {

		columnString << " " << columnName;

		std::string opString;
		switch(createParam.op.GetType()) {

		case EQUALS:
			columnString << " IN ( ";
			break;
		case NOT_EQUALS:
			columnString << " NOT IN ( ";
			break;

		default:
			THROW_EXCEPTION(DatabaseInvalidOperatorTypeException);
			break;
		}

		for(int i = 0;!columnValues.IsIterEnd();columnValues.Next(),i++) {
			if(i)
				columnString << ", ";
			columnString << " " << columnValues.GetConstIter()->GetConstColumn()->GetForSQL(db) << " ";
		}

		columnString << " ) ";
	}
	//listed like
	//needs to be:
	// ...word1 LIKE "bla" OR word1 LIKE "blub"...
	else {

		//LIKE keyword is case sensitive for PostGRESQL
		if(database::DatabaseHelper::GetDatabaseType() == database::DB_POSTGRESQL){
			columnName = "lower(" + columnName + ")"; }

		for(int i = 0;!columnValues.IsIterEnd();columnValues.Next(),i++) {
			if(i)
				columnString << " OR ";
			columnString << " " << columnName << " LIKE " << columnValues.GetConstIter()->GetConstColumn()->GetForSQL(db) << " ";
		}
	}

	columnString << " ) ";
	return columnString.str();
}

}
