/**
 *
 * @file PostgreSQLInsertStatement.cpp
 * @author Moritz Wagner
 * @date 16.07.2013
 *
 */

#include "PostgreSQLInsertStatement.h"

#include "InsertStatement.h"
#include "TableBase.h"
#include "TableColumnDefinition.h"
#include "TableDefinition.h"

#include "DatabaseConnection.h"

namespace database {

PostgreSQLInsertStatement::PostgreSQLInsertStatement(const InsertStatement& orgStmt)
: orgStmt(orgStmt){
}

PostgreSQLInsertStatement::~PostgreSQLInsertStatement() {
}

std::string PostgreSQLInsertStatement::ToSQL( DatabaseConnection* db ) const {
	const database::TableDefinition* tblDef = orgStmt.GetConstTableBase()->GetConstTableDefinition();
	const database::TableColumnDefinition* priCol = tblDef->GetConstPrimaryKeyColumnDefinition();
	return std::string(orgStmt.ToSQL(db) + " RETURNING " + tblDef->GetFullQualifiedTableName() + "." + priCol->GetColumnName());
}

}
