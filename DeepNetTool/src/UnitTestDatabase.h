/**
 *
 * @file UnitTestDatabase.h
 * @author Moritz Wagner
 * @date 15.07.2013
 *
 */

#pragma once

#include "UnitTest.h"

#include <ctime>

#include <Logging.h>
#include <TimeTools.h>

#include <DatabaseLayer.h>
#include <DatabaseException.h>
#include <DatabaseHelper.h>
#include <DatabaseConnection.h>

#include <TableColumnDefinition.h>
#include <TableDefinition.h>
#include <TableColumn.h>
#include <WhereCondition.h>

namespace database {
	class DatabaseConfig;
}

namespace toolbot {

/**
 * @brief implements database independent unit tests
 * @see toolbot::UnitTest
 */
class UnitTestDatabase: public toolbot::UnitTest {
private:
	typedef struct _UnitTestDatabaseEntry {

		_UnitTestDatabaseEntry() {}

		std::string varchar_test;
		double dDouble;
		long long nInteger;
		struct tm timestamp;

	} UnitTestDatabaseEntry;

public:
	UnitTestDatabase(const database::DatabaseConfig* dbConfig);
	virtual ~UnitTestDatabase();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestDatabase"; }

private:
	bool UpdateTest();
	bool UpsertTest();

private:
	template <class T>
	bool DeleteAllTest() {
		database::DeleteStatement deleteAll(T::CreateTableDefinition());
		try {
			dbHelper.Connection()->Delete(deleteAll); }
		catch(database::DatabaseException& ex) {
			log::Logging::LogError("could not delete test data:\n%s",ex.Dump().c_str());
			return false; }

		database::TableDefinition* tblDef(T::CreateTableDefinition());
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

		database::TableColumn* countCol(cols.at(0));

		/*
		const std::string& columnName = countCol->GetColumnName();
		if(!tools::StringTools::CompareCaseInsensitive(columnName,"id")) {
			log::Logging::LogError("invalid column name while select count(%lld) for test data: %s",countRow,columnName.c_str());
			return false; }
		*/

		long long countRow(-1);
		countCol->Get(countRow);

		if(countRow != 0) {
			log::Logging::LogError("invalid count(%lld) while select count for test data",countRow);
			return false; }

		return true;
	}

	template <class T>
	bool InsertTest(){
		std::vector<UnitTestDatabaseEntry>::const_iterator i = entries.begin();
		for(;i != entries.end();++i) {
			if(!InsertEntry<T>(*i)) {
				return false; }
		}

		database::SelectStatement selectAll(T::CreateTableDefinition());
		selectAll.SelectAllColumns();

		database::SelectResultContainer<T> results;
		try {
			dbHelper.Connection()->Select(selectAll,results); }
		catch(database::DatabaseException& ex) {
			log::Logging::LogError("could not select test data:\n%s",ex.Dump().c_str());
			return false; }
		results.ResetIter();

		if(results.Size() != entries.size()) {
			log::Logging::LogError("invalid number of entries in table %lu (should be %lu)",results.Size(),entries.size());
			return false;}

		return true;
	}

	template <class T>
	bool SelectTest() {
		std::vector<UnitTestDatabaseEntry>::const_iterator i = entries.begin();
		for(;i != entries.end();++i) {
			if(!SelectEntryByDouble<T>(*i)) {
				return false; }
			if(!SelectEntryByVarchar<T>(*i)) {
				return false; }
			if(!SelectEntryByTimestamp<T>(*i)) {
				return false; }
			if(!SelectEntryByInteger<T>(*i)) {
				return false; }
			if(!SelectEntryByAll<T>(*i)) {
				return false; }
		}
		return true;
	}

	template <class T>
	bool SelectEntryByDouble(const UnitTestDatabaseEntry& entry) {
		database::SelectResultContainer<T> results;
		try {
			T::GetBy_double_test(dbHelper.Connection(),entry.dDouble,results);	}
		catch(database::DatabaseException& ex) {
			log::Logging::LogError("could not select test data:\n%s",ex.Dump().c_str());
			return false; }

		if(results.Size() != 1) {
			log::Logging::LogError("invalid size while selecting double: %lu",results.Size());
			return false;}
		results.ResetIter();

		if(!CompareEntryTable(entry,results.GetIter())) {
			return false; }

		return true;
	}

	template <class T>
	bool SelectEntryByVarchar(const UnitTestDatabaseEntry& entry) {
		database::SelectResultContainer<T> results;
		try {
			T::GetBy_varchar_test(dbHelper.Connection(),entry.varchar_test,results);	}
		catch(database::DatabaseException& ex) {
			log::Logging::LogError("could not select test data:\n%s",ex.Dump().c_str());
			return false; }

		if(results.Size() != 1) {
			log::Logging::LogError("invalid size while selecting varchar: %lu",results.Size());
			return false;}
		results.ResetIter();

		if(!CompareEntryTable(entry,results.GetIter())) {
			return false; }

		return true;
	}

