/*
 * KeywordDictionary.cpp
 *
 *  Created on: Jun 10, 2017
 *      Author: Moritz Wagner
 */

#include "KeywordDictionary.h"

#include <Logging.h>

#include <DatabaseLayer.h>
#include <DatabaseException.h>
#include <WhereConditionTableColumn.h>
#include <WhereCondition.h>

#include "Query.h"
#include "QueryKeyword.h"

namespace queryserver {

KeywordDictionary::KeywordDictionary() {
}

KeywordDictionary::~KeywordDictionary() {
}

bool KeywordDictionary::Init(database::DatabaseConnection* dbConn,const Query& query) {

	bool success(true);
	const std::vector<QueryKeyword>& kws(query.GetQueryKeywords());
	std::vector<QueryKeyword>::const_iterator i(kws.begin());
	for(; i != kws.end(); ++i) {
		success &= InitByKeyword(dbConn,*i);
	}
	return success;
}

bool KeywordDictionary::GetDictIDInfo(const long long& dictID, DictIDInfo& info) const {

	std::vector<KeywordMatch>::const_iterator kw(keywords.begin());
	for(; kw != keywords.end(); ++kw) {
		KeywordMatch::KeywordMatchEntry::const_iterator m(kw->entry.begin());
		for(; m != kw->entry.end(); ++m) {
			std::vector<long long>::const_iterator d(m->second.begin());
			for(; d != m->second.end(); ++d) {
				if( *d == dictID ) {
					info.type = kw->keyword->GetMatchType();
					info.position = kw->keyword->GetPosition();
					info.groupID = kw->keyword->GetGroupID();
					return true;
				}
			}
		}
	}
	return false;
}

void KeywordDictionary::GetAllIDs(std::vector<long long>& dictIDs) const {

	std::vector<KeywordMatch>::const_iterator kw(keywords.begin());
	for(; kw != keywords.end(); ++kw) {
		std::vector<long long> ids;
		kw->GetAllDictIDs(ids);
		dictIDs.insert(dictIDs.end(),ids.begin(),ids.end());
	}
}

bool KeywordDictionary::InitByKeyword(database::DatabaseConnection* dbConn,const QueryKeyword& kw) {

	database::WhereConditionOperator whereOp(database::WhereCondition::Equals());
	database::WildcardType wildType(database::WILDCARD_NONE);

	std::vector<long long> excludeIDs;
	for (int i(EXACT_MATCH); i < kw.GetMatchType(); i++) {
		std::vector<database::WhereConditionTableColumn*> where;

		KeywordMatchType type(static_cast<KeywordMatchType>(i));

		switch(type) {
		case EXACT_MATCH:
			whereOp = database::WhereCondition::Equals();
			wildType = database::WILDCARD_NONE;
			break;
		case CASEINSENSITIVE_MATCH:
			whereOp = database::WhereCondition::Equals();
			wildType = database::WILDCARD_BOTH;
			break;
		case SIMILAR_MATCH:
			whereOp = database::WhereCondition::Like();
			wildType = database::WILDCARD_BOTH;
			break;
		default:
			log::Logging::LogWarn("invalid match type %d for keyword %s",kw.GetMatchType(),kw.GetKeyword().c_str());
			return false;
		}

		database::WhereConditionTableColumnCreateParam whereCreate(
			whereOp,
			database::WhereCondition::InitialComp(),
			wildType);

		database::dictTableBase::GetWhereColumnsFor_keyword(
			whereCreate,
			kw.GetKeyword(),
			where );

		if(excludeIDs.size()) {
			database::dictTableBase::GetWhereColumnsFor_ID(
				database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(),database::WhereCondition::And()),
				excludeIDs,
				where );
		}

		database::SelectResultContainer<database::dictTableBase> results;
		database::SelectStatement selectDict(database::dictTableBase::CreateTableDefinition());
		selectDict.SelectAllColumns();
		selectDict.Where().AddColumns(where);

		try {
			dbConn->Select(selectDict,results); }
		CATCH_EXCEPTION(database::DatabaseException,e,1)
			log::Logging::LogTrace("error while selecting keyword: %s",kw.GetKeyword().c_str());
			return false; }

		for(results.ResetIter();!results.IsIterEnd();results.Next()) {
			long long dictID(-1);
			results.GetConstIter()->Get_ID(dictID);

			excludeIDs.push_back(dictID);

			if( keywords.size() == kw.GetPosition() ) {
				KeywordMatch km(&kw);
				km.entry[type].push_back(dictID);
				keywords.push_back(km);
			}
			else if( keywords.size() > kw.GetPosition() ) {
				KeywordMatch& km(keywords.at(kw.GetPosition()));
				km.entry[type].push_back(dictID);
			}
			else {
				log::Logging::LogError("invalid keywords-dictionary size");
				return false;
			}
		}
	}

	return true;
}

}
