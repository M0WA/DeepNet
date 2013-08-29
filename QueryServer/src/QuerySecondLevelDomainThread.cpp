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

#include <StringTools.h>
#include <Pointer.h>
#include <Exception.h>
#include <Logging.h>

namespace queryserver {

QuerySecondLevelDomainThread::QuerySecondLevelDomainThread() {
}

QuerySecondLevelDomainThread::~QuerySecondLevelDomainThread() {
}

void* QuerySecondLevelDomainThread::OnRun(){

	const Query& query(queryThreadParam.GetConst()->query);
	const QueryProperties& queryProperties(query.properties);
	std::vector<std::string> lowerKeywords;
	query.GetLoweredKeywords(lowerKeywords);
	if(lowerKeywords.size()) {
		return 0; }

	tools::Pointer<database::TableDefinition> ptrTblDef(database::secondleveldomainsTableBase::CreateTableDefinition());
	database::SelectStatement select(ptrTblDef.GetConst());

	database::TableColumnDefinition
		*colDefSecondLevelDomain(database::secondleveldomainsTableBase::GetDefinition_domain()),
		*colDefUrlStageID(database::latesturlstagesTableBase::GetDefinition_URLSTAGE_ID()),
		*colDefUrlID(database::latesturlstagesTableBase::GetDefinition_URL_ID()),
		*colDefFound(database::urlstagesTableBase::GetDefinition_found_date());

	select.SelectAddColumnAlias(colDefSecondLevelDomain,colDefSecondLevelDomain->GetColumnName());
	select.SelectAddColumnAlias(colDefUrlStageID,colDefUrlStageID->GetColumnName());
	select.SelectAddColumnAlias(colDefUrlID,colDefUrlID->GetColumnName());
	select.SelectAddColumnAlias(colDefFound,colDefFound->GetColumnName());

	database::urlsTableBase::AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinLeftSideOn_URL_ID(select);
	database::latesturlstagesTableBase::AddInnerJoinRightSideOn_URLSTAGE_ID(select);

	std::vector<database::WhereConditionTableColumn*> where;

	database::secondleveldomainsTableBase::GetWhereColumnsFor_domain(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Like(),database::WhereCondition::InitialComp(),database::WILDCARD_BOTH),
		lowerKeywords,
		where );
	select.Where().AddColumns(where);

	//
	//TODO: limit results here
	//

	database::SelectResultContainer<database::TableBase> results;
	try {
		dbConn->Select(select,results);
	}
	catch(errors::Exception& e) {
		return (void*) -1;
	}

	for(results.ResetIter();!results.IsIterEnd();results.Next()) {

		const database::TableBase* curTbl(results.GetConstIter());
		const database::TableColumn
			*colSecondLevelDomain(curTbl->GetConstColumnByName(colDefSecondLevelDomain->GetColumnName())),
			*colUrlStageID(curTbl->GetConstColumnByName(colDefUrlStageID->GetColumnName())),
			*colUrlID(curTbl->GetConstColumnByName(colDefUrlID->GetColumnName())),
			*colFound(curTbl->GetConstColumnByName(colDefFound->GetColumnName()));

		if(!colUrlID || !colSecondLevelDomain || !colUrlStageID || !colFound) {
			log::Logging::LogWarn("invalid result row received for search query secondlevel domain result, ommitting entry");
			continue; }

		long long urlID(-1),urlStageID(-1);
		struct tm found;
		std::string domainName;

		colSecondLevelDomain->Get(domainName);
		colUrlID->Get(urlID);
		colUrlStageID->Get(urlStageID);
		colFound->Get(found);

		resultEntries.Add(
			new QueryThreadResultEntry(
				SECONDLEVELDOMAIN_RESULT,
				urlID,
				urlStageID,
				0, //query.GetPositionByKeyword(domainName), //TODO: find real position
				1,
				queryProperties.relevanceSecondLevelDomain,
				found));
	}

	return 0;
}

}
