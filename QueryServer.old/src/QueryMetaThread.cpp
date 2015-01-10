/**
 *
 * @file QueryMetaThread.cpp
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#include "QueryMetaThread.h"

#include "Query.h"
#include "QueryThreadParam.h"

#include <Logging.h>
#include <PerformanceCounter.h>
#include <ContainerTools.h>
#include <StringTools.h>
#include <TimeTools.h>
#include <Pointer.h>

#include <DatabaseLayer.h>
#include <DatabaseException.h>
#include <TableDefinition.h>
#include <TableColumnDefinition.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

/*
#include "QueryThreadResultEntry.h"
#include "QueryDictionaryInfoThread.h"

#include <TableColumn.h>
#include <Dictionary.h>
*/

//
//TODO: move to config file
//
#define META_INFO_HARDLIMIT 10000

namespace queryserver {

QueryMetaThread::QueryMetaThread()
: queryserver::QueryThread() {
}

QueryMetaThread::~QueryMetaThread() {
}

void* QueryMetaThread::OnRun(){

	const Query& q(queryThreadParam.GetConst()->query);
	const QueryProperties& queryProperties(q.GetQueryProperties());

	const std::vector<QueryKeywordGroup>& grps(q.GetKeywordGroups());
	std::vector<QueryKeywordGroup>::const_iterator igrp(grps.begin());

	std::map<QueryKeyword::QueryKeywordType, std::vector<long long> > dictIDsType;
	for(; igrp!=grps.end(); ++igrp) {
		const std::vector<QueryKeyword>& keys(igrp->GetKeywords());
		std::vector<QueryKeyword>::const_iterator ikey(keys.begin());
		for(;ikey != keys.end(); ++ikey) {
			ikey->GetDictIDByType(QueryKeyword::CASEINSENSITIVE_MATCH, dictIDsType); }
	}

	std::vector<std::vector<long long> > dictIDsVec;
	tools::ContainerTools::Map2ToVector(dictIDsType,dictIDsVec);

	std::vector<long long> dictIDs;
	tools::ContainerTools::AppendFlattenedVector(dictIDsVec, dictIDs);
	tools::ContainerTools::MakeUniqueVector(dictIDs,false);

	tools::Pointer<database::TableDefinition> tblDefPtr(database::docmetaTableBase::CreateTableDefinition());
	database::SelectStatement select(tblDefPtr.GetConst());

	database::TableColumnDefinition
		*colDefMetaType(database::docmetaTableBase::GetDefinition_type()),
		*colDefDictID(database::docmetaTableBase::GetDefinition_DICT_ID()),
		*colDefOccurrence(database::docmetaTableBase::GetDefinition_occurrence()),
		*colDefUrlStageID(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID()),
		*colDefUrlID(database::latesturlstagesTableBase::GetDefinition_URL_ID()),
		*colDefFound(database::urlstagesTableBase::GetDefinition_found_date());

	select.SelectAddColumnAlias(colDefMetaType,colDefMetaType->GetColumnName());
	select.SelectAddColumnAlias(colDefDictID,colDefDictID->GetColumnName());
	select.SelectAddColumnAlias(colDefOccurrence,colDefOccurrence->GetColumnName());
	select.SelectAddColumnAlias(colDefUrlStageID,colDefUrlStageID->GetColumnName());
	select.SelectAddColumnAlias(colDefUrlID,colDefUrlID->GetColumnName());
	select.SelectAddColumnAlias(colDefFound,colDefFound->GetColumnName());

	database::docmetaTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID(select);

	std::vector<database::WhereConditionTableColumn*> where;
	database::docmetaTableBase::GetWhereColumnsFor_DICT_ID(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::InitialComp()),
			dictIDs,
		where);

	if(queryProperties.GetLimitations().IsLimitationEnabled(QueryLimitations::LIMITATION_DOMAIN)) {
		long long secondleveldomainID(-1);
		queryProperties.GetLimitations().GetLimitationByType(QueryLimitations::LIMITATION_DOMAIN,secondleveldomainID);
		database::urlsTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::Equals(),
				database::WhereCondition::And()),
				secondleveldomainID,
			where);
	}

	/*
	if(queryProperties.limitSubDomainID > 0) {
		database::urlsTableBase::GetWhereColumnsFor_SUBDOMAIN_ID(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::Equals(),
				database::WhereCondition::And()),
			queryProperties.limitSubDomainID,
			where);
	}
	*/

	if(queryProperties.GetLimitations().IsLimitationEnabled(QueryLimitations::LIMITATION_MIN_AGE)) {
		struct tm min_age;
		queryProperties.GetLimitations().GetLimitationByType(QueryLimitations::LIMITATION_MIN_AGE,min_age);
				database::urlstagesTableBase::GetWhereColumnsFor_found_date(
					database::WhereConditionTableColumnCreateParam(
						database::WhereCondition::GreaterOrEqual(),
						database::WhereCondition::And()),
					min_age,
					where);
	}

	if(queryProperties.GetLimitations().IsLimitationEnabled(QueryLimitations::LIMITATION_MAX_AGE)) {
		struct tm max_age;
		queryProperties.GetLimitations().GetLimitationByType(QueryLimitations::LIMITATION_MAX_AGE,max_age);
		database::urlstagesTableBase::GetWhereColumnsFor_found_date(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::SmallerOrEqual(),
				database::WhereCondition::And()),
			max_age,
			where);
	}

	select.Where().AddColumns(where);

	//
	//TODO: set order by when setting a limit
	//
	select.SetLimit(META_INFO_HARDLIMIT);

	database::SelectResultContainer<database::TableBase> dbResults;
	PERFORMANCE_LOG_START;
	try {
		dbConn->Select(select,dbResults); }
	catch(database::DatabaseException& e) {
		return 0; }
	PERFORMANCE_LOG_STOP("selecting result by meta information");

	ProcessResults(dbResults);
	return 0;
}

