/**
 * @file GenericWebUrlFetcherThread.cpp
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#include "GenericWebUrlFetcherThread.h"

#include <TimeTools.h>
#include <PerformanceCounter.h>
#include <ContainerTools.h>
#include <Logging.h>

#include <TableDefinition.h>
#include <TableColumn.h>
#include <OrderByClauseDirection.h>

#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <URLInvalidSecondLevelDomainIDException.h>

#include <ctime>

//TODO: put this in config file
#define MAX_SECONDLEVEL_PER_THREAD                30 //max. 30 secondlevel domains scanned in parallel
#define MAX_AGE_MINUTES_SECONDLEVELDOMAIN         10 //10 minutes
#define RESCHEDULE_MAX_AGE_DAYS_SECONDLEVELDOMAIN 1  //1  day

namespace crawler {

GenericWebUrlFetcherThread::GenericWebUrlFetcherThread()
: UrlFetcherThread()
, sldID(-1)
, start(0) {
}

GenericWebUrlFetcherThread::~GenericWebUrlFetcherThread() {
}

long long GenericWebUrlFetcherThread::GetSecondLevelDomainID()
{

#define MAX_SECONDS_PER_SECONDLEVELDOMAIN 600

	if(sldID > 0) {
		// check if we should re-register for another secondlevel domain
		if((time(0) -  start) > MAX_SECONDS_PER_SECONDLEVELDOMAIN) {
			sldID = -1;
			start = time(0);
		}
	}
}

bool GenericWebUrlFetcherThread::GetNextUrlIDs(const long long& maxUrls, std::vector<long long>& urlIDs)
{
	long long sID(GetSecondLevelDomainID());

	if(!SyncClient()->GetURLs(fetcherThreadParam->maxPerSelect, sID, urlIDs)) {
		log::Logging::LogWarn("no urls for secondlevel domain id %lu", sID);
		return false;
	}

	return true;
}

}
