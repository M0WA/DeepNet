/**
 *
 * @file UnitTestDatabase.cpp
 * @author Moritz Wagner
 * @date 15.07.2013
 *
 */

#include "UnitTestDatabase.h"

#include <sstream>
#include <algorithm>

#include <FileTools.h>

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

	log::Logging::LogTrace("cleaning up tables used for unit tests");
	if(!DeleteAllTest<database::unittest3TableBase>()) {
		return false;}
	if(!DeleteAllTest<database::unittest1TableBase>()) {
		return false;}
	if(!DeleteAllTest<database::unittest2TableBase>()) {
		return false;}

	log::Logging::LogTrace("testing simple insert/update/select and delete");
	if(!InsertTest<database::unittest1TableBase>()) {
		return false;}
	if(!SelectTest<database::unittest1TableBase>()) {
		return false;}
	if(!UpdateTest()) {
		return false;}
	if(!DeleteAllTest<database::unittest1TableBase>()) {
		return false;}

	log::Logging::LogTrace("testing upserts (insert-or-update)");
	if(!InsertTest<database::unittest2TableBase>()) {
		return false;}
	if(!UpsertTest()) {
		return false; }
	if(!DeleteAllTest<database::unittest2TableBase>()) {
		return false;}

	log::Logging::LogTrace("testing inner joins");
	if(!InsertTest<database::unittest1TableBase>()) {
		return false;}
	if(!InsertTest<database::unittest2TableBase>()) {
		return false;}
	if(!InnerJoinTest()) {
		return false;}
	if(!DeleteAllTest<database::unittest3TableBase>()) {
		return false;}
	if(!DeleteAllTest<database::unittest1TableBase>()) {
		return false;}
	if(!DeleteAllTest<database::unittest2TableBase>()) {
		return false;}

	log::Logging::LogTrace("testing order by");
	if(!InsertTest<database::unittest1TableBase>()) {
		return false;}
	if(!OrderByTest()) {
		return false;}
	if(!DeleteAllTest<database::unittest1TableBase>()) {
		return false;}

	//
	//TODO: implement tests for sum columns/group by/update+orderby+limit statements
	//

	log::Logging::LogTrace("testing sql injection safety");
	if(!SQLInjectionTest()) {
		return false;}

	log::Logging::LogTrace("cleaning up unit test tables");
	if(!DeleteAllTest<database::unittest3TableBase>()) {
		return false;}
	if(!DeleteAllTest<database::unittest1TableBase>()) {
		return false;}
	if(!DeleteAllTest<database::unittest2TableBase>()) {
		return false;}
	return true;
}

bool UnitTestDatabase::OrderByTest() {

	std::vector<UnitTestDatabaseEntry> entriesTmp(entries);
	std::sort(entriesTmp.begin(),entriesTmp.end(),DoubleComparator());

	database::SelectStatement stmt(database::unittest1TableBase::CreateTableDefinition());
	stmt.SelectAllColumns();
	stmt.OrderBy().AddColumn(database::unittest1TableBase::GetDefinition_ID(),database::DESCENDING);

	database::SelectResultContainer<database::unittest1TableBase> results;
	try {
		dbHelper.Connection()->Select(stmt,results); }
	catch(database::DatabaseException& ex) {
		return false; }

	if(results.Size() != entriesTmp.size()) {
		return false; }

	results.ResetIter();
	std::vector<UnitTestDatabaseEntry>::const_iterator iEntry(entriesTmp.begin());
	for(;!results.IsIterEnd();++iEntry,results.Next()) {
		if(!CompareEntryTable<database::unittest1TableBase>(*iEntry,results.GetConstIter())) {
			log::Logging::LogError("error while comparing tables in OrderByTest()");
			return false; }
	}

	return true;
}

bool UnitTestDatabase::InnerJoinTest() {

	std::vector<UnitTestDatabaseEntry>::const_iterator i(entries.begin());
	for(;i != entries.end();++i) {

		if(!InsertEntryFkTable(*i)) {
			return false; }

		if(!InnerJoinRightSideEntry(*i)) {
			return false; }

		if(!InnerJoinLeftSideEntry(*i)) {
			return false; }
	}

	return true;
}

