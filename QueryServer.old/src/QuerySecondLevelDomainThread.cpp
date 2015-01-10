/**
 *
 * @file QuerySecondLevelDomainThread.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QuerySecondLevelDomainThread.h"

#include "Query.h"
#include "QueryProperties.h"
#include "QueryThreadParam.h"
#include "QueryThreadResultEntry.h"

#include <DatabaseLayer.h>
#include <DatabaseHelper.h>
#include <TableDefinition.h>
#include <TableColumnDefinition.h>
#include <TableColumn.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <PerformanceCounter.h>
#include <StringTools.h>
#include <Pointer.h>
#include <Exception.h>
#include <Logging.h>

//
//TODO: move to config file
//
#define SECONDLEVELDOMAIN_HARDLIMIT 10000

namespace queryserver {

QuerySecondLevelDomainThread::QuerySecondLevelDomainThread() {
}

QuerySecondLevelDomainThread::~QuerySecondLevelDomainThread() {
}

void* QuerySecondLevelDomainThread::OnRun(){

	const Query& q(queryThreadParam.GetConst()->query);
	//const QueryProperties& queryProperties(q.GetQueryProperties());

	const std::vector<QueryKeywordGroup>& grps(q.GetKeywordGroups());
	std::vector<QueryKeywordGroup>::const_iterator igrp(grps.begin());

	std::vector<std::string> keywords;
	for(; igrp!=grps.end(); ++igrp) {
		const std::vector<QueryKeyword>& keys(igrp->GetKeywords());
		std::vector<QueryKeyword>::const_iterator ikey(keys.begin());
		for(;ikey != keys.end(); ++ikey) {
			ikey->GetKeywordsByType(QueryKeyword::CASEINSENSITIVE_MATCH,keywords); }
	}

	tools::StringTools::LowerStringsInVector(keywords);
	tools::ContainerTools::MakeUniqueVector(keywords,false);
	tools::Pointer<database::TableDefinition> ptrTblDef(database::secondleveldomainsTableBase::CreateTableDefinition());
	database::SelectStatement select(ptrTblDef.GetConst());

	database::TableColumnDefinition
		*colDefSecondLevelDomainID(database::secondleveldomainsTableBase::GetDefinition_ID()),
		*colDefSecondLevelDomain(database::secondleveldomainsTableBase::GetDefinition_domain()),
		*colDefUrlStageID(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID()),
		*colDefUrlID(database::latesturlstagesTableBase::GetDefinition_URL_ID()),
		*colDefFound(database::urlstagesTableBase::GetDefinition_found_date());

	select.SelectAddColumnAlias(colDefSecondLevelDomainID,colDefSecondLevelDomainID->GetColumnName());
	select.SelectAddColumnAlias(colDefSecondLevelDomain,colDefSecondLevelDomain->GetColumnName());
	select.SelectAddColumnAlias(colDefUrlStageID,colDefUrlStageID->GetColumnName());
	select.SelectAddColumnAlias(colDefUrlID,colDefUrlID->GetColumnName());
	select.SelectAddColumnAlias(colDefFound,colDefFound->GetColumnName());

	database::urlsTableBase::AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URL_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(select);

	std::vector<database::WhereConditionTableColumn*> where;
	database::secondleveldomainsTableBase::GetWhereColumnsFor_domain(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Like(),
			database::WhereCondition::InitialComp(),
			database::WILDCARD_BOTH),
		keywords,
		where );
	select.Where().AddColumns(where);

	//
	//TODO: set order by when setting a limit
	//
	select.SetLimit(SECONDLEVELDOMAIN_HARDLIMIT);

	database::SelectResultContainer<database::TableBase> selectresults;

	PERFORMANCE_LOG_START;
	try {
		dbConn->Select(select,selectresults);
	}
	catch(errors::Exception& e) {
		return (void*) -1; }
	PERFORMANCE_LOG_STOP("selecting result by second level domain");

	for(selectresults.ResetIter();!selectresults.IsIterEnd();selectresults.Next()) {

		const database::TableBase* curTbl(selectresults.GetConstIter());
		const database::TableColumn
			*colSecondLevelDomainID(curTbl->GetConstColumnByName(colDefSecondLevelDomainID->GetColumnName())),
			*colSecondLevelDomain(curTbl->GetConstColumnByName(colDefSecondLevelDomain->GetColumnName())),
			*colUrlStageID(curTbl->GetConstColumnByName(colDefUrlStageID->GetColumnName())),
			*colUrlID(curTbl->GetConstColumnByName(colDefUrlID->GetColumnName())),
			*colFound(curTbl->GetConstColumnByName(colDefFound->GetColumnName()));

		if(!colUrlID || !colSecondLevelDomainID || !colSecondLevelDomain || !colUrlStageID || !colFound) {
			log::Logging::LogWarn("invalid result row received for search query secondlevel domain result, ommitting entry");
			continue; }

		QueryThreadResultKey key;
		colUrlID->Get(key.urlId);
		colUrlStageID->Get(key.urlStageId);

		const Relevance& relSndLvl(q.GetQueryProperties().GetCriteria().GetRelevanceByCriteria(QueryCriteria::CRITERIA_DOMAIN));

		QueryThreadResultEntry& e(results[key]);
		colSecondLevelDomainID->Get(e.secondLvlDomainId);
		colFound->Get(e.found);
		e.AddRelevanceForType(SECONDLEVELDOMAIN_RESULT,relSndLvl);
	}
	return 0;
}

}
