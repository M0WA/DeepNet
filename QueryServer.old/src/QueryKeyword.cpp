/**
 *
 * @file QueryKeyword.cpp
 * @author Moritz Wagner
 * @date 14.08.2013
 *
 */

#include "QueryKeyword.h"

#include <DatabaseLayer.h>
#include <DatabaseException.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <Logging.h>
#include <StringTools.h>

//#include <SpellChecking.h>

namespace queryserver {

QueryKeyword::_QueryKeyWordEntry::_QueryKeyWordEntry()
: keyword("")
, id(-1)
, occurrence(0) {
}

QueryKeyword::_QueryKeyWordEntry::_QueryKeyWordEntry(const std::string& keyword, const long long& id, const long long& occurrence)
: keyword(keyword)
, id(id)
, occurrence(occurrence) {
}

QueryKeyword::QueryKeyword()
: keyword("") {
}

QueryKeyword::QueryKeyword(const std::string& keyword)
: keyword(keyword){
}

QueryKeyword::~QueryKeyword() {
}

bool QueryKeyword::InitExactKeywords(void) {
	map[EXACT_MATCH].push_back(QueryKeyWordEntry(keyword));
	return true;
}

bool QueryKeyword::InitCaseInsensitiveKeywords(void) {
	map[CASEINSENSITIVE_MATCH].push_back(QueryKeyWordEntry(tools::StringTools::ToLowerNP(keyword)));
	return true;
}

bool QueryKeyword::InitSimilarKeywords(void) {
	//tools::SpellChecking spellCheck;
	return true;
}

bool QueryKeyword::Init(database::DatabaseConnection *db, QueryKeyword::QueryKeywordType types) {

	bool success(true);
	std::vector<long long> excludeDictIDs;

	if( (types & EXACT_MATCH) ) {
		InitExactKeywords();
		database::WhereConditionTableColumnCreateParam where(
				database::WhereCondition::Equals(),
				database::WhereCondition::InitialComp());
		std::vector<QueryKeyWordEntry>& entries(map.at(EXACT_MATCH));
		success &= InitIDsForKeywords( db, entries, where, excludeDictIDs );
	}
	if( (types & CASEINSENSITIVE_MATCH) ) {
		InitCaseInsensitiveKeywords();
		database::WhereConditionTableColumnCreateParam where(
				database::WhereCondition::Like(),
				database::WhereCondition::InitialComp());
		std::vector<QueryKeyWordEntry>& entries(map.at(CASEINSENSITIVE_MATCH));
		success &= InitIDsForKeywords( db, entries, where, excludeDictIDs );
	}
	if( (types & SIMILAR_MATCH) ) {
		InitSimilarKeywords();
		database::WhereConditionTableColumnCreateParam where(
			database::WhereCondition::Like(),
			database::WhereCondition::InitialComp(),
			database::WILDCARD_BOTH);
		std::vector<QueryKeyWordEntry>& entries(map.at(SIMILAR_MATCH));
		success &= InitIDsForKeywords( db, entries, where, excludeDictIDs );
	}

	return success;
}

void QueryKeyword::GetDictIDByType(QueryKeywordType types, std::map<QueryKeywordType, std::vector<long long> >& dictIDs) const {

	if( (types & SIMILAR_MATCH) && (map.find(SIMILAR_MATCH) != map.end()) ) {
		const std::vector<QueryKeyWordEntry>& entries(map.at(SIMILAR_MATCH));
		QueryKeywordEntryToDictID e(dictIDs[SIMILAR_MATCH]);
		std::for_each(entries.begin(),entries.end(), e); }

	if( (types & CASEINSENSITIVE_MATCH) && (map.find(CASEINSENSITIVE_MATCH) != map.end()) ) {
		const std::vector<QueryKeyWordEntry>& entries(map.at(CASEINSENSITIVE_MATCH));
		QueryKeywordEntryToDictID e(dictIDs[CASEINSENSITIVE_MATCH]);
		std::for_each(entries.begin(),entries.end(), e); }

	if( (types & EXACT_MATCH) && (map.find(EXACT_MATCH) != map.end()) ) {
		const std::vector<QueryKeyWordEntry>& entries(map.at(EXACT_MATCH));
		QueryKeywordEntryToDictID e(dictIDs[EXACT_MATCH]);
		std::for_each(entries.begin(),entries.end(), e); }
}

void QueryKeyword::GetKeywordsByType(QueryKeywordType types,std::map<QueryKeywordType, std::vector<std::string> >& keywords) const {

	if( (types & SIMILAR_MATCH) && (map.find(SIMILAR_MATCH) != map.end()) ) {
		const std::vector<QueryKeyWordEntry>& entries(map.at(SIMILAR_MATCH));
		QueryKeywordEntryToKeyword e(keywords[SIMILAR_MATCH]);
		std::for_each(entries.begin(),entries.end(), e); }

	if( (types & CASEINSENSITIVE_MATCH) && (map.find(CASEINSENSITIVE_MATCH) != map.end()) ) {
		const std::vector<QueryKeyWordEntry>& entries(map.at(CASEINSENSITIVE_MATCH));
		QueryKeywordEntryToKeyword e(keywords[CASEINSENSITIVE_MATCH]);
		std::for_each(entries.begin(),entries.end(), e); }

	if( (types & EXACT_MATCH) && (map.find(EXACT_MATCH) != map.end()) ) {
		const std::vector<QueryKeyWordEntry>& entries(map.at(EXACT_MATCH));
		QueryKeywordEntryToKeyword e(keywords[EXACT_MATCH]);
		std::for_each(entries.begin(),entries.end(), e); }
}

void QueryKeyword::GetKeywordsByType( QueryKeywordType types, std::vector<std::string>& keywords) const {

	if( (types & SIMILAR_MATCH) && (map.find(SIMILAR_MATCH) != map.end()) ) {
		const std::vector<QueryKeyWordEntry>& entries(map.at(SIMILAR_MATCH));
		QueryKeywordEntryToKeyword e(keywords);
		std::for_each(entries.begin(),entries.end(), e); }

	if( (types & CASEINSENSITIVE_MATCH) && (map.find(CASEINSENSITIVE_MATCH) != map.end()) ) {
		const std::vector<QueryKeyWordEntry>& entries(map.at(CASEINSENSITIVE_MATCH));
		QueryKeywordEntryToKeyword e(keywords);
		std::for_each(entries.begin(),entries.end(), e); }

	if( (types & EXACT_MATCH) && (map.find(EXACT_MATCH) != map.end()) ) {
		const std::vector<QueryKeyWordEntry>& entries(map.at(EXACT_MATCH));
		QueryKeywordEntryToKeyword e(keywords);
		std::for_each(entries.begin(),entries.end(), e); }
}

bool QueryKeyword::InitIDsForKeywords(
	database::DatabaseConnection *db,
	std::vector<QueryKeyWordEntry>& entries,
	database::WhereConditionTableColumnCreateParam& where,
	std::vector<long long>& excludeDictIDs) {

	where.compOp = database::WhereCondition::InitialComp();

	std::vector<database::WhereConditionTableColumn*> whereTotal;

	std::vector<std::string> keywords;
	QueryKeywordEntryToKeyword e(keywords);
	std::for_each(entries.begin(),entries.end(), e);

	std::vector<std::string>::const_iterator iKeyword(keywords.begin());
	for(size_t pos(0);iKeyword!=keywords.end();++iKeyword,++pos) {

		whereTotal.clear();
		database::dictTableBase::GetWhereColumnsFor_keyword(
			where,
			*iKeyword,
			whereTotal );

		if(excludeDictIDs.size()) {
			database::dictTableBase::GetWhereColumnsFor_ID(
				database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(),database::WhereCondition::And()),
				excludeDictIDs,
				whereTotal );
		}

		database::SelectResultContainer<database::dictTableBase> results;
		database::SelectStatement selectDict(database::dictTableBase::CreateTableDefinition());
		selectDict.SelectAllColumns();
		selectDict.Where().AddColumns(whereTotal);

		try {
			db->Select(selectDict,results); }
		catch(database::DatabaseException& e) {
			log::Logging::LogTrace("error while selecting keyword: %s",iKeyword->c_str());
			return false; }

		for(results.ResetIter();!results.IsIterEnd();results.Next()) {
			long long dictID(-1), occurrence(-1);
			std::string dictWord;
			results.GetConstIter()->Get_ID(dictID);
			results.GetConstIter()->Get_keyword(dictWord);
			results.GetConstIter()->Get_occurrence(occurrence);
			excludeDictIDs.push_back(dictID);

			std::vector<QueryKeyWordEntry>::iterator iEntry(std::find(entries.begin(),entries.end(),dictWord));
			if(iEntry != entries.end()) {
				if(iEntry->id != -1) {
					if(iEntry->id != -dictID) {
						entries.push_back(QueryKeyWordEntry(dictWord,dictID,occurrence));
						log::Logging::LogError("duplicate dictID for %s detected: %lld should be %lld",dictWord.c_str(),dictID,iEntry->id);	}
					else {
						iEntry->occurrence += occurrence;
						log::Logging::LogError("multiple entries for dictID %lld (%s) detected",dictID,dictWord.c_str()); }
				}
				else {
					iEntry->id = dictID;
					iEntry->occurrence = occurrence;
				}
			}
			else {
				entries.push_back(QueryKeyWordEntry(dictWord,dictID,occurrence));
			}
		}
	}
	return true;
}

}
