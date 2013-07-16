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

Statement::Statement(const StatementType typeIn, TableBase* tableBase)
: tableDefinition(tableBase->GetTableDefinition())
, tableAlias(tableBase->GetTableAlias())
, limit(0)
, typeStmt(typeIn)
, deleteDefinition(false)
{
}

Statement::Statement(const StatementType typeIn, TableDefinition* tableDefinition)
: tableDefinition(tableDefinition)
, tableAlias("")
, limit(0)
, typeStmt(typeIn)
, deleteDefinition(true)
{
}

Statement::Statement(const StatementType typeIn, TableDefinition* tableDefinition, const std::string& tableAlias)
: tableDefinition(tableDefinition)
, tableAlias(tableAlias)
, limit(0)
, typeStmt(typeIn)
, deleteDefinition(true)
{
}

Statement::Statement(const Statement& copyStmt) {

	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy statement");
}

Statement::~Statement()
{
	if(deleteDefinition && tableDefinition)
		delete tableDefinition;
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

const std::string& Statement::TableAlias(void) const {

	return this->tableAlias;
}

const TableDefinition* Statement::GetConstTableDefinition() const {
	return this->tableDefinition;
}

}
