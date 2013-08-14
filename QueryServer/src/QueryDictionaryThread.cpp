/**
 *
 * @file QueryDictionaryThread.cpp
 * @author Moritz Wagner
 * @date 14.08.2013
 *
 */

#include "QueryDictionaryThread.h"

#include "Query.h"
#include "QueryThreadParam.h"
#include "QueryThreadResultEntry.h"

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

QueryDictionaryThread::QueryDictionaryThread() {
}

QueryDictionaryThread::~QueryDictionaryThread() {
}

void QueryDictionaryThread::OnInitThreadInstance() {

	const QueryThreadParam* queryparam(queryThreadParam.GetConst());
	const Query& query(queryparam->query);
	const std::vector<std::string>& vecKey(queryparam->query.keywords);

	dictIDs.resize(vecKey.size(),-1);
	if(query.lowerKeywords.size()) {
		caseInsensitiveDictIDs.resize(query.lowerKeywords.size(),std::vector<long long>()); }
}

void QueryDictionaryThread::OnDestroyThreadInstance(){

	dictIDs.clear();
	caseInsensitiveDictIDs.clear();
}

void* QueryDictionaryThread::OnRun() {

	if(!GetIDsForKeywords()) {
		return (void*)1; }

	if(!GetIDsForCaseInsensitiveKeywords()) {
		return (void*)1; }

	return 0;
}

bool QueryDictionaryThread::GetIDsForKeywords() {

	const QueryThreadParam* queryparam(queryThreadParam.GetConst());
	const std::vector<std::string>& vecKey(queryparam->query.keywords);

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

		size_t keywordPos(queryparam->query.GetPositionByKeyword(tmpKey));
		std::vector<long long>::iterator iDictID(dictIDs.begin());
		std::advance(iDictID,keywordPos);

		results.GetConstIter()->Get_ID(*iDictID);
		dictIDPosition.insert(std::pair<long long,size_t>(*iDictID,keywordPos));
	}

	return true;
}

bool QueryDictionaryThread::GetIDsForCaseInsensitiveKeywords() {

	const QueryThreadParam* queryparam(queryThreadParam.GetConst());
	const std::vector<std::string>& vecLower(queryparam->query.lowerKeywords);

	if(queryparam->query.lowerKeywords.size() == 0)
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

		size_t keywordPos(queryparam->query.GetPositionByKeyword(tmpKey));
		std::vector< std::vector<long long> >::iterator iDictID(caseInsensitiveDictIDs.begin());
		std::advance(iDictID,keywordPos);

		long long dictID(-1);
		results.GetConstIter()->Get_ID(dictID);

		dictIDPosition.insert(std::pair<long long,size_t>(dictID,keywordPos));
		caseInsensitiveDictIDs.at(keywordPos).push_back(dictID);
	}

	return true;
}

}
