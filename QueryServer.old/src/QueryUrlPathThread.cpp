/**
 *
 * @file QueryUrlPathThread.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QueryUrlPathThread.h"

#include "Query.h"
#include "QueryThreadParam.h"
#include "QueryThreadResultEntry.h"

#include <Logging.h>
#include <PerformanceCounter.h>
#include <Pointer.h>
#include <ContainerTools.h>

#include <DatabaseLayer.h>
#include <TableDefinition.h>
#include <TableColumnDefinition.h>
#include <TableColumn.h>

/*
#include <WhereConditionTableColumnCreateParam.h>
#include <WhereConditionTableColumn.h>
*/

//
//TODO: move to config file
//
#define URLPATHPART_HARDLIMIT 10000

namespace queryserver {

QueryUrlPathThread::QueryUrlPathThread()
: queryserver::QueryThread() {
}

QueryUrlPathThread::~QueryUrlPathThread() {
}

void* QueryUrlPathThread::OnRun() {

	std::map<std::string, std::vector<long long> > pathPartIDs;
	if(!GetPathPartIDs(pathPartIDs)) {
		return 0; }

	if(!ProcessResults(pathPartIDs)) {
		return 0; }

	return 0;
}

bool QueryUrlPathThread::GetPathPartIDs(std::map<std::string, std::vector<long long> >& pathPartIDs) const {

	const Query& q(queryThreadParam.GetConst()->query);

	const std::vector<QueryKeywordGroup>& grps(q.GetKeywordGroups());
	std::vector<QueryKeywordGroup>::const_iterator igrp(grps.begin());

	std::map<QueryKeyword::QueryKeywordType, std::vector<std::string> > keywords;
	std::vector<database::WhereConditionTableColumn*> where;
	for(; igrp!=grps.end(); ++igrp) {

		const std::vector<QueryKeyword>& keys(igrp->GetKeywords());
		std::vector<QueryKeyword>::const_iterator ikey(keys.begin());

		for(;ikey != keys.end(); ++ikey) {
			QueryKeyword::QueryKeywordType matchtype(QueryKeyword::EXACT_MATCH);
			ikey->GetKeywordsByType(matchtype,keywords);
		}
	}

	std::vector<std::string>& exactMatch(keywords.at(QueryKeyword::EXACT_MATCH));
	tools::ContainerTools::MakeUniqueVector(exactMatch,false);

	std::vector<std::string>::const_iterator iexact(exactMatch.begin());
	for(;iexact != exactMatch.end();++iexact) {
		database::pathpartsTableBase::GetWhereColumnsFor_path(
			database::WhereConditionTableColumnCreateParam(
				database::LIKE,
				database::INITIAL_COMPOSITE_OPERATOR_TYPE,
				database::WILDCARD_BOTH),
			*iexact,
			where);
	}

	tools::Pointer<database::TableDefinition> pathPartDef(database::pathpartsTableBase::CreateTableDefinition());
	database::SelectStatement selectPathParts(pathPartDef.GetConst());
	selectPathParts.SelectAllColumns();
	selectPathParts.Where().AddColumns(where);

	//
	//TODO: set order by when setting a limit
	//
	selectPathParts.SetLimit(URLPATHPART_HARDLIMIT);

	database::DatabaseConnection* db(queryThreadParam.GetConst()->dbConn);
	database::SelectResultContainer<database::pathpartsTableBase> resultPathParts;

	PERFORMANCE_LOG_START;
	db->Select(selectPathParts,resultPathParts);
	PERFORMANCE_LOG_STOP("selecting result by url path information");

	for(resultPathParts.ResetIter();!resultPathParts.IsIterEnd();resultPathParts.Next()) {
		std::string path;
		long long pathPartID(-1);
		resultPathParts.GetConstIter()->Get_ID(pathPartID);
		resultPathParts.GetConstIter()->Get_path(path);
		pathPartIDs[path].push_back(pathPartID); }

	return true;
}

bool QueryUrlPathThread::ProcessResults(const std::map<std::string, std::vector<long long> >& pathPartIDs) {

	if(pathPartIDs.size() == 0)
		return false;

	std::vector<long long> ids;
	std::map<std::string, std::vector<long long> >::const_iterator iMap(pathPartIDs.begin());
	for(;iMap != pathPartIDs.end(); ++iMap) {
		ids.insert(ids.end(),iMap->second.begin(),iMap->second.end()); }
	tools::ContainerTools::MakeUniqueVector(ids,false);

	std::vector<database::WhereConditionTableColumn*> where;
	database::urlspathpartTableBase::GetWhereColumnsFor_PATHPART_ID(
		database::WhereConditionTableColumnCreateParam(database::EQUALS,database::INITIAL_COMPOSITE_OPERATOR_TYPE),
		ids,
		where);

	tools::Pointer<database::TableDefinition> tblDefPtr(database::urlspathpartTableBase::CreateTableDefinition());
	database::SelectStatement select(tblDefPtr.GetConst());

	select.SelectAllColumns();
	select.SelectAddColumn(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID());
	select.SelectAddColumn(database::urlstagesTableBase::GetDefinition_found_date());
	select.Where().AddColumns(where);

	database::urlspathpartTableBase::AddInnerJoinRightSideOn_URL_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URL_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(select);

	//
	//TODO: set order by when setting a limit
	//
	select.SetLimit(URLPATHPART_HARDLIMIT);

	database::SelectResultContainer<database::TableBase> resultsDB;
	dbConn->Select(select,resultsDB);

	tools::Pointer<database::TableColumnDefinition>
		colDefSecondLevelID(database::urlsTableBase::GetDefinition_SECONDLEVELDOMAIN_ID()),
		colDefPathPartID(database::urlspathpartTableBase::GetDefinition_PATHPART_ID()),
		colDefUrlID(database::urlspathpartTableBase::GetDefinition_URL_ID()),
		colDefUrlStageID(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID()),
		colDefFound(database::urlstagesTableBase::GetDefinition_found_date());

	for(resultsDB.ResetIter();!resultsDB.IsIterEnd(); resultsDB.Next()) {

		const database::TableBase* curTbl(resultsDB.GetConstIter());

		const database::TableColumn
			*colSecondLevelID(curTbl->GetConstColumnByName(colDefSecondLevelID.GetConst()->GetColumnName())),
			*colUrlID(curTbl->GetConstColumnByName(colDefUrlID.GetConst()->GetColumnName())),
			*colUrlStageID(curTbl->GetConstColumnByName(colDefUrlStageID.GetConst()->GetColumnName())),
			*colFound(curTbl->GetConstColumnByName(colDefFound.GetConst()->GetColumnName()));

		if(!colSecondLevelID || !colUrlID || !colFound || !colUrlStageID) {
			log::Logging::LogWarn("invalid result row received for url path part, ommitting entry");
			continue; }

		QueryThreadResultKey key;
		colUrlID->Get(key.urlId);
		colUrlStageID->Get(key.urlStageId);

		const Query& query(queryThreadParam.GetConst()->query);
		const Relevance& relUrl(query.GetQueryProperties().GetCriteria().GetRelevanceByCriteria(QueryCriteria::CRITERIA_PATH));

		QueryThreadResultEntry& e(results[key]);
		colSecondLevelID->Get(e.secondLvlDomainId);
		colFound->Get(e.found);
		e.AddRelevanceForType(URLPATH_RESULT,relUrl);
	}

	return true;
}

}
