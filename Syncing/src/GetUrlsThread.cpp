/*
 * @file GetUrlsThread.cpp
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#include "GetUrlsThread.h"

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

namespace syncing {

GetUrlsThread::GetUrlsThread()
: threading::Thread(GetUrlsThread::GetUrlsThreadFunc,false){

}

GetUrlsThread::~GetUrlsThread() {
}

bool GetUrlsThread::UnlockSecondLevelDomain(long long& sld) {
	return false;
}

bool GetUrlsThread::LockSecondLevelDomain(GetUrlsThreadParam* p, long long& sld) {

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
	tblLockDomain.Set_CRAWLERSESSION_ID(p->crawlerID);
	tblLockDomain.Set_schedule(tools::TimeTools::NowUTCAdd(p->minAge));

	PERFORMANCE_LOG_RESTART;
	tblLockDomain.Update(p->dbConn,param);
	PERFORMANCE_LOG_STOP("locking new second level domain id to crawl");

	if(sld == -1) {
		database::SelectResultContainer<database::locksecondleveldomainTableBase> tblLockDomains;

		PERFORMANCE_LOG_RESTART;
		database::locksecondleveldomainTableBase::GetBy_CRAWLERSESSION_ID(p->dbConn,p->crawlerID,tblLockDomains);
		PERFORMANCE_LOG_STOP("lookup second level domain id to crawl");

		if(tblLockDomains.Size() == 0){
			return false; }

		tblLockDomains.GetConstIter()->Get_SECONDLEVELDOMAIN_ID(sld);
	}
	return true;
}

bool GetUrlsThread::GetNextUrls(GetUrlsThreadParam* p, long long& sld) {
	return false;
}

bool GetUrlsThread::GetUrls(GetUrlsThreadParam* p) {
	long long sld(p->secondlevelDomain);

	if(!LockSecondLevelDomain(p,sld)) {
		return false; }

	bool success(GetNextUrls(p,sld));

	UnlockSecondLevelDomain(sld);
	return success;
}

void* GetUrlsThread::GetUrlsThreadFunc(threading::Thread::THREAD_PARAM* param) {

	GetUrlsThreadParam* p(reinterpret_cast<GetUrlsThreadParam*>(param));
	GetUrlsThread* instance(dynamic_cast<GetUrlsThread*>(p->instance));

	if(!instance->GetUrls(p)) {
	}

	return NULL;
}

}
