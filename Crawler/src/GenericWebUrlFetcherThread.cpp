/**
 * @file GenericWebUrlFetcherThread.cpp
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#include "GenericWebUrlFetcherThread.h"

#include <TimeTools.h>
#include <PerformanceCounter.h>
#include <ContainerTools.h>

#include <TableDefinition.h>
#include <TableColumn.h>
#include <OrderByClauseDirection.h>

#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <URLInvalidSecondLevelDomainIDException.h>

//TODO: put this in config file
#define MAX_SECONDLEVEL_PER_THREAD                30 //max. 30 secondlevel domains scanned in parallel
#define MAX_AGE_MINUTES_SECONDLEVELDOMAIN         10 //10 minutes
#define RESCHEDULE_MAX_AGE_DAYS_SECONDLEVELDOMAIN 1  //1  day

namespace crawler {

GenericWebUrlFetcherThread::GenericWebUrlFetcherThread()
: UrlFetcherThread()
, urlsFound(false) {
}

GenericWebUrlFetcherThread::~GenericWebUrlFetcherThread() {
}


bool GenericWebUrlFetcherThread::GetNextSecondLevelDomain()
{
	if(!LockNextSecondLevelDomain()){
		OnIdle();
		return false; }

	database::SelectResultContainer<database::locksecondleveldomainTableBase> tblLockDomains;
	database::locksecondleveldomainTableBase::GetBy_CRAWLERSESSION_ID(DB().Connection(),crawlerSessionID,tblLockDomains);
	if(tblLockDomains.Size() == 0){
		OnIdle();
		return false; }

	if(!CheckSecondLevelDomainTimeout(tblLockDomains)){
		OnIdle();
		return false; }

	return true;
}

bool GenericWebUrlFetcherThread::CheckSecondLevelDomainTimeout(database::SelectResultContainer<database::locksecondleveldomainTableBase>& tblLockDomains) {

	tblLockDomains.ResetIter();
	for(;!tblLockDomains.IsIterEnd(); tblLockDomains.Next()){

		long long secondLevelDomainID = -1;
		tblLockDomains.GetIter()->Get_SECONDLEVELDOMAIN_ID(secondLevelDomainID);
		if(secondLevelDomainID <= 0) {
			THROW_EXCEPTION(caching::URLInvalidSecondLevelDomainIDException,secondLevelDomainID,-1);}

		if(syncSecondLevelDomains.count(secondLevelDomainID) == 0){
			syncSecondLevelDomains[secondLevelDomainID] = time(0); }
	}

	return true;
}

bool GenericWebUrlFetcherThread::LockNextSecondLevelDomain() {
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

	//crawl in normal mode
	database::locksecondleveldomainTableBase tblLockDomain;
	tblLockDomain.Set_CRAWLERSESSION_ID(crawlerSessionID);
	tblLockDomain.Set_schedule(tools::TimeTools::NowUTCAdd(fetcherThreadParam->minAge));

	PERFORMANCE_LOG_RESTART;
	tblLockDomain.Update(DB().Connection(),param);
	PERFORMANCE_LOG_STOP("locking new second level domain id to crawl");

	return true;
}

bool GenericWebUrlFetcherThread::ReserveNextUrls(std::vector<long long>& urlIDs)
{
	PERFORMANCE_LOG_START;

	//fetch a new domain if neccessary
	if(!urlsFound || syncSecondLevelDomains.size() == 0) {

		if(!GetNextSecondLevelDomain()) {
			OnIdle();
			if(!syncSecondLevelDomains.size())
				return false;
		}

		CheckMaxSecondLevelDomain();
	}

	//fetch urls for current second level domains and crawler id
	database::TableBaseUpdateParam fetchUrlParam;
	fetchUrlParam.limit = fetcherThreadParam->maxPerSelect;

	std::vector<long long> vecWhereSndLevelDomainID;
	tools::ContainerTools::Map1ToVector(syncSecondLevelDomains,vecWhereSndLevelDomainID);

	database::syncurlsTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::InitialComp()),
		vecWhereSndLevelDomainID,
		fetchUrlParam.whereCols);

	database::syncurlsTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::And()),
		0,
		fetchUrlParam.whereCols);

	database::syncurlsTableBase::GetWhereColumnsFor_schedule(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::SmallerOrEqual(), database::WhereCondition::And()),
		tools::TimeTools::NowUTC(),
		fetchUrlParam.whereCols);

	if(fetcherThreadParam->maxPerSelect > 0) {
		database::OrderByColumn colOrder;
		colOrder.colDef = database::syncurlsTableBase::GetDefinition_schedule();
		colOrder.dir = database::ASCENDING;
		fetchUrlParam.orderCols.push_back(colOrder);
	}

	database::syncurlsTableBase syncUrl;
	syncUrl.Set_CRAWLERSESSION_ID(crawlerSessionID);
	syncUrl.Set_schedule(tools::TimeTools::NowUTCAdd(fetcherThreadParam->minAge));

	PERFORMANCE_LOG_RESTART;
	syncUrl.Update(DB().Connection(),fetchUrlParam);
	PERFORMANCE_LOG_STOP("setting crawlersession to syncurls");

	database::SelectResultContainer<database::syncurlsTableBase> syncUrlTbls;

	PERFORMANCE_LOG_RESTART;
	database::syncurlsTableBase::GetBy_CRAWLERSESSION_ID(DB().Connection(),crawlerSessionID,syncUrlTbls);
	PERFORMANCE_LOG_STOP("fetching sync urls to crawl");

	if( syncUrlTbls.Size() == 0 ) {
		urlsFound = false;
		OnIdle();
		return false;
	}
	urlsFound = true;

	syncUrlTbls.ResetIter();
	for(;!syncUrlTbls.IsIterEnd(); syncUrlTbls.Next()) {
		long long urlID = -1;
		syncUrlTbls.GetIter()->Get_URL_ID(urlID);
		urlIDs.push_back(urlID);
	}

	database::TableBaseUpdateParam clearParam;
	clearParam.limit = -1;

	database::syncurlsTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),	database::WhereCondition::InitialComp()),
		crawlerSessionID,
		clearParam.whereCols);

	database::syncurlsTableBase clearSession;
	clearSession.Set_CRAWLERSESSION_ID(0);
	clearSession.Set_schedule(tools::TimeTools::NowUTCAdd(fetcherThreadParam->minAge));

	PERFORMANCE_LOG_RESTART;
	clearSession.Update(DB().Connection(),clearParam);
	PERFORMANCE_LOG_STOP("rescheduling sync urls to crawl");
	return true;
}

void GenericWebUrlFetcherThread::RemoveSecondLevelReservation(const long long secondLevelID, const int addSchedule)
{
	PERFORMANCE_LOG_START;

	if(syncSecondLevelDomains.count(secondLevelID) > 0 )
		syncSecondLevelDomains.erase(secondLevelID);

	database::locksecondleveldomainTableBase lockSecondLevel;
	lockSecondLevel.Set_CRAWLERSESSION_ID(0);
	lockSecondLevel.Set_SECONDLEVELDOMAIN_ID(secondLevelID);
	lockSecondLevel.Set_schedule( tools::TimeTools::NowUTCAdd( addSchedule > 0 ? addSchedule : 0 ) );

	database::TableBaseUpdateParam remParam;
	remParam.limit = -1;

	database::locksecondleveldomainTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::NotEquals(), database::WhereCondition::InitialComp()),
		0,
		remParam.whereCols);

	database::locksecondleveldomainTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
		database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::And()),
		secondLevelID,
		remParam.whereCols);

	PERFORMANCE_LOG_RESTART;
	lockSecondLevel.Update(DB().Connection(),remParam);
	PERFORMANCE_LOG_STOP("remove secondlevel reservation");
}

void GenericWebUrlFetcherThread::OnExit()
{
	//remove all reservations
	std::vector<long long> vecResSndLvl;
	std::map<long long,time_t>::iterator iterSecondLevel = syncSecondLevelDomains.begin();
	for(;iterSecondLevel != syncSecondLevelDomains.end();++iterSecondLevel) {
		vecResSndLvl.push_back(iterSecondLevel->first); }
	std::vector<long long>::iterator iterResSndLvl = vecResSndLvl.begin();
	for(;iterResSndLvl != vecResSndLvl.end();++iterResSndLvl) {
		RemoveSecondLevelReservation(*iterResSndLvl,RESCHEDULE_MAX_AGE_DAYS_SECONDLEVELDOMAIN); }
	syncSecondLevelDomains.clear();
}

void GenericWebUrlFetcherThread::CheckMaxSecondLevelDomain() {
	if(syncSecondLevelDomains.size() >= MAX_SECONDLEVEL_PER_THREAD ) {
		long long minID = -1;
		time_t tmpMin = time(0);
		std::map<long long,time_t>::iterator iterSecondLevel = syncSecondLevelDomains.begin();
		//remove oldest entries first
		for(;iterSecondLevel != syncSecondLevelDomains.end();++iterSecondLevel) {
			if(tmpMin > iterSecondLevel->second) {
				tmpMin = iterSecondLevel->second;
				minID  = iterSecondLevel->first; }
		}
		if(minID != -1)	{
			RemoveSecondLevelReservation(minID,RESCHEDULE_MAX_AGE_DAYS_SECONDLEVELDOMAIN); }
	}

	//check if domains in cache are too old, if so delete them
	if( MAX_AGE_MINUTES_SECONDLEVELDOMAIN > 0 &&
	    syncSecondLevelDomains.size() > 0 )
	{
		time_t tmpMin = time(0);
		std::vector<long long> removeDomains;
		std::map<long long,time_t>::iterator iterSecondLevel = syncSecondLevelDomains.begin();
		for(;iterSecondLevel != syncSecondLevelDomains.end();++iterSecondLevel) {
			if(tmpMin > (iterSecondLevel->second + (60*MAX_AGE_MINUTES_SECONDLEVELDOMAIN) ) ) {
				removeDomains.push_back(iterSecondLevel->first); }
		}

		if(removeDomains.size()>0){
			std::vector<long long>::iterator iterRemoveDomain = removeDomains.begin();
			for(;iterRemoveDomain != removeDomains.end(); ++iterRemoveDomain) {
				RemoveSecondLevelReservation(*iterRemoveDomain,RESCHEDULE_MAX_AGE_DAYS_SECONDLEVELDOMAIN);
			}
		}
	}
}

}
