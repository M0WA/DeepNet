/**
 *
 * @file QueryDictionaryInfoThread.cpp
 * @author Moritz Wagner
 * @date 02.02.2014
 *
 */

#include "QueryDictionaryInfoThread.h"

#include <Logging.h>
#include <PerformanceCounter.h>

#include <DatabaseLayer.h>
#include <DatabaseHelper.h>
#include <TableDefinition.h>
#include <TableColumnDefinition.h>
#include <TableColumn.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include "Query.h"
#include "QueryKeywordGroup.h"
#include "QueryThreadParam.h"

namespace queryserver {

QueryDictionaryInfoThread::_QueryDictionaryInfoThreadParam::_QueryDictionaryInfoThreadParam(Query& query,database::DatabaseConnection *db)
: query(query)
, db(db) {
}

QueryDictionaryInfoThread::QueryDictionaryInfoThread()
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(QueryDictionaryInfoThread::QueryDictionaryInfoThreadFunction)),false) {
}

QueryDictionaryInfoThread::~QueryDictionaryInfoThread() {
}

void* QueryDictionaryInfoThread::QueryDictionaryInfoThreadFunction(threading::Thread::THREAD_PARAM* threadParam) {

	log::Logging::RegisterThreadID("QueryDictionaryInfoThreadFunction");

	QueryDictionaryInfoThreadParam *qp(reinterpret_cast<QueryDictionaryInfoThreadParam*>(threadParam->pParam));


	free(qp);
	return 0;
}

/*
bool QueryDictionaryInfoThread::GetIDsForKeywords(
	const std::vector<std::string>& vecKey,
	database::WhereConditionTableColumnCreateParam& whereKeywordCreate,
	std::vector<long long>& excludeDictIDs,
	std::vector<long long>& dictIDs) {

	whereKeywordCreate.compOp = database::WhereCondition::InitialComp();

	std::vector<database::WhereConditionTableColumn*> where;
	std::vector<std::string>::const_iterator iKeyword(vecKey.begin());
	for(size_t pos(0);iKeyword!=vecKey.end();++iKeyword,++pos) {

		where.clear();
		database::dictTableBase::GetWhereColumnsFor_keyword(
			whereKeywordCreate,
			*iKeyword,
			where );

		if(excludeDictIDs.size()) {
			database::dictTableBase::GetWhereColumnsFor_ID(
				database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(),database::WhereCondition::And()),
				excludeDictIDs,
				where );
		}

		database::SelectResultContainer<database::dictTableBase> results;
		database::SelectStatement selectDict(database::dictTableBase::CreateTableDefinition());
		selectDict.SelectAllColumns();
		selectDict.Where().AddColumns(where);

		try {
			dbConn->Select(selectDict,results); }
		catch(database::DatabaseException& e) {
			log::Logging::LogTrace("error while selecting keyword: %s",iKeyword->c_str());
			return false; }

		for(results.ResetIter();!results.IsIterEnd();results.Next()) {
			long long dictID(-1);
			results.GetConstIter()->Get_ID(dictID);
			excludeDictIDs.push_back(dictID);
			dictIDs.push_back(dictID);
		}
	}
	return true;
}

bool QueryDictionaryInfoThread::GetIDsForExactKeywords(
		const std::vector<std::string>& vecKey,
		std::vector<long long>& exactMatchDictIDs,
		std::vector<long long>& excludeDictIDs) {

	database::WhereConditionTableColumnCreateParam whereCreate(database::WhereCondition::Equals(),database::WhereCondition::InitialComp());
	return GetIDsForKeywords(
		vecKey,
		whereCreate,
		excludeDictIDs,
		exactMatchDictIDs);
}

bool QueryDictionaryInfoThread::GetIDsForCaseInsensitiveKeywords(
		const std::vector<std::string>& vecKey,
		std::vector<long long>& caseInsensitiveMatchDictIDs,
		std::vector<long long>& excludeDictIDs) {

	database::WhereConditionTableColumnCreateParam whereCreate(database::WhereCondition::Like(),database::WhereCondition::InitialComp());
	return GetIDsForKeywords(
		vecKey,
		whereCreate,
		excludeDictIDs,
		caseInsensitiveDictIDs);
}

bool QueryDictionaryInfoThread::GetIDsForSimilarKeywords(
		const std::vector<std::string>& vecKey,
		std::vector<long long>& similarDictIDs,
		std::vector<long long>& excludeDictIDs) {

	database::WhereConditionTableColumnCreateParam whereCreate(database::WhereCondition::Like(),database::WhereCondition::InitialComp(),database::WILDCARD_BOTH);
	return GetIDsForKeywords(
		vecKey,
		whereCreate,
		excludeDictIDs,
		similarDictIDs);
}

bool QueryDictionaryInfoThread::GetDictIDsByKeywordGroup(
		const queryserver::QueryKeywordGroup& group,
		queryserver::QueryDictionaryInfoThread::QueryKeywordDictInfo& dictIDs) {

	std::vector<std::string> words, caseInsensitive, similar;
	group.GetKeywordVariations(words, caseInsensitive, similar);

	std::vector<long long> excludeDictIDs;

	if(words.size() && !GetIDsForKeywords(words,dictIDs.exactIDs,excludeDictIDs)) {
		return false; }

	if(caseInsensitive.size() && !GetIDsForCaseInsensitiveKeywords(caseInsensitive,dictIDs.caseinsensitiveIDs,excludeDictIDs)) {
		return false; }

	if(similar.size() && !GetIDsForSimilarKeywords(similar,dictIDs.similarIDs,excludeDictIDs)) {
		return false; }

	bool found(false);
	found |= words.size();
	found |= caseInsensitive.size();
	found |= similar.size();
	return found;
}

void* QueryDictionaryInfoThread::OnRun() {

	const Query& query(queryThreadParam.GetConst()->query);
	const std::vector<QueryKeywordGroup>& groups(query.GetKeywordGroups());

	std::vector<QueryDictionaryInfoThread::QueryKeywordDictInfo> dictInfos;
	std::vector<QueryKeywordGroup>::const_iterator i(groups.begin());
	for(;i != groups.end(); ++i) {
		QueryDictionaryInfoThread::QueryKeywordDictInfo dictIDs;
		if( GetDictIDsByKeywordGroup( (*i), dictIDs	) ) {
			dictInfos.push_back(dictIDs); }
	}

	return 0;
}
*/

}
