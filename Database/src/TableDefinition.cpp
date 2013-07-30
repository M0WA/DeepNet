/**
 * @file TableDefinition.cpp
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#include "TableDefinition.h"

#include "DatabaseHelper.h"
#include "TableColumnDefinition.h"

#include "DatabaseNoPrimaryKeyException.h"
#include "DatabaseInvalidColumnNameException.h"

#include <StringTools.h>

#include <NotImplementedException.h>

namespace database {

TableDefinition::TableDefinition(const TableDefinitionCreateParam& param)
: definition(param){
}

TableDefinition::TableDefinition(const TableDefinition& copy)
: definition(copy.definition){

	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy table definition");
}

TableDefinition::~TableDefinition() {
}

TableDefinition* TableDefinition::CreateInstance(const TableDefinitionCreateParam& param) {

	return new TableDefinition(param);
}

std::string TableDefinition::GetFullQualifiedTableName(void) const {
	return (DatabaseName().empty() ? TableName() :  DatabaseName()+"."+TableName());
}

std::vector< const TableColumnDefinition* > TableDefinition::GetConstUniqueKeyColumnDefinitions() const {

	std::vector< const TableColumnDefinition* > out;

	const std::vector< TableColumnDefinition* >& colDefs = GetConstColumnDefinitions();
	std::vector< TableColumnDefinition* >::const_iterator iterColDefs = colDefs.begin();
	for(;iterColDefs != colDefs.end();++iterColDefs) {
		if( (*iterColDefs)->IsUniqueKey() )
			out.push_back(*iterColDefs);
	}
	return out;
}

std::vector<std::vector< const TableColumnDefinition* > > TableDefinition::GetConstCombinedUniqueKeyColumnDefinitions() const {

	std::vector<std::vector< const TableColumnDefinition* > > defs;
	std::vector<std::vector<std::string> >::const_iterator i(definition.combinedUniqueKeys.begin());
	for(;i != definition.combinedUniqueKeys.end();++i) {
		std::vector< const TableColumnDefinition* > keyDefs;
		std::vector<std::string>::const_iterator k(i->begin());
		for(;k != i->end(); ++k) {
			keyDefs.push_back(GetConstColumnDefinitionByName(*k));
		}
		defs.push_back(keyDefs);
	}
	return defs;
}

const TableColumnDefinition* TableDefinition::GetConstPrimaryKeyColumnDefinition() const {

	const std::vector< TableColumnDefinition* >& colDefs = GetConstColumnDefinitions();
	std::vector< TableColumnDefinition* >::const_iterator iterColDefs = colDefs.begin();
	for(;iterColDefs != colDefs.end();++iterColDefs) {

		if( (*iterColDefs)->IsPrimaryKey() )
			return (*iterColDefs);
	}

	THROW_EXCEPTION(DatabaseNoPrimaryKeyException);
	return 0;
}

TableColumnDefinition* TableDefinition::GetColumnDefinitionByName(std::string columnName) {

	switch(DatabaseHelper::GetDatabaseType())
	{
	case DB_POSTGRESQL:
		tools::StringTools::ToLowerIP(columnName);
		break;
	default:
		break;
	}

	std::vector< TableColumnDefinition* >& colDefs = GetColumnDefinitions();
	std::vector< TableColumnDefinition* >::iterator iterColDefs = colDefs.begin();
	for(;iterColDefs != colDefs.end();++iterColDefs) {

		if( columnName.compare((*iterColDefs)->GetColumnName()) == 0 )
			return (*iterColDefs);
	}

	THROW_EXCEPTION(DatabaseInvalidColumnNameException);
	return 0;
}

const TableColumnDefinition* TableDefinition::GetConstColumnDefinitionByName(std::string columnName) const {
	switch(DatabaseHelper::GetDatabaseType())
	{
	case DB_POSTGRESQL:
		tools::StringTools::ToLowerIP(columnName);
		break;
	default:
		break;
	}

	const std::vector< TableColumnDefinition* >& colDefs = GetConstColumnDefinitions();
	std::vector< TableColumnDefinition* >::const_iterator iterColDefs = colDefs.begin();
	for(;iterColDefs != colDefs.end();++iterColDefs) {

		if( columnName.compare((*iterColDefs)->GetColumnName()) == 0 )
			return (*iterColDefs);
	}

	THROW_EXCEPTION(DatabaseInvalidColumnNameException);
	return 0;
}

}
