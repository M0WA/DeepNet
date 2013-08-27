/**
 *
 * @file DictionaryInfoThread.cpp
 * @author Moritz Wagner
 * @date 27.08.2013
 *
 */

#include "DictionaryInfoThread.h"

#include "Query.h"

#include <iterator>

#include <DatabaseLayer.h>
#include <DatabaseHelper.h>
#include <TableDefinition.h>
#include <TableColumnDefinition.h>
#include <TableColumn.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <ContainerTools.h>
#include <StringTools.h>
#include <TimeTools.h>
#include <Pointer.h>
#include <Logging.h>

#include <DatabaseException.h>

namespace queryserver {

DictionaryInfoThread::DictionaryInfoThread(database::DatabaseConnection* dbConn,const Query& query)
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(DictionaryInfoThread::DictionaryInfoThreadFunction)),false)
, dbConn(dbConn)
, query(query) {
	const std::vector<std::string>& vecKey(query.keywords);
	dictIDs.resize(vecKey.size(),-1);
	if(query.lowerKeywords.size()) {
		caseInsensitiveDictIDs.resize(query.lowerKeywords.size(),std::vector<long long>()); }
}

DictionaryInfoThread::~DictionaryInfoThread() {
}

void* DictionaryInfoThread::DictionaryInfoThreadFunction(threading::Thread::THREAD_PARAM* threadParam) {

	DictionaryInfoThread* threadInst = reinterpret_cast<DictionaryInfoThread*>(threadParam->instance);

	if(!threadInst->GetIDsForKeywords()) {
		return (void*)1; }

	if(!threadInst->GetIDsForCaseInsensitiveKeywords()) {
		return (void*)1; }

	if(!threadInst->GetIDsForSimilarKeywords()) {
		return (void*)1; }

	return 0;
}

bool DictionaryInfoThread::GetIDsForKeywords() {

	const std::vector<std::string>& vecKey(query.keywords);

	database::SelectResultContainer<database::dictTableBase> results;

	try {
		database::dictTableBase::GetBy_keyword(dbConn,vecKey,results);
	}
	catch(database::DatabaseException& e) {
		std::string keywordsDump;
		tools::ContainerTools::DumpVector(vecKey,keywordsDump);
		log::Logging::LogTrace("error while selecting keywords\n%s",keywordsDump.c_str());
		return false;
	}

	for(results.ResetIter();!results.IsIterEnd();results.Next()) {

		std::string tmpKey;
		results.GetConstIter()->Get_keyword(tmpKey);

		size_t keywordPos(query.GetPositionByKeyword(tmpKey));
		std::vector<long long>::iterator iDictID(dictIDs.begin());
		std::advance(iDictID,keywordPos);

		results.GetConstIter()->Get_ID(*iDictID);
		dictIDPosition.insert(std::pair<long long,size_t>(*iDictID,keywordPos));
	}

	return true;
}

bool DictionaryInfoThread::GetIDsForCaseInsensitiveKeywords() {

	const std::vector<std::string>& vecLower(query.lowerKeywords);

	if(query.lowerKeywords.size() == 0)
		return true;

	std::vector<database::WhereConditionTableColumn*> where;
	database::dictTableBase::GetWhereColumnsFor_keyword(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Like(),database::WhereCondition::InitialComp()),
		vecLower,
		where );

	database::dictTableBase::GetWhereColumnsFor_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(),database::WhereCondition::And()),
		dictIDs,
		where );

	tools::Pointer<database::TableDefinition> defDictPtr(database::dictTableBase::CreateTableDefinition());
	database::SelectStatement selectCaseInsensitive(defDictPtr.GetConst());
	selectCaseInsensitive.SelectAllColumns();
	selectCaseInsensitive.Where().AddColumns(where);

	database::SelectResultContainer<database::dictTableBase> results;
	try {
		dbConn->Select(selectCaseInsensitive,results);
	}
	catch(database::DatabaseException& e) {
		return false;
	}

	for(results.ResetIter();!results.IsIterEnd();results.Next()) {

		std::string tmpKey;
		results.GetConstIter()->Get_keyword(tmpKey);

		size_t keywordPos(query.GetPositionByKeyword(tmpKey));
		std::vector< std::vector<long long> >::iterator iDictID(caseInsensitiveDictIDs.begin());
		std::advance(iDictID,keywordPos);

		long long dictID(-1);
		results.GetConstIter()->Get_ID(dictID);

		dictIDPosition.insert(std::pair<long long,size_t>(dictID,keywordPos));
		caseInsensitiveDictIDs.at(keywordPos).push_back(dictID);
	}

	return true;
}

bool DictionaryInfoThread::GetIDsForSimilarKeywords() {

	const std::vector<std::string>& vecLower(query.lowerKeywords);

	if(query.lowerKeywords.size() == 0)
		return true;

	std::vector<database::WhereConditionTableColumn*> where;
	database::dictTableBase::GetWhereColumnsFor_keyword(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Like(),
			database::WhereCondition::InitialComp(),
			database::WILDCARD_BOTH),
		vecLower,
		where );

	if(dictIDs.size()) {
		database::dictTableBase::GetWhereColumnsFor_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(),database::WhereCondition::And()),
			dictIDs,
			where );
	}

	if(caseInsensitiveDictIDs.size()) {
		std::vector< std::vector<long long> >::const_iterator iCSDict(caseInsensitiveDictIDs.begin());
		for(;iCSDict!=caseInsensitiveDictIDs.end();++iCSDict) {
			if(iCSDict->size()) {
				database::dictTableBase::GetWhereColumnsFor_ID(
					database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(),database::WhereCondition::And()),
					*iCSDict,
					where );
			}
		}
	}

	tools::Pointer<database::TableDefinition> defDictPtr(database::dictTableBase::CreateTableDefinition());
	database::SelectStatement select(defDictPtr.GetConst());
	select.SelectAllColumns();
	select.Where().AddColumns(where);

	database::SelectResultContainer<database::dictTableBase> results;
	try {
		dbConn->Select(select,results);
	}
	catch(database::DatabaseException& e) {
		return false;
	}

	for(results.ResetIter();!results.IsIterEnd();results.Next()) {
		long long dictID(-1);
		results.GetConstIter()->Get_ID(dictID);
		similarDictIDs.push_back(dictID);
	}

	return true;
}

}
