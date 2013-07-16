/**
 *
 * @file UnitTestDatabase.cpp
 * @author Moritz Wagner
 * @date 15.07.2013
 *
 */

#include "UnitTestDatabase.h"

#include <sstream>

namespace toolbot {

UnitTestDatabase::UnitTestDatabase(const database::DatabaseConfig* dbConfig)
: dbConfig(dbConfig) {
	//initialize test entries
	static const size_t nEntriesCount(20);
	for(size_t i = 1; i <= nEntriesCount; i++) {
		std::stringstream ss;
		ss << i;

		UnitTestDatabaseEntry entry;
		ss >> entry.dDouble;
		entry.varchar_test = ss.str();
		entry.nInteger = i;
		tools::TimeTools::NowUTCAdd(entry.timestamp,i);
		entries.push_back(entry); }
}

UnitTestDatabase::~UnitTestDatabase() {
}

bool UnitTestDatabase::Run() {

	if(!dbHelper.CreateConnection(dbConfig)) {
		return false;}

	//first of all, cleanup unit test tables
	if(!DeleteAllTest<database::unittest1TableBase>()) {
		return false;}
	if(!DeleteAllTest<database::unittest2TableBase>()) {
		return false;}

	//do simple insert/update/select and delete tests
	if(!InsertTest<database::unittest1TableBase>()) {
		return false;}
	if(!SelectTest<database::unittest1TableBase>()) {
		return false;}
	if(!UpdateTest()) {
		return false;}
	if(!DeleteAllTest<database::unittest1TableBase>()) {
		return false;}

	//do upsert tests
	if(!InsertTest<database::unittest2TableBase>()) {
		return false;}
	if(!UpsertTest()) {
		return false; }
	if(!DeleteAllTest<database::unittest2TableBase>()) {
		return false;}

	//
	//TODO: implement tests for sum columns/order by/group by statements
	//

	return true;
}

bool UnitTestDatabase::UpsertTest() {

	//update by duplicate key test
	database::unittest2TableBase upsertTbl;
	upsertTbl.Set_double_test(2.0);
	upsertTbl.Set_integer_test(2);
	upsertTbl.Set_varchar_test("duplicate key detected");
	upsertTbl.Set_timestamp_test(entries.at(1).timestamp);

	database::SelectResultContainer<database::unittest2TableBase> results;
	long long affectedID(-1);
	try {
		upsertTbl.InsertOrUpdate(dbHelper.Connection());
		dbHelper.Connection()->LastInsertID(affectedID);
		if(affectedID == -1) {
			log::Logging::LogError("invalid id while upsert test: %lld",affectedID);
			return false; }

		database::unittest2TableBase::GetBy_varchar_test(
			dbHelper.Connection(), "duplicate key detected", results);
	}
	catch(database::DatabaseException& e) {
		return false;}

	if(results.Size() != 1) {
		log::Logging::LogError("invalid size while upsert test: %llu",results.Size());
		return false;}
	results.ResetIter();

	long long tmpID(-1);
	results.GetConstIter()->Get_ID(tmpID);
	if(tmpID != affectedID) {
		log::Logging::LogError("invalid table id while upsert test: %lld (should be %lld)",tmpID,affectedID);
		return false; }

	//reset data for duplicate key
	std::vector<database::WhereConditionTableColumn*> whereCols;
	database::unittest2TableBase::GetWhereColumnsFor_double_test(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::InitialComp()),
		2.0,
		whereCols);
	upsertTbl.Set_varchar_test("2");

	long long tmp2ID(-1);
	try {
		upsertTbl.InsertOrUpdate(dbHelper.Connection());
		dbHelper.Connection()->LastInsertID(tmp2ID);
		if(tmp2ID != tmpID) {
			log::Logging::LogError("invalid update table id while upsert test: %lld (should be %lld)",tmpID,tmp2ID);
			return false; }
	}
	catch(database::DatabaseException& e) {
		return false;}

	if(!SelectTest<database::unittest2TableBase>()) {
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

}
