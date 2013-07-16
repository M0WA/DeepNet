/**
 * @file InsertOrUpdateStatement.cpp
 * @author Moritz Wagner
 * @date 12.08.2012
 */

#include "InsertOrUpdateStatement.h"

#include "InsertStatement.h"
#include "TableBase.h"
#include "TableColumnDefinition.h"

#include <NotImplementedException.h>

namespace database {

InsertOrUpdateStatement::InsertOrUpdateStatement(TableBase* tableBase)
: InsertStatement(tableBase) {

	typeStmt = INSERT_OR_UPDATE_STMT;
}

InsertOrUpdateStatement::~InsertOrUpdateStatement() {
}

std::string InsertOrUpdateStatement::ToSQL( DatabaseConnection* db ) const {

	THROW_EXCEPTION(errors::NotImplementedException,"database");
	return "";
}

void InsertOrUpdateStatement::AddSumUpColumn(TableColumnDefinition* colDef) {

	sumColumns.Add(colDef);
}

void InsertOrUpdateStatement::AddSumUpColumns(std::vector<TableColumnDefinition*> colDefs) {

	sumColumns.Add(colDefs);
}

bool InsertOrUpdateStatement::IsSumColumn(const std::string& columnName) const {

	sumColumns.ResetIter();
	for(;!sumColumns.IsIterEnd();sumColumns.Next()) {
		if(sumColumns.GetConstIter()->GetColumnName().compare(columnName) == 0)
			return true;
	}

	return false;
}

}
