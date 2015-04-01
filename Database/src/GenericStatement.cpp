/**
 * @file GenericStatement.cpp
 * @author Moritz Wagner
 * @date 01.05.2012
 */

#include "GenericStatement.h"

#include <NotImplementedException.h>

namespace database {

GenericStatement::GenericStatement(const StatementType typeIn, const std::string& query)
: Statement(typeIn, (TableDefinition*)0)
, query(query)
{
}

GenericStatement::~GenericStatement()
{
}

std::string GenericStatement::ToSQL(database::DatabaseConnection* db) const
{
	return query;
}

InnerJoinCondition& GenericStatement::InnerJoin() {

	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

}
