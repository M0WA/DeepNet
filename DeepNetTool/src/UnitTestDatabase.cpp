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

	static const size_t nEntriesCount = 20;

	for(size_t i = 1; i <= nEntriesCount; i++) {

		UnitTestDatabaseEntry entry;

		std::stringstream ss;
		ss << i;

		ss >> entry.dDouble;
		entry.varchar_test = ss.str();
		entry.nInteger = i;


		tools::TimeTools::NowUTCAdd(entry.timestamp,i);
		entries.push_back(entry);
	}
}

UnitTestDatabase::~UnitTestDatabase() {
}

bool UnitTestDatabase::Run() {

	if(!dbHelper.CreateConnection(dbConfig)) {
		return false;}

	if(!InsertTest<database::unittest1TableBase>()) {
		return false;}

	if(!SelectTest<database::unittest1TableBase>()) {
		return false;}

	if(!UpdateTest()) {
		return false;}

	if(!DeleteAllTest<database::unittest1TableBase>()) {
		return false;}

	//
	//TODO: implement tests for insert-or-update (+sum columns and on duplicate key update....)
	//
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