	template <class T>
	bool SelectEntryByTimestamp(const UnitTestDatabaseEntry& entry) {
		database::SelectResultContainer<T> results;
		try {
			T::GetBy_timestamp_test(dbHelper.Connection(),entry.timestamp,results);	}
		catch(database::DatabaseException& ex) {
			log::Logging::LogError("could not select test data:\n%s",ex.Dump().c_str());
			return false; }

		if(results.Size() != 1) {
			log::Logging::LogError("invalid size while selecting timestamp: %lu",results.Size());
			return false;}
		results.ResetIter();

		if(!CompareEntryTable(entry,results.GetIter())) {
			return false; }

		return true;
	}

	template <class T>
	bool SelectEntryByInteger(const UnitTestDatabaseEntry& entry) {
		database::SelectResultContainer<T> results;
		try {
			T::GetBy_integer_test(dbHelper.Connection(),entry.nInteger,results);	}
		catch(database::DatabaseException& ex) {
			log::Logging::LogError("could not select test data:\n%s",ex.Dump().c_str());
			return false; }

		if(results.Size() != 1) {
			log::Logging::LogError("invalid size while selecting integer: %lu",results.Size());
			return false;}
		results.ResetIter();

		if(!CompareEntryTable(entry,results.GetIter())) {
			return false; }
		return true;
	}

	template <class T>
	bool SelectEntryByAll(const UnitTestDatabaseEntry& entry) {

		std::vector<database::WhereConditionTableColumn*> container;
		T::GetWhereColumnsFor_double_test(
				database::WhereConditionTableColumnCreateParam(
					database::WhereCondition::Equals(),
					database::WhereCondition::InitialComp()),
		        entry.dDouble,
		        container);

		T::GetWhereColumnsFor_varchar_test(
				database::WhereConditionTableColumnCreateParam(
					database::WhereCondition::Equals(),
					database::WhereCondition::And()),
		        entry.varchar_test,
		        container);

		T::GetWhereColumnsFor_timestamp_test(
				database::WhereConditionTableColumnCreateParam(
					database::WhereCondition::Equals(),
					database::WhereCondition::And()),
		        entry.timestamp,
		        container);

		T::GetWhereColumnsFor_integer_test(
				database::WhereConditionTableColumnCreateParam(
					database::WhereCondition::Equals(),
					database::WhereCondition::And()),
		        entry.nInteger,
		        container);

		database::SelectStatement stmt(T::CreateTableDefinition());
		stmt.SelectAllColumns();
		stmt.Where().AddColumns(container);

		database::SelectResultContainer<T> results;
		try {
			dbHelper.Connection()->Select(stmt,results); }
		catch(database::DatabaseException& e) {
			return false; }

		if(results.Size() != 1) {
			log::Logging::LogError("invalid size while selecting by all fields: %lu",results.Size());
			return false;}
		results.ResetIter();

		if(!CompareEntryTable(entry,results.GetIter())) {
			return false; }

		return true;
	}

	template <class T>
	bool CompareEntryTable(const UnitTestDatabaseEntry& entry,const T* tbl) const {

		double dTest(0.0);
		tbl->Get_double_test(dTest);
		if(dTest != entry.dDouble) {
			log::Logging::LogError("invalid data while select double_test: %f (should be %f)",dTest,entry.dDouble);
			return false; }

		std::string sTest;
		tbl->Get_varchar_test(sTest);
		if(sTest.compare(entry.varchar_test) != 0) {
			log::Logging::LogError("invalid data while select varchar_test: %s (should be '%s')",sTest.c_str(),entry.varchar_test.c_str());
			return false; }

		long long nTest(-99);
		tbl->Get_integer_test(nTest);
		if(nTest != entry.nInteger) {
			log::Logging::LogError("invalid data while select integer_test: %lld (should be '%lld')",nTest,entry.nInteger);
			return false; }

		struct tm tTest;
		tbl->Get_timestamp_test(tTest);

		std::string dump1(tools::TimeTools::DumpTm(tTest)),
				    dump2(tools::TimeTools::DumpTm(entry.timestamp));

		time_t tmpTime1(tools::TimeTools::TmToTime(tTest)),
			   tmpTime2(tools::TimeTools::TmToTime(entry.timestamp));

		if(dump1.compare(dump2) != 0|| tmpTime1 != tmpTime2) {
			log::Logging::LogError("invalid data while select timestamp_test: %s (%ld) (should be %s (%ld))",
				dump1.c_str(), tmpTime1,
				dump2.c_str(), tmpTime2);
			return false;
		}
		return true;
	}

	template <class T>
	bool InsertEntry(const UnitTestDatabaseEntry& entry){
		T insertTbl;
		insertTbl.Set_timestamp_test(entry.timestamp);
		insertTbl.Set_double_test(entry.dDouble);
		insertTbl.Set_varchar_test(entry.varchar_test);
		insertTbl.Set_integer_test(entry.nInteger);

		try {
			insertTbl.Insert(dbHelper.Connection()); }
		catch(database::DatabaseException& ex) {
			log::Logging::LogError("could not insert test data:\n%s",ex.Dump().c_str());
			return false; }

		long long insertID(-99);
		dbHelper.Connection()->LastInsertID(insertID);
		if(insertID < 0) {
			log::Logging::LogError("could not determine last inserted id: %lld",insertID);
			return false; }
		return true;
	}

private:
	const database::DatabaseConfig* dbConfig;
	database::DatabaseHelper dbHelper;
	std::vector<UnitTestDatabaseEntry> entries;
};

}
