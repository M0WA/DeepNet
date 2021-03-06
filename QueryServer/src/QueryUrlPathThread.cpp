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

#include <DatabaseLayer.h>
#include <WhereConditionTableColumnCreateParam.h>
#include <WhereConditionTableColumn.h>
#include <TableDefinition.h>
#include <TableColumn.h>
#include <TableColumnDefinition.h>

#include <Pointer.h>
#include <Logging.h>
#include <TimeTools.h>

namespace queryserver {

QueryUrlPathThread::QueryUrlPathThread() {
}

QueryUrlPathThread::~QueryUrlPathThread() {
}

bool QueryUrlPathThread::GetPathPartIDs(std::vector<long long>& pathPartIDs,std::map<long long,size_t>& pathPartIDKeywordPos) const {

	const Query& query(queryThreadParam.GetConst()->query);
	const QueryProperties& queryProperties(query.properties);

	std::vector<std::string> keys;
	query.GetQueryKeywords(keys);

	if(!keys.size())
		return false;

	std::vector<std::string>::const_iterator iKey(keys.begin());
	for(size_t pos(0);iKey != keys.end();++iKey,++pos) {

		std::vector<database::WhereConditionTableColumn*> where;
		database::pathpartsTableBase::GetWhereColumnsFor_path(
			database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::Like(),
				database::WhereCondition::InitialComp(),
				database::WILDCARD_BOTH),
			*iKey,
			where);

		tools::Pointer<database::TableDefinition> pathPartDef(database::pathpartsTableBase::CreateTableDefinition());
		database::SelectStatement selectPathParts(pathPartDef.GetConst());
		selectPathParts.SelectAllColumns();
		selectPathParts.Where().AddColumns(where);

		selectPathParts.SetLimit(queryProperties.maxTotalResults);

		database::SelectResultContainer<database::pathpartsTableBase> resultPathParts;
		dbConn->Select(selectPathParts,resultPathParts);

		for(resultPathParts.ResetIter();!resultPathParts.IsIterEnd();resultPathParts.Next()) {
			const database::pathpartsTableBase* pathPartTbl(resultPathParts.GetConstIter());
			long long pathPartID(-1);
			pathPartTbl->Get_ID(pathPartID);
			pathPartIDs.push_back(pathPartID);
			pathPartIDKeywordPos[pathPartID] = pos;
		}
	}

	return true;
}

bool QueryUrlPathThread::ProcessResults(const std::vector<long long>& pathPartIDs,const std::map<long long,size_t>& pathPartIDKeywordPos) {

	const QueryProperties& queryProperties(queryThreadParam.GetConst()->query.properties);

	 if(pathPartIDs.size() == 0)
		 return false;

	std::vector<database::WhereConditionTableColumn*> where;
	database::urlspathpartTableBase::GetWhereColumnsFor_PATHPART_ID(
		database::WhereConditionTableColumnCreateParam(
				database::WhereCondition::Equals(),
				database::WhereCondition::InitialComp()),
		pathPartIDs,
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

	tools::Pointer<database::TableDefinition> tblDefPtr(database::urlspathpartTableBase::CreateTableDefinition());
	database::SelectStatement select(tblDefPtr.GetConst());

	select.SelectAllColumns();
	select.SelectAddColumn(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID());
	select.SelectAddColumn(database::urlstagesTableBase::GetDefinition_found_date());
	select.Where().AddColumns(where);

	database::urlspathpartTableBase::AddInnerJoinRightSideOn_URL_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URL_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(select);

	select.OrderBy().AddColumn(database::urlstagesTableBase::GetDefinition_found_date(),database::DESCENDING);
	select.SetLimit(queryProperties.maxTotalResults);

	database::SelectResultContainer<database::TableBase> results;
	dbConn->Select(select,results);

	tools::Pointer<database::TableColumnDefinition>
		colDefPathPartID(database::urlspathpartTableBase::GetDefinition_PATHPART_ID()),
		colDefUrlID(database::urlspathpartTableBase::GetDefinition_URL_ID()),
		colDefUrlStageID(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID()),
		colDefFound(database::urlstagesTableBase::GetDefinition_found_date());

	for(results.ResetIter();!results.IsIterEnd(); results.Next()) {

		const database::TableBase* curTbl(results.GetConstIter());

		const database::TableColumn
			*colPathPartID(curTbl->GetConstColumnByName(colDefPathPartID.GetConst()->GetColumnName())),
			*colUrlID(curTbl->GetConstColumnByName(colDefUrlID.GetConst()->GetColumnName())),
			*colUrlStageID(curTbl->GetConstColumnByName(colDefUrlStageID.GetConst()->GetColumnName())),
			*colFound(curTbl->GetConstColumnByName(colDefFound.GetConst()->GetColumnName()));

		if(!colPathPartID || !colUrlID || !colFound || !colUrlStageID) {
			log::Logging::LogWarn("invalid result row received for search query content result, ommitting entry");
			continue; }

		long long pathPartID(-1),urlID(-1),urlStageID(-1);
		struct tm found;

		colPathPartID->Get(pathPartID);
		colUrlID->Get(urlID);
		colUrlStageID->Get(urlStageID);
		colFound->Get(found);

		resultEntries.Add(
			new QueryThreadResultEntry(
				URLPATH_RESULT,
				urlID,
				urlStageID,
				pathPartIDKeywordPos.at(pathPartID),
				1,
				queryProperties.relevanceUrlPath,
				found));
	}

	return true;
}

void* QueryUrlPathThread::OnRun(){

	std::vector<long long> pathPartIDs;
	std::map<long long,size_t> pathPartIDKeywordPos;

	if(!GetPathPartIDs(pathPartIDs,pathPartIDKeywordPos))
		return 0;

	if(!ProcessResults(pathPartIDs,pathPartIDKeywordPos)) {
		return 0; }

	return 0;
}

}
