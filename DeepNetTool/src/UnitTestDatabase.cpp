/**
 *
 * @file UnitTestDatabase.cpp
 * @author Moritz Wagner
 * @date 15.07.2013
 *
 */

#include "UnitTestDatabase.h"

#include <DatabaseLayer.h>
#include <DatabaseHelper.h>
#include <DatabaseException.h>

#include <TableDefinition.h>
#include <TableColumn.h>

#include <Logging.h>
#include <TimeTools.h>

namespace toolbot {

UnitTestDatabase::UnitTestDatabase(const database::DatabaseConfig* dbConfig)
: dbConfig(dbConfig) {
}

UnitTestDatabase::~UnitTestDatabase() {
}

bool UnitTestDatabase::Run() {

	if(!dbHelper.CreateConnection(dbConfig,false)) {
		log::Logging::LogError("could not connect to database");
		return false;}

	if(!InsertTest()) {
		return false;}

	if(!UpdateTest()) {
		return false;}

	if(!SelectTest()) {
		return false;}

	if(!DeleteTest()) {
		return false;}

	return true;
}

bool UnitTestDatabase::InsertTest() {

	database::unittest1TableBase insertTbl;
	insertTbl.Set_timestamp_test(tools::TimeTools::NowUTC());
	insertTbl.Set_double_test(1.0);
	insertTbl.Set_varchar_test("1");
	try {
		insertTbl.Insert(dbHelper.Connection()); }
	catch(database::DatabaseException& ex) {
		log::Logging::LogError("could not insert test data:\n%s",ex.Dump().c_str());
		return false; }

	insertTbl.Set_timestamp_test(tools::TimeTools::NowUTC());
	insertTbl.Set_double_test(2.0);
	insertTbl.Set_varchar_test("2");
	try {
		insertTbl.Insert(dbHelper.Connection()); }
	catch(database::DatabaseException& ex) {
		log::Logging::LogError("could not insert test data:\n%s",ex.Dump().c_str());
		return false; }

	long long insertID = -1,insertIDTbl = -1;
	dbHelper.Connection()->LastInsertID(insertID);
	insertTbl.Get_ID(insertIDTbl);

	if(insertID == -1 || insertIDTbl == -1) {
		log::Logging::LogError("could not determine last inserted id: %lld,%lld",
			insertID,insertIDTbl);
		return false; }

	if(insertID != insertIDTbl) {
		log::Logging::LogError("last inserted id did not match: %lld,%lld",
			insertID,insertIDTbl);
		return false; }

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
		paramTbl1.whereCols);

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
	selectRest.SelectAddCountColumn(tblDef->GetColumnDefinitionByName("ID"),"pid","");

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
	const std::string& columnName = countCol->GetColumnName();

	long long countRow = -1;
	countCol->Get(countRow);

	if(!tools::StringTools::CompareCaseInsensitive(columnName,"pid")) {
		log::Logging::LogError("invalid column name while select count(%lld) for test data: %s",countRow,columnName.c_str());
		return false; }

	if(countRow != 0) {
		log::Logging::LogError("invalid count(%lld) while select count for test data",countRow);
		return false; }

	return true;
}

bool UnitTestDatabase::SelectTest() {

	database::SelectResultContainer<database::unittest1TableBase> results1;

	try {
		database::unittest1TableBase::GetBy_double_test(dbHelper.Connection(),3.0,results1);
	}
	catch(database::DatabaseException& ex) {
		log::Logging::LogError("could not select test data:\n%s",ex.Dump().c_str());
		return false; }

	if(results1.Size() != 1) {
		log::Logging::LogError("invalid size while selecting data (3.0): %llu",results1.Size());
		return false;}
	results1.ResetIter();

	double dTest1 = 0.0;
	results1.GetIter()->Get_double_test(dTest1);
	if(dTest1 != 3.0) {
		log::Logging::LogError("invalid data while select double_test: %f (should be 3.0)",dTest1);
		return false; }

	std::string sTest1;
	results1.GetIter()->Get_varchar_test(sTest1);
	if(sTest1.compare("3") != 0) {
		log::Logging::LogError("invalid data while select varchar_test: %s (should be '3')",sTest1.c_str());
		return false; }

	database::SelectResultContainer<database::unittest1TableBase> results2;
	try {
		database::unittest1TableBase::GetBy_double_test(dbHelper.Connection(),4.0,results2); }
	catch(database::DatabaseException& ex) {
		log::Logging::LogError("could not select test data:\n%s",ex.Dump().c_str());
		return false; }

	if(results2.Size() != 1) {
		log::Logging::LogError("invalid size while selecting data (4.0): %llu",results2.Size());
		return false;}
	results2.ResetIter();

	double dTest2 = 0.0;
	results2.GetIter()->Get_double_test(dTest2);
	if(dTest2 != 4.0) {
		log::Logging::LogError("invalid data while select double_test: %f (should be 4.0)",dTest2);
		return false; }

	std::string sTest2;
	results2.GetIter()->Get_varchar_test(sTest2);
	if(sTest2.compare("4") != 0) {
		log::Logging::LogError("invalid data while select varchar_test: %s (should be '4')",sTest2.c_str());
		return false; }

	//////////////////////////////////////////
	//
	//TODO: test timestamp and integer columns
	//
	//////////////////////////////////////////

	database::SelectStatement selectAll(database::unittest1TableBase::CreateTableDefinition());
	selectAll.SelectAllColumns();

	database::SelectResultContainer<database::unittest1TableBase> results3;
	try {
		dbHelper.Connection()->Select(selectAll,results3); }
	catch(database::DatabaseException& ex) {
		log::Logging::LogError("could not select test data:\n%s",ex.Dump().c_str());
		return false; }

	return true;
}

}
