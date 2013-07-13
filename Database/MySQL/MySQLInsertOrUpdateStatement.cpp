/**
 * @file MySQLInsertOrUpdateStatement.cpp
 * @author Moritz Wagner
 * @date 01.05.2012
 */

#include "MySQLInsertOrUpdateStatement.h"

#include <sstream>

#include "TableBase.h"
#include "TableDefinition.h"
#include "TableColumn.h"
#include "TableColumnDefinition.h"

#include "InsertOrUpdateStatement.h"

#include "DatabaseNoColumnsException.h"
#include "DatabaseInvalidColumnNameException.h"
#include "DatabaseNoPrimaryKeyException.h"

namespace database {

MySQLInsertOrUpdateStatement::MySQLInsertOrUpdateStatement(const InsertOrUpdateStatement* stmt)
: orgStatement(stmt) {
}

MySQLInsertOrUpdateStatement::~MySQLInsertOrUpdateStatement() {
}

std::string MySQLInsertOrUpdateStatement::ToSQL( DatabaseConnection* db ) const {

	const TableBase* tableBase = orgStatement->GetConstTableBase();
	const std::vector<TableColumn*>& cols = tableBase->GetConstColumns();
	if(cols.size() == 0)
		THROW_EXCEPTION(DatabaseNoColumnsException);

	const TableColumnDefinition* primaryKeyDef = tableBase->GetConstTableDefinition()->GetConstPrimaryKeyColumnDefinition();
	if(!primaryKeyDef) {
		THROW_EXCEPTION(database::DatabaseNoPrimaryKeyException);}
	const std::string& primaryKeyColumnName = primaryKeyDef->GetColumnName();

	std::stringstream ssQuery;
	ssQuery <<
		orgStatement->InsertStatement::ToSQL(db) << " ON DUPLICATE KEY UPDATE " <<
		primaryKeyColumnName << " = LAST_INSERT_ID( " << primaryKeyColumnName << " ) ";

	const std::vector< TableColumnDefinition* >& colDefs = tableBase->GetConstTableDefinition()->GetConstColumnDefinitions();
	std::vector< TableColumnDefinition* >::const_iterator iterReplace = colDefs.begin();
	for(;iterReplace != colDefs.end();++iterReplace) {

		const TableColumnDefinition* pColDef = (*iterReplace);
		const std::string& columnName = pColDef->GetColumnName();

		if(columnName.compare(primaryKeyColumnName) == 0)
			continue;

		if(!orgStatement->IsSumColumn(columnName)) {
			ssQuery << ", " << columnName << " = VALUES( " << columnName << " ) ";
		}
	}

	std::vector< TableColumnDefinition* >::const_iterator iterSum = orgStatement->sumColumns.begin();
	for(;iterSum != orgStatement->sumColumns.end();++iterSum) {
		const std::string& sumColumnName = (*iterSum)->GetColumnName();

		if(sumColumnName.compare(primaryKeyColumnName) == 0)
			THROW_EXCEPTION(DatabaseInvalidColumnNameException);

		ssQuery << ", " << sumColumnName << " = " << sumColumnName << " + VALUES( " << sumColumnName << " ) ";
	}

	return ssQuery.str();
}

}
