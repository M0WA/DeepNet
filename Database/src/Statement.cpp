/**
 * @file Statement.cpp
 * @author Moritz Wagner
 * @date 01.05.2012
 */

#include "Statement.h"
#include "TableDefinition.h"
#include "TableBase.h"

#include <NotImplementedException.h>

namespace database {

Statement::Statement(const StatementType typeIn, const TableBase* tableBase)
: tableAlias(tableBase->GetTableAlias())
, limit(0)
, typeStmt(typeIn)
, tableDefinition(tableBase->GetConstTableDefinition())
{
}

Statement::Statement(const StatementType typeIn, const TableDefinition* tableDefinition)
: tableAlias()
, limit(0)
, typeStmt(typeIn)
, tableDefinition(tableDefinition)
{
}

Statement::Statement(const StatementType typeIn, const TableDefinition* tableDefinition, const std::string& tableAlias)
: tableAlias(tableAlias)
, limit(0)
, typeStmt(typeIn)
, tableDefinition(tableDefinition)
{
}

Statement::Statement(const Statement& copyStmt)
: limit(0)
, typeStmt(copyStmt.typeStmt)
, tableDefinition(0) {

	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy statement");
}

Statement::~Statement()
{
}

const std::string& Statement::TableName(void) const {

	return this->tableDefinition->TableName();
}

const std::string& Statement::DatabaseName(void) const {

	return this->tableDefinition->DatabaseName();
}

std::string Statement::GetFullQualifiedTableName() const {

	return this->tableDefinition->GetFullQualifiedTableName();
}

void Statement::SetLimit(unsigned int limit) {

	this->limit = limit;
}

unsigned int Statement::GetLimit() const {

	return this->limit;
}

const std::string& Statement::TableAlias(void) const {

	return this->tableAlias;
}

const TableDefinition* Statement::GetConstTableDefinition() const {
	return this->tableDefinition;
}

}
