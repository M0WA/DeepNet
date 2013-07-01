/**
 * @file GenericWebUrlFetcherThread.h
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#pragma once

#include <ctime>
#include <vector>
#include <map>

#include <DatabaseLayer.h>

#include "UrlFetcherThreadParam.h"
#include "UrlFetcherThread.h"

namespace crawler {

	class CrawlerParam;

/**
 * @brief generic web crawler url fetcher thread implementation.
 * @see crawler::UrlFetcherThread
 * @see crawler::DataminingUrlFetcherThread
 */
class GenericWebUrlFetcherThread : public UrlFetcherThread {

public:
	GenericWebUrlFetcherThread();
	virtual ~GenericWebUrlFetcherThread();

private:
	virtual bool GetNextSecondLevelDomain();
	virtual bool ReserveNextUrls(std::vector<long long>& urlIDs);
	virtual void OnExit();

private:
	/**
	 * locks current secondlevel domains with this crawler session id.
	 * @return true if successful, false if not successful
	 */
	virtual bool LockNextSecondLevelDomain();

	/**
	 * checks and removes timed out secondlevel domains from cache
	 * @return true if successful, false if not successful
	 */
	virtual bool CheckSecondLevelDomainTimeout(database::SelectResultContainer<database::locksecondleveldomainTableBase>& tblLockDomains);

	/**
	 * checks for upper barrier in active secondlevel domains and deletes oldest if neccessary
	 */
	virtual void CheckMaxSecondLevelDomain();

private:
	/**
	 * removes reservations for a certain secondleveldomain-id.
	 * @param secondLevelID secondleveldomain-id to remove reservation for.
	 * @param addSchedule reschedule crawling (in days).
	 */
	void RemoveSecondLevelReservation(const long long secondLevelID, const int addSchedule);

protected:
	std::map<long long,time_t> syncSecondLevelDomains;

private:
	bool urlsFound;
};

}
