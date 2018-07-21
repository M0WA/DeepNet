/*
 * TableBase.cpp
 *
 *  Created on: 10.08.2012
 *      Author: Moritz Wagner
 */

#include "TableBase.h"

#include "TableColumnDefinition.h"
#include "TableColumn.h"
#include "TableDefinition.h"

#include "InsertStatement.h"
#include "InsertOrUpdateStatement.h"
#include "UpdateStatement.h"

#include "DatabaseHelper.h"
#include "DatabaseConnection.h"

#include "DatabaseNotInitializedException.h"
#include "DatabaseInvalidColumnNameException.h"

#include <NotImplementedException.h>

namespace database {

TableBase::TableBase(TableDefinition* definition)
: definition(definition) {
	CreateColumns();
}

TableBase::TableBase()
: definition(0){
}

TableBase::TableBase(const TableBase& base)
: definition(0) {
	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy TableBase");
}

TableBase::~TableBase() {
	CleanUp();
}

void TableBase::CleanUp() {
	std::vector<TableColumn*>::iterator iterColumns(columns.begin());
	for(;iterColumns != columns.end();++iterColumns) {
		delete (*iterColumns); }
	columns.clear();

	if(definition)
		delete definition;
	definition = 0;
}

void TableBase::CreateColumns() {

	const std::vector<TableColumnDefinition*>& definitions(definition->GetColumnDefinitions());
	std::vector<TableColumnDefinition*>::const_iterator iterDefs(definitions.begin());
	for(;iterDefs != definitions.end();++iterDefs) {
		TableColumnDefinition* defNew = TableColumnDefinition::CreateInstance((*iterDefs)->GetConstCreateParam());
		columns.push_back(TableColumn::CreateInstance(defNew)); }
}

TableBase* TableBase::CreateInstance(const TableDefinitionCreateParam& param) {

	return new TableBase(TableDefinition::CreateInstance(param));
}

std::vector<TableColumn*>& TableBase::GetColumns() {

	CheckInitialization();
	return columns;
}

const std::vector<TableColumn*>& TableBase::GetConstColumns() const {

	CheckInitialization();
	return columns;
}

const TableDefinition* TableBase::GetConstTableDefinition() const {

	CheckInitialization();
	return definition;
}

TableDefinition* TableBase::GetTableDefinition() {

	CheckInitialization();
	return definition;
}

const TableColumn* TableBase::GetConstColumnByName(std::string columnName) const {

	CheckInitialization();

	switch(DatabaseHelper::GetDatabaseType())
	{
	case DB_POSTGRESQL:
		tools::StringTools::ToLowerIP(columnName);
		break;
	default:
		break;
	}

	std::vector<TableColumn*>::const_iterator iterColumns(columns.begin());
	for(;iterColumns != columns.end();++iterColumns) {
		if((*iterColumns)->GetConstColumnDefinition()->GetColumnName().compare(columnName) == 0){
			return (*iterColumns); }
	}

	THROW_EXCEPTION(DatabaseInvalidColumnNameException,columnName);
	return 0;
}

TableColumn* TableBase::GetColumnByName(std::string columnName) {

	CheckInitialization();

	switch(DatabaseHelper::GetDatabaseType())
	{
	case DB_POSTGRESQL:
		tools::StringTools::ToLowerIP(columnName);
		break;
	default:
		break;
	}

	std::vector<TableColumn*>::iterator iterColumns(columns.begin());
	for(;iterColumns != columns.end();++iterColumns) {
		if((*iterColumns)->GetConstColumnDefinition()->GetColumnName().compare(columnName) == 0){
			return (*iterColumns); }
	}

	THROW_EXCEPTION(DatabaseInvalidColumnNameException,columnName);
	return 0;
}

void TableBase::CopyColumns(const TableBase* base) {

	CheckInitialization();

	std::vector<TableColumn*>::const_iterator iterColumns(columns.begin());
	for(;iterColumns != columns.end();++iterColumns) {
		const std::string& colName((*iterColumns)->GetConstColumnDefinition()->GetColumnName());
		const TableColumn* oldCol(base->GetConstColumnByName(colName));
		(*iterColumns)->CopyValue(oldCol);
	}
}

void TableBase::CheckInitialization() const {

	if(definition == 0)
		THROW_EXCEPTION(DatabaseNotInitializedException);

	if(columns.size() == 0)
		THROW_EXCEPTION(DatabaseNotInitializedException);
}

void TableBase::StartTransaction(DatabaseConnection* db) {
	db->TransactionStart();
}

void TableBase::CommitTransaction(DatabaseConnection* db) {
	db->TransactionCommit();
}

void TableBase::RollbackTransaction(DatabaseConnection* db) {
	db->TransactionRollback();
}

void TableBase::Insert(DatabaseConnection* db) {

	CheckInitialization();

	InsertStatement insertStmt(this);
	db->Insert(insertStmt);
}

void TableBase::InsertOrUpdate(DatabaseConnection* db) {

	InsertOrUpdate(db,std::vector< TableColumnDefinition* >());
}

void TableBase::InsertOrUpdate(
		DatabaseConnection* db,
		TableColumnDefinition* sumColumn) {

	CheckInitialization();

	InsertOrUpdateStatement insertOrUpdateStmt(this);
	insertOrUpdateStmt.AddSumUpColumn( sumColumn );
	db->InsertOrUpdate(insertOrUpdateStmt);
}

void TableBase::InsertOrUpdate(
		DatabaseConnection* db,
		const std::vector< TableColumnDefinition* >& sumColumn) {

	CheckInitialization();

	InsertOrUpdateStatement insertOrUpdateStmt(this);
	insertOrUpdateStmt.AddSumUpColumns( sumColumn );
	db->InsertOrUpdate(insertOrUpdateStmt);
}

void TableBase::Update(
		DatabaseConnection* db,
		const TableBaseUpdateParam& param) const {

	CheckInitialization();

	UpdateStatement updateStmt(
		const_cast<TableBase*>(this),
		param.whereCols,
		param.orderCols,
		param.onlyDirtyColumns);
	if(param.limit > 0)
		updateStmt.SetLimit(param.limit);
	db->Update(updateStmt);
}

}
