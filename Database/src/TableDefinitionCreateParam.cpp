/**
 * @file TableDefinitionCreateParam.cpp
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#include "TableDefinitionCreateParam.h"
#include "TableColumnDefinition.h"

namespace database {

TableDefinitionCreateParam::TableDefinitionCreateParam(const std::string& databaseName, const std::string& tableName)
: databaseName(databaseName)
, tableName(tableName) { }

TableDefinitionCreateParam::TableDefinitionCreateParam(const TableDefinitionCreateParam& copy)
: databaseName(copy.databaseName)
, tableName(copy.tableName)
, combinedUniqueKeys(copy.combinedUniqueKeys){
	CopyColumns(copy);
}

TableDefinitionCreateParam::~TableDefinitionCreateParam() {

	std::vector<TableColumnDefinition*>::iterator iter = columnDefinitions.begin();
	for(;iter != columnDefinitions.end();++iter) {
		delete (*iter);	}
	columnDefinitions.clear();
}

void TableDefinitionCreateParam::CopyColumns(const TableDefinitionCreateParam& copy) {

	const std::vector<TableColumnDefinition*>& colDefs = copy.columnDefinitions;
	std::vector<TableColumnDefinition*>::const_iterator iterCopyDef = colDefs.begin();
	for(;iterCopyDef != colDefs.end();++iterCopyDef) {
		TableColumnDefinition* copyColDef = *iterCopyDef;
		const TableColumnDefinitionCreateParam& paramCopyCol = copyColDef->GetConstCreateParam();
		TableColumnDefinitionCreateParam paramNewCol = paramCopyCol;
		columnDefinitions.push_back(TableColumnDefinition::CreateInstance(paramNewCol));
	}
}

}
