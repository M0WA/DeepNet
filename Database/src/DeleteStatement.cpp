/**
 * @file DeleteStatement.cpp
 * @author Moritz Wagner
 * @date 04.05.2012
 */

#include "DeleteStatement.h"

#include <sstream>

#include <NotImplementedException.h>

namespace database {

DeleteStatement::DeleteStatement(const TableDefinition* tableDefinition)
: Statement(Statement::DELETE_STMT, tableDefinition)
{
}

DeleteStatement::~DeleteStatement()
{
}

std::string DeleteStatement::ToSQL(database::DatabaseConnection* db) const
{
	std::stringstream ssSQL;
	ssSQL << "DELETE FROM " << GetFullQualifiedTableName() << " " << TableAlias();

	std::string whereConditionSQL = whereCondition.ToString(db);
	if(!whereConditionSQL.empty())
		ssSQL << " " << whereConditionSQL;

	return ssSQL.str();
}

InnerJoinCondition& DeleteStatement::InnerJoin() {

	THROW_EXCEPTION(errors::NotImplementedException,"database");
	return *static_cast<InnerJoinCondition*>( 0 );
}

}
