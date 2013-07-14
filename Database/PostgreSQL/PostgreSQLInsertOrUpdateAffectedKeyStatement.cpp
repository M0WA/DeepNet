/**
 *
 * @file PostgreSQLInsertOrUpdateAffectedKeyStatement.cpp
 * @author Moritz Wagner
 * @date 14.07.2013
 *
 */

#include "PostgreSQLInsertOrUpdateAffectedKeyStatement.h"

#include "InsertOrUpdateStatement.h"

#include "TableDefinition.h"
#include "TableBase.h"
#include "TableColumn.h"
#include "TableColumnDefinition.h"

#include "WhereConditionTableColumn.h"
#include "WhereConditionTableColumnCreateParam.h"

namespace database {

PostgreSQLInsertOrUpdateAffectedKeyStatement::PostgreSQLInsertOrUpdateAffectedKeyStatement(const InsertOrUpdateStatement& stmt)
: database::SelectStatement(TableDefinition::CreateInstance(stmt.GetConstTableBase()->GetConstTableDefinition()->GetConstCreateParam()))
, stmt(stmt){
	InitSelectedFields();
	InitWhereClause();
}

PostgreSQLInsertOrUpdateAffectedKeyStatement::~PostgreSQLInsertOrUpdateAffectedKeyStatement() {
}

void PostgreSQLInsertOrUpdateAffectedKeyStatement::InitSelectedFields() {

	const TableBase* tableBase = stmt.GetConstTableBase();
	const TableDefinition* tblDef = tableBase->GetConstTableDefinition();
	const TableColumnDefinition* pPriColDef = tblDef->GetConstPrimaryKeyColumnDefinition();

	SelectAddColumn(TableColumnDefinition::CreateInstance(pPriColDef->GetConstCreateParam()));
}

void PostgreSQLInsertOrUpdateAffectedKeyStatement::InitWhereClause() {

	const TableBase* tableBase = stmt.GetConstTableBase();
	const TableDefinition* tblDef = tableBase->GetConstTableDefinition();

	const std::vector<TableColumn*>& cols = tableBase->GetConstColumns();
	std::vector<TableColumn*>::const_iterator iCols = cols.begin();
	for(size_t i = 0;iCols != cols.end();++iCols) {

		const TableColumn* pCurCol = (*iCols);
		const std::string& curColName = pCurCol->GetColumnName();
		const TableColumnDefinition* pCurColDef = tblDef->GetConstColumnDefinitionByName(curColName);

		//add unique columns to where clauses
		if(!pCurColDef->IsUniqueKey() || pCurColDef->IsPrimaryKey()) {
			continue; }

		TableColumn* pWhereCol = TableColumn::CreateInstance(
			TableColumnDefinition::CreateInstance(pCurColDef->GetConstCreateParam())
		);

		pWhereCol->SetDirty();
		pWhereCol->CopyValue(pCurCol);

		WhereConditionCompositeOperator compOp = WhereCondition::Or();
		if(i == 0)
			compOp = WhereCondition::InitialComp();

		WhereConditionTableColumnCreateParam createParam(
			WhereCondition::Equals(), compOp );

		Where().AddColumn(WhereConditionTableColumn::CreateInstance(createParam,pWhereCol));
		i++;
	}
}

}
