/**
 *
 * @file UnitTestDatabase.cpp
 * @author Moritz Wagner
 * @date 15.07.2013
 *
 */

#include "UnitTestDatabase.h"

#include <sstream>

#include <TableDefinition.h>
#include <TableColumnDefinition.h>
#include <TableColumn.h>

namespace toolbot {

UnitTestDatabase::UnitTestDatabase(const database::DatabaseConfig* dbConfig)
: dbConfig(dbConfig) {

	static const size_t nEntriesCount = 20;

	for(size_t i = 1; i <= nEntriesCount; i++) {
		std::stringstream ss;
		ss << i;

		UnitTestDatabaseEntry entry;
		ss >> entry.dDouble;
		ss >> entry.nInteger;
		ss >> entry.varchar_test;

		tools::TimeTools::NowUTCAdd(entry.timestamp,1);
		entries.push_back(entry);
	}
}

UnitTestDatabase::~UnitTestDatabase() {
}

bool UnitTestDatabase::Run() {

	if(!dbHelper.CreateConnection(dbConfig)) {
		log::Logging::LogError("could not connect to database");
		return false;}

	if(!InsertTest<database::unittest1TableBase>()) {
		return false;}

	if(!SelectTest<database::unittest1TableBase>()) {
		return false;}

	if(!UpdateTest()) {
		return false;}

	if(!DeleteTest()) {
		return false;}

	return true;
}

bool UnitTestDatabase::UpdateTest() {

	database::TableBaseUpdateParam paramTbl1;
	paramTbl1.onlyDirtyColumns = true;
	database::unittest1TableBase::GetWhereColumnsFor_double_test(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::InitialComp()),
		1.0,
		paramTbl1.whereCols);

	database::unittest1TableBase updateTbl1;
	updateTbl1.Set_double_test(3.0);
	updateTbl1.Set_varchar_test("3");
	try {
		updateTbl1.Update(dbHelper.Connection(), paramTbl1); }
	catch(database::DatabaseException& ex) {
		log::Logging::LogError("could not update test data:\n%s",ex.Dump().c_str());
		return false; }

	database::TableBaseUpdateParam paramTbl2;
	database::unittest1TableBase::GetWhereColumnsFor_double_test(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::InitialComp()),
		2.0,
		paramTbl2.whereCols);

	database::unittest1TableBase updateTbl2;
	updateTbl2.Set_double_test(4.0);
	updateTbl2.Set_varchar_test("4");
	try {
		updateTbl2.Update(dbHelper.Connection(), paramTbl2); }
	catch(database::DatabaseException& ex) {
		log::Logging::LogError("could not update test data:\n%s",ex.Dump().c_str());
		return false; }

	//
	//TODO: test timestamp and integer columns
	//

	return true;
}

bool UnitTestDatabase::DeleteTest() {

	database::DeleteStatement deleteAll(database::unittest1TableBase::CreateTableDefinition());
	try {
		dbHelper.Connection()->Delete(deleteAll); }
	catch(database::DatabaseException& ex) {
		log::Logging::LogError("could not delete test data:\n%s",ex.Dump().c_str());
		return false; }

	database::TableDefinition* tblDef = database::unittest1TableBase::CreateTableDefinition();
	database::SelectStatement selectRest(tblDef);

	database::TableColumnDefinition* countColDef(
		database::TableColumnDefinition::CreateInstance(
			tblDef->GetColumnDefinitionByName("ID")->GetConstCreateParam() )
	);
	selectRest.SelectAddCountColumn(countColDef,"","");

	database::SelectResultContainer<database::TableBase> results;
	try {
		dbHelper.Connection()->Select(selectRest,results); }
	catch(database::DatabaseException& ex) {
		log::Logging::LogError("could select count for test data:\n%s",ex.Dump().c_str());
		return false; }
	results.ResetIter();

	if(results.Size() != 1) {
		log::Logging::LogError("invalid size while select count for test data: %llu",results.Size());
		return false;}

	const std::vector<database::TableColumn*>& cols(results.GetIter()->GetConstColumns());
	if(cols.size() != 1){
		log::Logging::LogError("invalid column size while select count for test data: %llu",cols.size());
		return false;}

	database::TableColumn* countCol = cols.at(0);

	/*
	const std::string& columnName = countCol->GetColumnName();
	if(!tools::StringTools::CompareCaseInsensitive(columnName,"id")) {
		log::Logging::LogError("invalid column name while select count(%lld) for test data: %s",countRow,columnName.c_str());
		return false; }
	*/

	long long countRow = -1;
	countCol->Get(countRow);

	if(countRow != 0) {
		log::Logging::LogError("invalid count(%lld) while select count for test data",countRow);
		return false; }

	return true;
}

}
