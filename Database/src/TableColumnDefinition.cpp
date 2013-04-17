/**
 * @file TableColumnDefinition.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#include "TableColumnDefinition.h"

#include <NotImplementedException.h>

namespace database {

TableColumnDefinition::TableColumnDefinition(const TableColumnDefinitionCreateParam& param)
: definition(param){
}

TableColumnDefinition::TableColumnDefinition(const TableColumnDefinition& copy){

	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy TableColumnDefinition");
}

TableColumnDefinition::~TableColumnDefinition() {
}

TableColumnDefinition* TableColumnDefinition::CreateInstance(const TableColumnDefinitionCreateParam& param) {
	return new TableColumnDefinition(param);
}

bool TableColumnDefinition::IsNullable(void) const {

	if(definition.isNullable)
		return true;

	if(definition.hasDefaultValue)
		return true;

	if(definition.isAutoGenerated)
		return true;

	return false;
}

bool TableColumnDefinition::IsIndex(void) const {

	if(definition.isPrimaryKey)
		return true;

	if(definition.isForeignKey)
		return true;

	if(definition.isUniqueKey)
		return true;

	if(definition.isIndex)
		return true;

	return false;
}

}
