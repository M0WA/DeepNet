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

#include "PostgreSQLInvalidStatementException.h"

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

	const TableBase* tableBase(stmt.GetConstTableBase());
	const TableDefinition* tblDef(tableBase->GetConstTableDefinition());
	const TableColumnDefinition* pPriColDef(tblDef->GetConstPrimaryKeyColumnDefinition());

	SelectAddColumn(TableColumnDefinition::CreateInstance(pPriColDef->GetConstCreateParam()));
}

void PostgreSQLInsertOrUpdateAffectedKeyStatement::InitWhereClause() {

	const TableBase* tableBase(stmt.GetConstTableBase());
	const TableDefinition* tblDef(tableBase->GetConstTableDefinition());

	const std::vector<TableColumn*>& cols(tableBase->GetConstColumns());
	std::vector<TableColumn*>::const_iterator iCols(cols.begin());

	size_t i(0);
	for(;iCols != cols.end();++iCols) {
		const TableColumn* pCurCol(*iCols);
		const std::string& curColName(pCurCol->GetColumnName());
		const TableColumnDefinition* pCurColDef(tblDef->GetConstColumnDefinitionByName(curColName));

		//add unique columns to where clauses
		if(!pCurColDef->IsUniqueKey() || pCurColDef->IsPrimaryKey()) {
			continue; }

		TableColumn* pWhereCol(TableColumn::CreateInstance(
			TableColumnDefinition::CreateInstance(pCurColDef->GetConstCreateParam())
		));

		pWhereCol->SetDirty();
		pWhereCol->CopyValue(pCurCol);

		WhereConditionCompositeOperator compOp(WhereCondition::Or());
		if(i == 0)
			compOp = WhereCondition::InitialComp();

		WhereConditionTableColumnCreateParam createParam(
			WhereCondition::Equals(), compOp );

		Where().AddColumn(WhereConditionTableColumn::CreateInstance(createParam,pWhereCol));
		i++;
	}

	std::vector<std::vector<const TableColumnDefinition*> > colsCombined(tblDef->GetConstCombinedUniqueKeyColumnDefinitions());
	std::vector<std::vector<const TableColumnDefinition*> >::const_iterator iCombined(colsCombined.begin());
	for(;iCombined!=colsCombined.end();++iCombined) {

		if(iCombined->size() < 2) {
			THROW_EXCEPTION(PostgreSQLInvalidStatementException,0,"too few columns for combined unique key"); }

		WhereConditionCompositeOperator compOp(i ? WhereCondition::Or() : WhereCondition::InitialComp());

		std::vector<const TableColumnDefinition*>::const_iterator iColCom(iCombined->begin());
		for(;iColCom!=iCombined->end();++iColCom) {

			const TableColumn* curCol(tableBase->GetConstColumnByName((*iColCom)->GetColumnName()));

			WhereConditionTableColumnCreateParam createParam(
				WhereCondition::Equals(), compOp );

			TableColumn* pWhereCol(TableColumn::CreateInstance(
				TableColumnDefinition::CreateInstance((*iColCom)->GetConstCreateParam())
			));

			pWhereCol->SetDirty();
			pWhereCol->CopyValue(curCol);

			WhereConditionTableColumn* whereCol(
				WhereConditionTableColumn::CreateInstance(
					createParam,
					pWhereCol)
			);
			Where().AddColumn(whereCol);

			compOp=WhereCondition::And();
		}
	}
}

}
