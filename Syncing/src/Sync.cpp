/*
 * @file Sync.cpp
 * @date Dec 2, 2017
 * @author Moritz Wagner
 */

#include "Sync.h"

#include <TimeTools.h>
#include <PerformanceCounter.h>
#include <ContainerTools.h>

#include <DatabaseLayer.h>
#include <TableDefinition.h>
#include <TableColumn.h>
#include <TableBase.h>
#include <OrderByClauseDirection.h>

#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#define RESCHEDULE_INTERVAL 30

namespace syncing {

Sync::Sync() {

}

Sync::~Sync() {
}

bool Sync::UnlockSecondLevelDomain(database::DatabaseConnection* db, const long long& crawlerID, const long long& sld) {

	database::locksecondleveldomainTableBase lockSecondLevel;
	lockSecondLevel.Set_CRAWLERSESSION_ID(0);
	if(sld != -1) {
		lockSecondLevel.Set_SECONDLEVELDOMAIN_ID(sld); }

	lockSecondLevel.Set_schedule( tools::TimeTools::NowUTCAdd( RESCHEDULE_INTERVAL > 0 ? RESCHEDULE_INTERVAL : 0 ) );

	database::TableBaseUpdateParam remParam;
	remParam.limit = -1;

	database::locksecondleveldomainTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(), database::WhereCondition::InitialComp()),
		0,
		remParam.whereCols);

	if(sld != -1) {
		database::locksecondleveldomainTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::And()),
			sld,
			remParam.whereCols);
	}

	PERFORMANCE_LOG_START;
	lockSecondLevel.Update(db,remParam);
	PERFORMANCE_LOG_STOP("remove secondlevel reservation");

	long long aff(0);
	db->AffectedRows(aff);
	if(aff <= 0) {
		return false; }
	return true;
}

bool Sync::LockSecondLevelDomain(database::DatabaseConnection* db, const long long& crawlerID, long long& sld) {

	PERFORMANCE_LOG_START;

	database::TableBaseUpdateParam param;
	param.onlyDirtyColumns = true;
	param.limit = 1;

	database::OrderByColumn entry;
	entry.colDef = database::locksecondleveldomainTableBase::GetDefinition_schedule();
	entry.dir    = database::ASCENDING;
	param.orderCols.push_back(entry);

	database::locksecondleveldomainTableBase::GetWhereColumnsFor_schedule(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::SmallerOrEqual(),	database::WhereCondition::InitialComp()),
		tools::TimeTools::NowUTC(),
		param.whereCols);

	if(sld != -1) {
		database::locksecondleveldomainTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),	database::WhereCondition::And()),
			sld,
			param.whereCols);
	}

	database::locksecondleveldomainTableBase tblLockDomain;
	tblLockDomain.Set_CRAWLERSESSION_ID(crawlerID);
	tblLockDomain.Set_schedule(tools::TimeTools::NowUTCAdd(RESCHEDULE_INTERVAL));

	PERFORMANCE_LOG_RESTART;
	tblLockDomain.Update(db,param);
	PERFORMANCE_LOG_STOP("locking new second level domain id to crawl");

	database::SelectResultContainer<database::locksecondleveldomainTableBase> tblLockDomains;

	PERFORMANCE_LOG_RESTART;
	database::locksecondleveldomainTableBase::GetBy_CRAWLERSESSION_ID(db,crawlerID,tblLockDomains);
	PERFORMANCE_LOG_STOP("lookup second level domain id to crawl");

	if(tblLockDomains.Size() == 0){
		return false; }

	tblLockDomains.GetConstIter()->Get_SECONDLEVELDOMAIN_ID(sld);
	return true;
}

long long Sync::GetRescheduleInterval() {
	return RESCHEDULE_INTERVAL;
}

}
