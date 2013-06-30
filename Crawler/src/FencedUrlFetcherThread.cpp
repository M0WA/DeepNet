/**
 *
 * @file FencedCrawlerFetcherThread.cpp
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#include "FencedUrlFetcherThread.h"

#include <Logging.h>
#include <PerformanceCounter.h>
#include <ContainerTools.h>
#include <TimeTools.h>

#include <DatabaseLayer.h>
#include <WhereCondition.h>

namespace crawler {

FencedUrlFetcherThread::FencedUrlFetcherThread()
: GenericWebUrlFetcherThread()
, isDomainsReserved(false){

	fencedParam = dynamic_cast<const FencedUrlFetcherThreadParam*>(fetcherThreadParam);
	std::vector<long long>::const_iterator i = fencedParam->secondLevelDomains.begin();
	std::vector<long long>::const_iterator end = fencedParam->secondLevelDomains.end();
	for(;i != end; ++i) {
		syncSecondLevelDomains[*i] = time(0); }
}

FencedUrlFetcherThread::~FencedUrlFetcherThread() {
}

bool FencedUrlFetcherThread::LockNextSecondLevelDomain() {

	if(!isDomainsReserved) {
		PERFORMANCE_LOG_START;
		database::TableBaseUpdateParam param;
		param.onlyDirtyColumns = true;
		param.limit = 1;

		database::OrderByColumn entry;
		entry.colDef = database::locksecondleveldomainTableBase::GetDefinition_schedule();
		entry.dir    = database::ASCENDING;
		param.orderCols.push_back(entry);

		database::locksecondleveldomainTableBase::GetWhereColumnsFor_schedule(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::SmallerOrEqual(), database::WhereCondition::InitialComp()),
			tools::TimeTools::NowUTC(),
			param.whereCols);

		std::vector<long long> tmpSndLvl;
		tools::ContainerTools::Map1ToVector(syncSecondLevelDomains,tmpSndLvl);
		database::locksecondleveldomainTableBase::GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
			database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(), database::WhereCondition::And()),
			tmpSndLvl,
			param.whereCols);

		database::locksecondleveldomainTableBase tblLockDomain;
		tblLockDomain.Set_CRAWLERSESSION_ID(crawlerSessionID);
		tblLockDomain.Set_schedule(tools::TimeTools::NowUTCAdd(fetcherThreadParam->minAge));

		PERFORMANCE_LOG_RESTART;
		tblLockDomain.Update(DB().Connection(),param);
		PERFORMANCE_LOG_STOP("locking new second level domain id to crawl");

		isDomainsReserved = true;
	}

	if(syncSecondLevelDomains.size() == 0) {
		log::Logging::LogError("no secondlevel domain ids found for FencedUrlFetcherThread");
		return false; }

	std::vector<long long>::const_iterator i = fencedParam->secondLevelDomains.begin();
	std::vector<long long>::const_iterator end = fencedParam->secondLevelDomains.end();
	for(;i != end; ++i) {
		syncSecondLevelDomains[*i] = time(0); }

	return true;
}

}
