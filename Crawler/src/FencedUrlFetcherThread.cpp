/**
 *
 * @file FencedUrlFetcherThread.cpp
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#include "FencedUrlFetcherThread.h"

#include <Logging.h>
#include <PerformanceCounter.h>
#include <ContainerTools.h>
#include <TimeTools.h>

#include <WhereCondition.h>

namespace crawler {

FencedUrlFetcherThread::FencedUrlFetcherThread()
: GenericWebUrlFetcherThread()
, fencedParam(0){
}

FencedUrlFetcherThread::~FencedUrlFetcherThread() {
}

long long FencedUrlFetcherThread::GetSecondLevelDomainID()
{
	if(!fencedParam) {
		fencedParam = dynamic_cast<const FencedUrlFetcherThreadParam*>(fetcherThreadParam);
		iDom = fencedParam->secondLevelDomains.begin();
	}
	else if(iDom == fencedParam->secondLevelDomains.end()) {
		iDom = fencedParam->secondLevelDomains.begin();
	}
	else {
		++iDom;
	}
	return *iDom;
}

}
