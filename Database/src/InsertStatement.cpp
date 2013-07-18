/**
 * @file InsertStatement.cpp
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#include "InsertStatement.h"

#include <sstream>

#include "TableBase.h"
#include "TableColumn.h"

#include "DatabaseNoColumnsException.h"
#include <NotImplementedException.h>

namespace database {

InsertStatement::InsertStatement(TableBase* tableBase)
: Statement(Statement::INSERT_STMT, tableBase)
, tableBase(tableBase) {
}

InsertStatement::~InsertStatement() {
}

std::string InsertStatement::ToSQL(database::DatabaseConnection* db) const {

	const std::vector<TableColumn*> cols = tableBase->GetConstColumns();
	if(cols.size() == 0)
		THROW_EXCEPTION(DatabaseNoColumnsException);

	std::stringstream ssColumnNames, ssColumnValues;
	ssColumnNames  << " ( ";
	ssColumnValues << " ( ";
	std::vector<TableColumn*>::const_iterator iterCols = cols.begin();
	for(int i = 0;iterCols != cols.end();++iterCols) {

		const TableColumn* pCol(*iterCols);

		if(i) {
			ssColumnNames  << ", ";
			ssColumnValues << ", ";	}

		if(!TableAlias().empty())
			ssColumnNames  << TableAlias() << ".";

		ssColumnNames  << pCol->GetColumnName();
		ssColumnValues << pCol->GetForSQL(db);
		i++;
	}
	ssColumnNames  << " ) ";
	ssColumnValues << " ) ";

	std::stringstream ssQuery;
	ssQuery << "INSERT INTO " << GetFullQualifiedTableName() << " " << TableAlias()  << " " << ssColumnNames.str() << " VALUES " << ssColumnValues.str();
	return ssQuery.str();
}

InnerJoinCondition& InsertStatement::InnerJoin() {

	THROW_EXCEPTION(errors::NotImplementedException,"database");
	return *static_cast<InnerJoinCondition*>(0);
}

}
