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

namespace database {
	class DatabaseConfig;
}

namespace toolbot {

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
	template <class T>
	bool InsertTest(){
		std::vector<UnitTestDatabaseEntry>::const_iterator i = entries.begin();
		for(;i != entries.end();++i) {
			if(!InsertEntry<T>(*i)) {
				return false; }
		}
		return true;
	}

	template <class T>
	bool SelectTest() {
		std::vector<UnitTestDatabaseEntry>::const_iterator i = entries.begin();
		for(;i != entries.end();++i) {
			if(!SelectEntryByDouble<T>(*i)) {
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
			return false; }

		return true;
	}

	bool UpdateTest();
	bool DeleteTest();

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
	bool CompareEntryTable(const UnitTestDatabaseEntry& entry,const T* tbl) const {

		double dTest = 0.0;
		tbl->Get_double_test(dTest);
		if(dTest != entry.dDouble) {
			log::Logging::LogError("invalid data while select double_test: %f (should be %f)",dTest,entry.dDouble);
			return false; }

		std::string sTest;
		tbl->Get_varchar_test(sTest);
		if(sTest.compare(entry.varchar_test) != 0) {
			log::Logging::LogError("invalid data while select varchar_test: %s (should be '%s')",sTest.c_str(),entry.varchar_test.c_str());
			return false; }

		/*
		//
		//TODO: implement timetools to compare two struct tm's
		//
		struct tm tTest;
		tbl->Get_timestamp_test(tTest);
		if(tTest != entry.timestamp) {
			log::Logging::LogError("invalid data while select timestamp_test: %s (should be '%s')",
					tools::TimeTools::TimevalToString(tTest).c_str(),
					tools::TimeTools::TimevalToString(entry.varchar_test).c_str());
			return false;}
		*/
		return true;
	}

	template <class T>
	bool InsertEntry(const UnitTestDatabaseEntry& entry){
		T insertTbl;
		insertTbl.Set_timestamp_test(entry.timestamp);
		insertTbl.Set_double_test(entry.dDouble);
		insertTbl.Set_varchar_test(entry.varchar_test);
		try {
			insertTbl.Insert(dbHelper.Connection()); }
		catch(database::DatabaseException& ex) {
			log::Logging::LogError("could not insert test data:\n%s",ex.Dump().c_str());
			return false; }

		long long insertID1 = -1;
		dbHelper.Connection()->LastInsertID(insertID1);
		if(insertID1 == -1) {
			log::Logging::LogError("could not determine last inserted id: %lld",insertID1);
			return false; }
		return true;
	}

private:
	const database::DatabaseConfig* dbConfig;
	database::DatabaseHelper dbHelper;
	std::vector<UnitTestDatabaseEntry> entries;
};

}
