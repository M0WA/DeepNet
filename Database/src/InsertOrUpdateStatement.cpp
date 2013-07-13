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
	std::vector< TableColumnDefinition* >::iterator iterSum = sumColumns.begin();
	for(;iterSum != sumColumns.end();++iterSum) {
		delete (*iterSum);}
	sumColumns.clear();
}

std::string InsertOrUpdateStatement::ToSQL( DatabaseConnection* db ) const {

	THROW_EXCEPTION(errors::NotImplementedException,"database");
	return "";
}

void InsertOrUpdateStatement::AddSumUpColumn(TableColumnDefinition* colDef) {

	sumColumns.push_back(colDef);
}

void InsertOrUpdateStatement::AddSumUpColumns(std::vector<TableColumnDefinition*> colDefs) {

	sumColumns.insert(sumColumns.end(),colDefs.begin(),colDefs.end());
}

bool InsertOrUpdateStatement::IsSumColumn(const std::string& columnName) const {

	std::vector< TableColumnDefinition* >::const_iterator iterSum = sumColumns.begin();
	for(;iterSum != sumColumns.end();++iterSum) {
		if((*iterSum)->GetColumnName().compare(columnName) == 0)
			return true;
	}

	return false;
}

}