void QueryMetaThread::ProcessResults(database::SelectResultContainer<database::TableBase>& results) {

	/*
	const Query& query(queryThreadParam.GetConst()->query);
	const QueryProperties& queryProperties(query.GetQueryProperties());
	const QueryDictionaryThreadParam* dictThreadParam(reinterpret_cast<const QueryDictionaryThreadParam*>(queryThreadParam.GetConst()));
	const QueryDictionaryInfoThread* dictInfo(dictThreadParam->dictInfo);

	tools::Pointer<database::TableColumnDefinition>
		colDefMetaTypePtr(database::docmetaTableBase::GetDefinition_type()),
		colDefUrlIDPtr(database::latesturlstagesTableBase::GetDefinition_URL_ID()),
		colDefUrlStageIDPtr(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID()),
		colDefOccurencePtr(database::docmetaTableBase::GetDefinition_occurrence()),
		colDefDictIDPtr(database::docmetaTableBase::GetDefinition_DICT_ID()),
		colDefFoundPtr(database::urlstagesTableBase::GetDefinition_found_date());

	const database::TableColumnDefinition
		*colDefMetaType(colDefMetaTypePtr.GetConst()),
		*colDefUrlID(colDefUrlIDPtr.GetConst()),
		*colDefUrlStageID(colDefUrlStageIDPtr.GetConst()),
		*colDefOccurence(colDefOccurencePtr.GetConst()),
		*colDefDictID(colDefDictIDPtr.GetConst()),
		*colDefFound(colDefFoundPtr.GetConst());

	for(results.ResetIter();!results.IsIterEnd();results.Next()) {

		const database::TableBase* curTbl(results.GetConstIter());

		const database::TableColumn
			*colMetaType(curTbl->GetConstColumnByName(colDefMetaType->GetColumnName())),
			*colUrlID(curTbl->GetConstColumnByName(colDefUrlID->GetColumnName())),
			*colUrlStageID(curTbl->GetConstColumnByName(colDefUrlStageID->GetColumnName())),
			*colOccurence(curTbl->GetConstColumnByName(colDefOccurence->GetColumnName())),
			*colDictID(curTbl->GetConstColumnByName(colDefDictID->GetColumnName())),
			*colFound(curTbl->GetConstColumnByName(colDefFound->GetColumnName()));

		if(!colMetaType || !colUrlID || !colDictID || !colOccurence || !colFound || !colUrlStageID) {
			log::Logging::LogWarn("invalid result row received for search query content result, ommitting entry");
			continue; }

		long long metaType(-1), urlID(-1),urlStageID(-1), dictID(-1), occurence(-1);
		struct tm found;
		colMetaType->Get(metaType);
		colUrlID->Get(urlID);
		colUrlStageID->Get(urlStageID);
		colDictID->Get(dictID);
		colOccurence->Get(occurence);
		colFound->Get(found);

		//
		//TODO: this should not be hardcoded, move to QueryProperties
		//
		double matchRelevanceFactor(0.0);
		switch(dictInfo->GetMatchTypeForDictionaryID(dictID))
		{
		case DictionaryInfoThread::EXACT_MATCH:
			matchRelevanceFactor=1.0;
			break;

		case DictionaryInfoThread::CASEINSENSITIVE_MATCH:
			matchRelevanceFactor=0.95;
			break;

		case DictionaryInfoThread::SIMILAR_MATCH:
			matchRelevanceFactor=0.9;
			break;

		default:
			//TODO: throw exception
			break;
		}

		//
		//TODO: this should not be hardcoded, move to QueryProperties
		//
		double metaRelevanceFactor(0.5);
		switch(metaType)
		{
		case indexing::Dictionary::META_TITLE:
			metaRelevanceFactor = 1.0;
			break;

		case indexing::Dictionary::META_DESCRIPTION:
			metaRelevanceFactor = 0.95;
			break;

		case indexing::Dictionary::META_KEYWORDS:
			metaRelevanceFactor = 0.8;
			break;

		default:
			break;
		}

		resultEntries.Add(
			new QueryThreadResultEntry(
				META_RESULT,
				urlID,
				urlStageID,
				dictInfo->GetPositionForDictionaryID(dictID),
				occurence,
				queryProperties.relevanceMeta * matchRelevanceFactor * metaRelevanceFactor,
				found));
	}
	 */
}

}
