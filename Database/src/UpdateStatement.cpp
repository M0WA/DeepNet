/**
 * @file UpdateStatement.cpp
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#include "UpdateStatement.h"

#include <sstream>

#include "TableColumn.h"
#include "TableBase.h"

#include "DatabaseNoColumnsException.h"
#include <NotImplementedException.h>

namespace database {

UpdateStatement::UpdateStatement(
	TableBase* tableBase,
	const std::vector<WhereConditionTableColumn*>& whereCols,
	const std::vector<OrderByColumn>& orderCols,
	const bool onlyDirty)
: Statement(Statement::UPDATE_STMT, tableBase)
, tableBase(tableBase)
, onlyDirty(onlyDirty) {

	Where().AddColumns(whereCols);

	std::vector<OrderByColumn>::const_iterator iterOrder = orderCols.begin();
	for(;iterOrder != orderCols.end();++iterOrder) {
		OrderBy().AddColumn(
			iterOrder->colDef,
			iterOrder->dir,
			iterOrder->tableAlias,
			iterOrder->columnAlias);
	}
}

UpdateStatement::~UpdateStatement(){
}

std::string UpdateStatement::ToSQL(database::DatabaseConnection* db) const {

	const std::vector<TableColumn*> cols = tableBase->GetConstColumns();
	if(cols.size() == 0)
		THROW_EXCEPTION(DatabaseNoColumnsException);

	std::stringstream ssQuery;
	ssQuery << "UPDATE " << GetFullQualifiedTableName() << " " << TableAlias() << " " << " SET ";

	std::vector< TableColumn* >::const_iterator iterCols = cols.begin();
	for(int i = 0;iterCols != cols.end();++iterCols) {
		const TableColumn* pCol = (*iterCols);
		if ( !onlyDirty || (onlyDirty && pCol->IsDirty()) ) {
			if(i)
				ssQuery << ", ";

			if(!TableAlias().empty())
				ssQuery << TableAlias() << ".";

			ssQuery << pCol->GetColumnName() << " = " << pCol->GetForSQL(db);
			i++;
		}
	}

	ssQuery << whereCondition.ToString(db);
	ssQuery << orderByClause.ToString(db);

	if(limit > 0)
		ssQuery << " LIMIT " << limit;

	return ssQuery.str();
}

InnerJoinCondition& UpdateStatement::InnerJoin() {

	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

}
