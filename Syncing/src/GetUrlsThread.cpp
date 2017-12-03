/*
 * @file GetUrlsThread.cpp
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#include "GetUrlsThread.h"

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

namespace syncing {

GetUrlsThread::GetUrlsThread()
: threading::Thread(GetUrlsThread::GetUrlsThreadFunc,false){

}

GetUrlsThread::~GetUrlsThread() {
}

bool GetUrlsThread::GetNextUrls(database::DatabaseConnection* db,GetUrlsThreadParam* p, long long& sld) {

	//fetch urls for current second level domains and crawler id
	database::TableBaseUpdateParam fetchUrlParam;
	fetchUrlParam.limit = p->urlCount;

	database::syncurlsTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::InitialComp()),
		sld,
		fetchUrlParam.whereCols);

	database::syncurlsTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::And()),
		0,
		fetchUrlParam.whereCols);

	database::syncurlsTableBase::GetWhereColumnsFor_schedule(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::SmallerOrEqual(), database::WhereCondition::And()),
		tools::TimeTools::NowUTC(),
		fetchUrlParam.whereCols);

	if(p->urlCount > 0) {
		database::OrderByColumn colOrder;
		colOrder.colDef = database::syncurlsTableBase::GetDefinition_schedule();
		colOrder.dir = database::ASCENDING;
		fetchUrlParam.orderCols.push_back(colOrder);
	}

	database::syncurlsTableBase syncUrl;
	syncUrl.Set_CRAWLERSESSION_ID(p->crawlerID);
	syncUrl.Set_schedule(tools::TimeTools::NowUTCAdd(Sync::GetRescheduleInterval()));

	database::SelectResultContainer<database::syncurlsTableBase> syncUrlTbls;

	PERFORMANCE_LOG_RESTART;
	try {
		PERFORMANCE_LOG_START;
		syncUrl.Update(db,fetchUrlParam);
		PERFORMANCE_LOG_STOP("setting crawlersession to syncurls");

		PERFORMANCE_LOG_RESTART;
		database::syncurlsTableBase::GetBy_CRAWLERSESSION_ID(db,p->crawlerID,syncUrlTbls);
		PERFORMANCE_LOG_STOP("finding syncurls urls reserverd by crawlersession");
	}
	CATCH_EXCEPTION(database::DatabaseException,e,0)
		// database exceptions are considered
		// nonfatal because we will just sleep
		// and come back later to try again
	}
	PERFORMANCE_LOG_STOP("fetching sync urls to crawl");

	syncUrlTbls.ResetIter();
	for(;!syncUrlTbls.IsIterEnd(); syncUrlTbls.Next()) {
		long long urlID(-1);
		syncUrlTbls.GetIter()->Get_URL_ID(urlID);
		urlIDs.push_back(urlID);
	}

	database::TableBaseUpdateParam clearParam;
	clearParam.limit = -1;

	database::syncurlsTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),	database::WhereCondition::InitialComp()),
		p->crawlerID,
		clearParam.whereCols);

	database::syncurlsTableBase clearSession;
	clearSession.Set_CRAWLERSESSION_ID(0);
	clearSession.Set_schedule(tools::TimeTools::NowUTCAdd(Sync::GetRescheduleInterval()));

	PERFORMANCE_LOG_RESTART;
	clearSession.Update(db,clearParam);
	PERFORMANCE_LOG_STOP("rescheduling sync urls to crawl");

	return true;
}

bool GetUrlsThread::GetUrls(database::DatabaseConnection* db,GetUrlsThreadParam* p) {
	long long sld(p->secondlevelDomain);

	if(!Sync::LockSecondLevelDomain(db,p->crawlerID,sld)) {
		return false; }

	long long reqSLD(sld);
	bool success(GetNextUrls(db,p,sld));

	if(reqSLD == -1) {
		Sync::UnlockSecondLevelDomain(db,p->crawlerID,sld);
	}
	else if(reqSLD != sld) {
		//check if locked the correct secondlevel domain
		Sync::UnlockSecondLevelDomain(db,p->crawlerID,sld);
		log::Logging::LogError("locked wrong secondlevel domain");
		return false;
	}

	return success;
}

void* GetUrlsThread::GetUrlsThreadFunc(threading::Thread::THREAD_PARAM* param) {

	log::Logging::RegisterThreadID("GetUrlsThread");

	GetUrlsThreadParam* p(reinterpret_cast<GetUrlsThreadParam*>(param->pParam));
	GetUrlsThread* instance(reinterpret_cast<GetUrlsThread*>(p->instance));

	database::DatabaseHelper helper;
	database::DatabaseConnection* db(helper.CreateConnection(p->dbConf));

	PERFORMANCE_LOG_START;
	if(!instance->GetUrls(db,p)) {
		delete p;
		return (void*)1;
	}
	PERFORMANCE_LOG_STOP("GetUrls overall");

	delete p;
	return NULL;
}

}
