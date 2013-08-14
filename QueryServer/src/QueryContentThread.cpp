/**
 *
 * @file QueryContentThread.cpp
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#include "QueryContentThread.h"

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

QueryContentThread::QueryContentThread()
: queryserver::QueryThread() {
}

QueryContentThread::~QueryContentThread() {
}

void QueryContentThread::OnInitThreadInstance() {

	const QueryThreadParam* queryparam(queryThreadParam.GetConst());
	const std::vector<std::string>& vecKey(queryparam->query.keywords);

	dictIDs.resize(vecKey.size(),-1);
	if(!queryparam->query.properties.caseSensitive) {
		caseInsensitiveDictIDs.resize(vecKey.size(),std::vector<long long>()); }
}

void QueryContentThread::OnDestroyThreadInstance(){

	dictIDs.clear();
	caseInsensitiveDictIDs.clear();
}

void* QueryContentThread::OnRun() {

	if(!GetIDsForKeywords()) {
		return (void*)1; }

	if(!GetIDsForCaseInsensitiveKeywords()) {
		return (void*)1; }

	if(!GetUrlsForKeywords()) {
		return (void*)1; }

	return 0;
}

bool QueryContentThread::GetIDsForKeywords() {

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

bool QueryContentThread::GetIDsForCaseInsensitiveKeywords() {

	const QueryThreadParam* queryparam(queryThreadParam.GetConst());
	const QueryProperties& queryprop(queryparam->query.properties);
	const std::vector<std::string>& vecLower(queryparam->query.lowerKeywords);

	if(queryprop.caseSensitive)
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

bool QueryContentThread::GetUrlsForKeywords() {

	std::vector<long long> allDictIDs;
	allDictIDs.insert(allDictIDs.end(),dictIDs.begin(),dictIDs.end());
	const QueryProperties& queryProperties(queryThreadParam.GetConst()->query.properties);

	if(!queryProperties.caseSensitive) {
		tools::ContainerTools::AppendFlattenedVector(caseInsensitiveDictIDs,allDictIDs);	}

	tools::ContainerTools::MakeUniqueVector(allDictIDs,true);

	tools::Pointer<database::TableDefinition> tblDefPtr(database::dockeyTableBase::CreateTableDefinition());
	database::SelectStatement select(tblDefPtr.GetConst());

	database::TableColumnDefinition
		*colDefDictID(database::dockeyTableBase::GetDefinition_DICT_ID()),
		*colDefOccurrence(database::dockeyTableBase::GetDefinition_occurrence()),
		*colDefUrlStageID(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID()),
		*colDefUrlID(database::latesturlstagesTableBase::GetDefinition_URL_ID()),
		*colDefFound(database::urlstagesTableBase::GetDefinition_found_date());

	select.SelectAddColumnAlias(colDefDictID,colDefDictID->GetColumnName());
	select.SelectAddColumnAlias(colDefOccurrence,colDefOccurrence->GetColumnName());
	select.SelectAddColumnAlias(colDefUrlStageID,colDefUrlStageID->GetColumnName());
	select.SelectAddColumnAlias(colDefUrlID,colDefUrlID->GetColumnName());
	select.SelectAddColumnAlias(colDefFound,colDefFound->GetColumnName());

	database::dockeyTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URLSTAGE_ID(select);

	std::vector<database::WhereConditionTableColumn*> where;
	database::dockeyTableBase::GetWhereColumnsFor_DICT_ID(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::InitialComp()),
		allDictIDs,
		where);

	if(queryProperties.limitSecondLevelDomainID > 0) {
		database::urlsTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::Equals(),
				database::WhereCondition::And()),
			queryProperties.limitSecondLevelDomainID,
			where);
	}

	if(queryProperties.limitSubDomainID > 0) {
		database::urlsTableBase::GetWhereColumnsFor_SUBDOMAIN_ID(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::Equals(),
				database::WhereCondition::And()),
			queryProperties.limitSubDomainID,
			where);
	}

	if(!tools::TimeTools::IsZero(queryProperties.maxAge)) {
		database::urlstagesTableBase::GetWhereColumnsFor_found_date(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::GreaterOrEqual(),
				database::WhereCondition::And()),
			queryProperties.maxAge,
			where);
	}

	select.Where().AddColumns(where);

	if(queryProperties.maxResults != 0)
		select.SetLimit(queryProperties.maxResults);
	else {
		//
		//TODO: do not hardcode this limit here
		//
		select.SetLimit(10000);	}


	database::SelectResultContainer<database::TableBase> results;
	try {
		dbConn->Select(select,results);
	}
	catch(database::DatabaseException& e) {
		return false;
	}

	return ProcessResults(results);
}

bool QueryContentThread::ProcessResults(database::SelectResultContainer<database::TableBase>& results) {

	const QueryProperties& queryProperties(queryThreadParam.GetConst()->query.properties);

	tools::Pointer<database::TableColumnDefinition>
		colDefUrlIDPtr(database::latesturlstagesTableBase::GetDefinition_URL_ID()),
		colDefUrlStageIDPtr(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID()),
		colDefOccurencePtr(database::dockeyTableBase::GetDefinition_occurrence()),
		colDefDictIDPtr(database::dockeyTableBase::GetDefinition_DICT_ID()),
		colDefFoundPtr(database::urlstagesTableBase::GetDefinition_found_date());

	const database::TableColumnDefinition
		*colDefUrlID(colDefUrlIDPtr.GetConst()),
		*colDefUrlStageID(colDefUrlStageIDPtr.GetConst()),
		*colDefOccurence(colDefOccurencePtr.GetConst()),
		*colDefDictID(colDefDictIDPtr.GetConst()),
		*colDefFound(colDefFoundPtr.GetConst());

	for(results.ResetIter();!results.IsIterEnd();results.Next()) {

		const database::TableBase* curTbl(results.GetConstIter());

		const database::TableColumn
			*colUrlID(curTbl->GetConstColumnByName(colDefUrlID->GetColumnName())),
			*colUrlStageID(curTbl->GetConstColumnByName(colDefUrlStageID->GetColumnName())),
			*colOccurence(curTbl->GetConstColumnByName(colDefOccurence->GetColumnName())),
			*colDictID(curTbl->GetConstColumnByName(colDefDictID->GetColumnName())),
			*colFound(curTbl->GetConstColumnByName(colDefFound->GetColumnName()));

		if(!colUrlID || !colDictID || !colOccurence || !colFound || !colUrlStageID) {
			log::Logging::LogWarn("invalid result row received for search query content result, ommitting entry");
			continue; }

		long long urlID(-1),urlStageID(-1), dictID(-1), occurence(-1);
		struct tm found;
		colUrlID->Get(urlID);
		colUrlStageID->Get(urlStageID);
		colDictID->Get(dictID);
		colOccurence->Get(occurence);
		colFound->Get(found);

		resultEntries.Add(
			new QueryThreadResultEntry(
				CONTENT_RESULT,
				urlID,
				urlStageID,
				dictIDPosition[dictID],
				occurence,
				queryProperties.relevanceContent,
				found));
	}

	return true;
}

}
