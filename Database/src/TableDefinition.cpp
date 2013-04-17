/**
 * @file TableDefinition.cpp
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#include "TableDefinition.h"

#include "TableColumnDefinition.h"

#include <NotImplementedException.h>
#include "DatabaseNoPrimaryKeyException.h"
#include "DatabaseInvalidColumnNameException.h"

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

const TableColumnDefinition* TableDefinition::GetPrimaryKeyColumnDefinition() const {

	const std::vector< TableColumnDefinition* >& colDefs = GetConstColumnDefinitions();
	std::vector< TableColumnDefinition* >::const_iterator iterColDefs = colDefs.begin();
	for(;iterColDefs != colDefs.end();++iterColDefs) {

		if( (*iterColDefs)->IsPrimaryKey() )
			return (*iterColDefs);
	}

	THROW_EXCEPTION(DatabaseNoPrimaryKeyException);
}

const TableColumnDefinition* TableDefinition::GetConstColumnDefinitionByName(const std::string& columnName) const {

	const std::vector< TableColumnDefinition* >& colDefs = GetConstColumnDefinitions();
	std::vector< TableColumnDefinition* >::const_iterator iterColDefs = colDefs.begin();
	for(;iterColDefs != colDefs.end();++iterColDefs) {

		if( columnName.compare((*iterColDefs)->GetColumnName()) == 0 )
			return (*iterColDefs);
	}

	THROW_EXCEPTION(DatabaseInvalidColumnNameException);
}

}
