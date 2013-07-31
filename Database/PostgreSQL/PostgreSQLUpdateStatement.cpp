/**
 *
 * @file PostgreSQLUpdateStatement.cpp
 * @author Moritz Wagner
 * @date 18.07.2013
 *
 */

#include "PostgreSQLUpdateStatement.h"

#include <sstream>

#include "UpdateStatement.h"
#include "SelectStatement.h"

#include "TableDefinition.h"
#include "TableBase.h"
#include "TableColumn.h"
#include "TableColumnDefinition.h"

#include "PostgreSQLInvalidStatementException.h"

namespace database {

PostgreSQLUpdateStatement::PostgreSQLUpdateStatement(const UpdateStatement& stmt)
: orgStmt(stmt){
}

PostgreSQLUpdateStatement::~PostgreSQLUpdateStatement() {
}

std::string PostgreSQLUpdateStatement::ToSQL(database::DatabaseConnection* db) const {

	//everything is fine except we have some order by columns
	std::string orderByPart(orgStmt.ConstOrderBy().ToString(db));
	if(orderByPart.empty() && orgStmt.GetLimit() == 0) {
		return (orgStmt.ToSQL(db) + " RETURNING *");}

	/*
	 * example:
	 *
UPDATE slots
  FROM (SELECT id FROM slots WHERE user IS NULL
	ORDER BY id LIMIT 1) AS available
   SET user='joe'
 WHERE id = available.id
 RETURNING *;
	 */

	std::string wherePart(orgStmt.ConstWhere().ToString(db));
	if(orgStmt.GetLimit() && wherePart.empty()) {
		THROW_EXCEPTION(PostgreSQLInvalidStatementException,0,"update with order by part has neither LIMIT nor WHERE clause: "+orgStmt.ToSQL(db)); }

	const TableDefinition* tblDef(orgStmt.GetConstTableDefinition());
	const TableColumnDefinition* priCol(tblDef->GetConstPrimaryKeyColumnDefinition());
	database::SelectStatement select(TableDefinition::CreateInstance(tblDef->GetConstCreateParam()));
	select.SelectAddColumn(TableColumnDefinition::CreateInstance(priCol->GetConstCreateParam()));

	std::stringstream ssSelect;
	ssSelect << " ( " <<
		select.ToSQL(db) << " " << wherePart << " " << orderByPart;
	if(orgStmt.GetLimit() > 0)
		ssSelect << " LIMIT " << orgStmt.GetLimit();
	ssSelect << " ) ";

	std::stringstream ssSetValues;
    const std::vector<TableColumn*> cols(orgStmt.tableBase->GetConstColumns());
	std::vector< TableColumn* >::const_iterator iterCols = cols.begin();
	for(int i = 0;iterCols != cols.end();++iterCols) {
		const TableColumn* pCol = (*iterCols);
		if ( !orgStmt.onlyDirty || (orgStmt.onlyDirty && pCol->IsDirty()) ) {
			if(i)
				ssSetValues << ", ";

			if(!orgStmt.TableAlias().empty())
				ssSetValues << orgStmt.TableAlias() << ".";

			ssSetValues << pCol->GetColumnName() << " = " << pCol->GetForSQL(db);
			i++;
		}
	}

	std::string updateTableAlias(orgStmt.TableAlias());
	if(updateTableAlias.empty())
		updateTableAlias = "OV";

	std::stringstream updateQuery;
	updateQuery << " \
UPDATE " << tblDef->GetFullQualifiedTableName() << " " << updateTableAlias << " \
SET " << ssSetValues.str() << " \
FROM " << ssSelect.str() << " as AV  \
WHERE " << updateTableAlias << "." << priCol->GetColumnName() << "=AV." << priCol->GetColumnName() << " RETURNING " << "AV.*";

	return updateQuery.str();
}

}