bool UnitTestDatabase::InsertEntryFkTable(const UnitTestDatabaseEntry& entry) {

	database::SelectResultContainer<database::unittest1TableBase> results1;
	database::SelectResultContainer<database::unittest2TableBase> results2;
	try {
		database::unittest1TableBase::GetBy_integer_test(dbHelper.Connection(),entry.nInteger,results1);
		database::unittest2TableBase::GetBy_integer_test(dbHelper.Connection(),entry.nInteger,results2); }
	catch(database::DatabaseException& e) {
		return false; }

	if(results1.Size() != results2.Size() || results1.Size() != 1) {
		log::Logging::LogError("invalid result size while InsertEntryFkTable(): %llu,%llu",results1.Size(),results2.Size());
		return false; }

	results1.ResetIter();
	results2.ResetIter();

	long long id1(-1),id2(-1);
	results1.GetConstIter()->Get_ID(id1);
	results2.GetConstIter()->Get_ID(id2);

	double dTest1(-1.0),dTest2(-1.0);
	results1.GetConstIter()->Get_double_test(dTest1);
	results2.GetConstIter()->Get_double_test(dTest2);
	if(dTest1 != dTest2 || dTest2 == -1.0) {
		log::Logging::LogError("double test mismatch while InsertEntryFkTable() 1: %f 2: %f",dTest1,dTest2);
		return false; }

	long long nIntTest1(-1),nIntTest2(-1);
	results1.GetConstIter()->Get_integer_test(nIntTest1);
	results2.GetConstIter()->Get_integer_test(nIntTest2);
	if(nIntTest1 != nIntTest2 || nIntTest2 == -1) {
		log::Logging::LogError("integer test mismatch while InsertEntryFkTable() 1: %lld 2: %lld",nIntTest1,nIntTest2);
		return false; }

	std::string sTest1,sTest2;
	results1.GetConstIter()->Get_varchar_test(sTest1);
	results2.GetConstIter()->Get_varchar_test(sTest2);
	if(sTest1.compare(sTest2) != 0 || sTest1.empty() ) {
		log::Logging::LogError("string test mismatch while InsertEntryFkTable() 1: %s 2: %s",sTest1.c_str(),sTest2.c_str());
		return false; }
	//
	//TODO: compare time fields
	//
/*
	struct tm tTimeTest1,tTimeTest1;
	tools::TimeTools::InitTm(tTimeTest1);
	tools::TimeTools::InitTm(tTimeTest2);
*/

	database::unittest3TableBase insertFk;
	insertFk.Set_UNITTEST1_ID(id1);
	insertFk.Set_UNITTEST2_ID(id2);

	try{
		insertFk.Insert(dbHelper.Connection());	}
	catch(database::DatabaseException& ex) {
		return false; }

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

bool UnitTestDatabase::InnerJoinRightSideEntry(const UnitTestDatabaseEntry& entry) {

	std::vector<database::WhereConditionTableColumn*> whereCols;

	database::unittest1TableBase::GetWhereColumnsFor_integer_test(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::InitialComp()	),
		entry.nInteger,
		whereCols );

	database::unittest2TableBase::GetWhereColumnsFor_integer_test(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::And()	),
		entry.nInteger,
		whereCols );

	database::SelectStatement stmt(database::unittest3TableBase::CreateTableDefinition());
	database::unittest3TableBase::AddInnerJoinRightSideOn_UNITTEST1_ID(stmt);
	database::unittest3TableBase::AddInnerJoinRightSideOn_UNITTEST2_ID(stmt);
	stmt.Where().AddColumns(whereCols);
	stmt.SelectAllColumns();

	database::SelectResultContainer<database::TableBase> results;
	try {
		dbHelper.Connection()->Select(stmt,results); }
	catch(database::DatabaseException& ex) {
		return false; }

	if(results.Size() != 1) {
		log::Logging::LogError("invalid result size while InnerJoinRightSideEntry(): %llu",results.Size());
		return false; }

	const std::vector<database::TableColumn*>& cols(results.GetConstIter()->GetConstColumns());
	std::vector<database::TableColumn*>::const_iterator iCol(cols.begin());
	for(;iCol!=cols.end();++iCol) {

		const database::TableColumn* col(*iCol);
		const std::string& colName(col->GetColumnName());
		log::Logging::LogError(colName);
	}

	//
	//TODO: check validity of returned results
	//
	return true;
}

bool UnitTestDatabase::InnerJoinLeftSideEntry(const UnitTestDatabaseEntry& entry) {

	std::vector<database::WhereConditionTableColumn*> whereCols;

	database::unittest1TableBase::GetWhereColumnsFor_integer_test(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::InitialComp()	),
		entry.nInteger,
		whereCols );

	database::SelectStatement stmt(database::unittest1TableBase::CreateTableDefinition());
	stmt.Where().AddColumns(whereCols);
	database::unittest3TableBase::AddInnerJoinLeftSideOn_UNITTEST1_ID(stmt);
	stmt.SelectAllColumns();

	database::SelectResultContainer<database::TableBase> results;
	try {
		dbHelper.Connection()->Select(stmt,results); }
	catch(database::DatabaseException& ex) {
		return false; }

	if(results.Size() != 1) {
		log::Logging::LogError("invalid result size while InnerJoinLeftSideEntry(): %llu",results.Size());
		return false; }

	//
	//TODO: check validity of returned results
	//
	return true;
}

bool UnitTestDatabase::SQLInjectionTest() {

	//the last element in this list has to be zero
	static const char** injectStringValues((const char *[]){ "-- a", "' a", "'' a", "' ' a '", "\" a", "; a", "<!DOCTYPE html> \
	<html><head>", 0 });
		//
		//TODO: check for zeros in statement
		//
		// "\0 a", 0 };

	for(size_t i = 0; injectStringValues[i]; i++) {
		database::unittest1TableBase sqlInject;
		sqlInject.Set_double_test(1.0);
		sqlInject.Set_integer_test(1);
		sqlInject.Set_varchar_test(injectStringValues[i]);
		sqlInject.Set_timestamp_test(tools::TimeTools::NowUTC());

		try {
			sqlInject.Insert(dbHelper.Connection()); }
		catch(database::DatabaseException& e) {
			return false; }
	}

	std::vector<std::string> files;
	const static std::string testFileDir("../Scripts/tests/database/");
	tools::FileTools::ListDirectory(files,testFileDir,true);
	std::vector<std::string>::const_iterator iFiles(files.begin());
	for(;iFiles != files.end();++iFiles) {

		std::string content;
		if(tools::FileTools::ReadFile(testFileDir + *iFiles,content)) {

			database::unittest1TableBase sqlInject;
			sqlInject.Set_double_test(1.0);
			sqlInject.Set_integer_test(1);
			sqlInject.Set_varchar_test(content);
			sqlInject.Set_timestamp_test(tools::TimeTools::NowUTC());

			try {
				sqlInject.Insert(dbHelper.Connection()); }
			catch(database::DatabaseException& e) {
				return false; }
		}
		else
			return false;
	}

	return true;
}

}
