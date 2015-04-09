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
#include <PerformanceCounter.h>

#include <DatabaseException.h>

namespace queryserver {

DictionaryInfoThread::DictionaryInfoThread(database::DatabaseConnection* dbConn,const querylib::Query& query)
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(DictionaryInfoThread::DictionaryInfoThreadFunction)),false)
, dbConn(dbConn)
, query(query) {
}

DictionaryInfoThread::~DictionaryInfoThread() {
}

DictionaryInfoThread::KeywordMatchType DictionaryInfoThread::GetMatchTypeForDictionaryID(const long long& dictID) const {

	if(IsInVector(exactMatchDictIDs,dictID))
		return EXACT_MATCH;
	if(IsInVector(caseInsensitiveDictIDs,dictID))
		return CASEINSENSITIVE_MATCH;
	if(IsInVector(similarDictIDs,dictID))
		return SIMILAR_MATCH;

	return INVALID_MATCH_TYPE;
}

bool DictionaryInfoThread::IsInVector(const std::map<size_t, std::vector<long long> >& map,const long long& dictID) const {
	size_t pos;
	return IsInVector(pos,map,dictID);
}

bool DictionaryInfoThread::IsInVector(size_t& pos,const std::map<size_t, std::vector<long long> >& map,const long long& dictID) const {
	std::map<size_t, std::vector<long long> >::const_iterator i(map.begin());
	for(;i!=map.end();++i) {
		std::vector<long long>::const_iterator ii(i->second.begin());
		for(;ii!=i->second.end();++ii) {
			if(*ii == dictID) {
				pos = i->first;
				return true;
			}
		}
	}
	return false;
}

size_t DictionaryInfoThread::GetPositionForDictionaryID(const long long& dictID) const {

	size_t pos(0);
	if(IsInVector(pos,exactMatchDictIDs,dictID))
		return pos;
	if(IsInVector(pos,caseInsensitiveDictIDs,dictID))
		return pos;
	if(IsInVector(pos,similarDictIDs,dictID))
		return pos;

	return 0;
}

void* DictionaryInfoThread::DictionaryInfoThreadFunction(threading::Thread::THREAD_PARAM* threadParam) {

	log::Logging::RegisterThreadID("DictionaryInfoThread");

	DictionaryInfoThread* threadInst = reinterpret_cast<DictionaryInfoThread*>(threadParam->instance);

	std::vector<long long> excludeDictIDs;

	PERFORMANCE_LOG_START;

	if(!threadInst->GetIDsForKeywords(excludeDictIDs)) {
		return (void*)1; }

	if(!threadInst->GetIDsForCaseInsensitiveKeywords(excludeDictIDs)) {
		return (void*)1; }

	if(!threadInst->GetIDsForSimilarKeywords(excludeDictIDs)) {
		return (void*)1; }

	PERFORMANCE_LOG_STOP("DictionaryInfoThread");

	return 0;
}

bool DictionaryInfoThread::GetIDsForKeywords(
	const std::vector<std::string>& vecKey,
	database::WhereConditionTableColumnCreateParam& whereKeywordCreate,
	std::vector<long long>& excludeDictIDs,
	std::map<size_t, std::vector<long long> >& mapPositionDictIDs) {

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
			mapPositionDictIDs[pos].push_back(dictID);
			excludeDictIDs.push_back(dictID);
			allKeywordIDs.push_back(dictID);
		}
	}

	return true;
}

bool DictionaryInfoThread::GetIDsForKeywords(std::vector<long long>& excludeDictIDs) {

	std::vector<std::string> vecKey;
	query.GetKeywords(vecKey);

	database::WhereConditionTableColumnCreateParam whereCreate(database::WhereCondition::Equals(),database::WhereCondition::InitialComp());
	return GetIDsForKeywords(
		vecKey,
		whereCreate,
		excludeDictIDs,
		exactMatchDictIDs);
}

bool DictionaryInfoThread::GetIDsForCaseInsensitiveKeywords(std::vector<long long>& excludeDictIDs) {

	std::vector<std::string> vecLower;
	query.GetLoweredKeywords(vecLower);

	database::WhereConditionTableColumnCreateParam whereCreate(database::WhereCondition::Like(),database::WhereCondition::InitialComp());
	return GetIDsForKeywords(
		vecLower,
		whereCreate,
		excludeDictIDs,
		caseInsensitiveDictIDs);
}

bool DictionaryInfoThread::GetIDsForSimilarKeywords(std::vector<long long>& excludeDictIDs) {

	std::vector<std::string> vecLower;
	query.GetLoweredKeywords(vecLower);

	database::WhereConditionTableColumnCreateParam whereCreate(database::WhereCondition::Like(),database::WhereCondition::InitialComp(),database::WILDCARD_BOTH);
	return GetIDsForKeywords(
		vecLower,
		whereCreate,
		excludeDictIDs,
		similarDictIDs);
}

}
