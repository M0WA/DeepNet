/**
 * @file TableColumn.cpp
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#include "DatabaseTypes.h"
#include "DatabaseConnection.h"

#include "TableColumn.h"
#include "TableColumnDefinition.h"
#include "TableColumnValue.h"
#include "TableColumnValueTyped.h"

#include <NotImplementedException.h>
#include "DatabaseInvalidTypeException.h"
#include "DatabaseNotNullableException.h"
#include "DatabaseNotInitializedException.h"

namespace database {

TableColumn::TableColumn(TableColumnDefinition* definition)
: columnValue(0)
, columnDefinition(definition)
, isNull(true)
, isDirty(false)
{
}

TableColumn::TableColumn(const TableColumn& copyCol)
{
	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy TableColumn()");
}

TableColumn::~TableColumn() {
	CleanUp();
}

void TableColumn::CleanUp() {

	switch(columnDefinition->GetColumnType())
	{
	case DB_TYPE_BIGINT:
	case DB_TYPE_INTEGER:
		delete dynamic_cast< TableColumnValueTyped<long long>* >(columnValue);
		break;

	case DB_TYPE_DOUBLE:
		delete dynamic_cast< TableColumnValueTyped<double>* >(columnValue);
		break;

	case DB_TYPE_VARCHAR:
	case DB_TYPE_CHAR:
	case DB_TYPE_LARGE_TEXT:
		delete dynamic_cast< TableColumnValueTyped<std::string>* >(columnValue);
		break;

	case DB_TYPE_TIMESTAMP:
		delete dynamic_cast< TableColumnValueTyped<struct tm>* >(columnValue);
		break;

	default:
		delete columnValue;
		THROW_EXCEPTION(DatabaseInvalidTypeException);
		break;
	}

	if(columnDefinition) {
		delete columnDefinition; }
	columnDefinition = 0;
}

TableColumn* TableColumn::CreateInstance(TableColumnDefinition* definition){

	TableColumn* pColumn(new TableColumn(definition));
	pColumn->InitFromDefinition();
	return pColumn;
}

TableColumn* TableColumn::CreateInstanceFromValue(const TableColumnDefinition* colDef, const std::string& value) {

	TableColumnType type(colDef->GetColumnType());
	if( type != DB_TYPE_VARCHAR && type != DB_TYPE_CHAR && type != DB_TYPE_LARGE_TEXT) {
		THROW_EXCEPTION(DatabaseInvalidTypeException);}

	const TableColumnDefinitionCreateParam& createParam(colDef->GetConstCreateParam());
	TableColumnDefinition* pNewDef(TableColumnDefinition::CreateInstance(createParam));
	TableColumn* pNewCol(TableColumn::CreateInstance(pNewDef));
	pNewCol->Set(value);
	return pNewCol;
}

TableColumn* TableColumn::CreateInstanceFromValue(const TableColumnDefinition* colDef, const struct tm& value) {

	if(colDef->GetColumnType() != DB_TYPE_TIMESTAMP) {
		THROW_EXCEPTION(DatabaseInvalidTypeException);}

	const TableColumnDefinitionCreateParam& createParam(colDef->GetConstCreateParam());
	TableColumnDefinition* pNewDef(TableColumnDefinition::CreateInstance(createParam));
	TableColumn* pNewCol(TableColumn::CreateInstance(pNewDef));
	pNewCol->Set(value);
	return pNewCol;
}

TableColumn* TableColumn::CreateInstanceFromValue(const TableColumnDefinition* colDef, const long long& value) {

	if(colDef->GetColumnType() != DB_TYPE_INTEGER && colDef->GetColumnType() != DB_TYPE_BIGINT) {
		THROW_EXCEPTION(DatabaseInvalidTypeException);}

	const TableColumnDefinitionCreateParam& createParam(colDef->GetConstCreateParam());
	TableColumnDefinition* pNewDef(TableColumnDefinition::CreateInstance(createParam));
	TableColumn* pNewCol(TableColumn::CreateInstance(pNewDef));
	pNewCol->Set(value);
	return pNewCol;
}

TableColumn* TableColumn::CreateInstanceFromValue(const TableColumnDefinition* colDef, const double& value) {

	if(colDef->GetColumnType() != DB_TYPE_DOUBLE) {
		THROW_EXCEPTION(DatabaseInvalidTypeException);}

	const TableColumnDefinitionCreateParam& createParam(colDef->GetConstCreateParam());
	TableColumnDefinition* pNewDef(TableColumnDefinition::CreateInstance(createParam));
	TableColumn* pNewCol(TableColumn::CreateInstance(pNewDef));
	pNewCol->Set(value);
	return pNewCol;
}

void TableColumn::SetNull() {

	if(!GetConstColumnDefinition()->IsNullable())
		THROW_EXCEPTION(DatabaseNotNullableException);

	isNull = isDirty = true;
}

void TableColumn::SetDirty() {

	isDirty = true;
}

void TableColumn::SetClean() {

	isDirty = false;
}

const TableColumnDefinition* TableColumn::GetConstColumnDefinition() const {

	return columnDefinition;
}

const std::string& TableColumn::GetColumnName() const {

	return GetConstColumnDefinition()->GetColumnName();
}

std::string TableColumn::GetForSQL(DatabaseConnection* db) const {

	if(isNull) {
		return "NULL"; }
	return columnValue->GetForSQL(db);
}

void TableColumn::InitFromDefinition() {

	const TableColumnType& type(columnDefinition->GetColumnType());
	switch(type)
	{
	case DB_TYPE_BIGINT:
	case DB_TYPE_INTEGER:
		columnValue = new TableColumnValueTyped<long long>(type);
		break;

	case DB_TYPE_DOUBLE:
		columnValue = new TableColumnValueTyped<double>(type);
		break;

	case DB_TYPE_VARCHAR:
	case DB_TYPE_CHAR:
	case DB_TYPE_LARGE_TEXT:
		columnValue = new TableColumnValueTyped<std::string>(type);
		break;

	case DB_TYPE_TIMESTAMP:
		columnValue = new TableColumnValueTyped<struct tm>(type);
		break;

	default:
		THROW_EXCEPTION(DatabaseInvalidTypeException);
		break;
	}

	if(columnDefinition->IsAutoGenerated()) {
		SetNull();
		SetClean(); }
}

void TableColumn::CopyValue(const TableColumn* copyCol) {

	TableColumnType typeCopy(copyCol->columnDefinition->GetColumnType());
	if(typeCopy == DB_TYPE_CHAR || typeCopy == DB_TYPE_LARGE_TEXT) {
		typeCopy = DB_TYPE_VARCHAR;	}

	TableColumnType typeNew(columnDefinition->GetColumnType());
	if(typeNew == DB_TYPE_CHAR || typeNew == DB_TYPE_LARGE_TEXT) {
		typeNew = DB_TYPE_VARCHAR; }

	if(typeCopy != typeNew)
		THROW_EXCEPTION(DatabaseInvalidTypeException);

	if(copyCol->IsNull()) {
		SetNull();
	}
	else {
		isNull = false;
		switch(columnDefinition->GetColumnType())
		{
		case DB_TYPE_BIGINT:
		case DB_TYPE_INTEGER:
			columnValue->Set(copyCol->Get<long long>());
			break;

		case DB_TYPE_DOUBLE:
			columnValue->Set(copyCol->Get<double>());
			break;

		case DB_TYPE_VARCHAR:
		case DB_TYPE_CHAR:
		case DB_TYPE_LARGE_TEXT:
			columnValue->Set(copyCol->Get<std::string>());
			break;

		case DB_TYPE_TIMESTAMP:
			columnValue->Set(copyCol->Get<struct tm>());
			break;

		default:
			THROW_EXCEPTION(DatabaseInvalidTypeException);
			break;
		}
	}
}

}
