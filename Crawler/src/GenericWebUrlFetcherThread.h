/**
 * @file GenericWebUrlFetcherThread.h
 * @author Moritz Wagner
 * @date 24.07.2012
 */

#pragma once

#include <ctime>
#include <vector>
#include <map>

#include "UrlFetcherThread.h"

namespace crawler {

/**
 * @brief generic web crawler url fetcher thread implementation.
 * @see crawler::UrlFetcherThread
 * @see crawler::DataminingUrlFetcherThread
 */
class GenericWebUrlFetcherThread : public UrlFetcherThread {

public:
	struct GenericWebUrlFetcherThreadParam : public UrlFetcherThread::UrlFetcherThreadParam {

		GenericWebUrlFetcherThreadParam()
		: UrlFetcherThreadParam(){
		}
	};

public:
	GenericWebUrlFetcherThread();
	virtual ~GenericWebUrlFetcherThread();

private:
	virtual bool GetNextSecondLevelDomain();
	virtual bool ReserveNextUrls(std::vector<long long>& urlIDs);
	virtual void OnExit();

private:
	/**
	 * removes reservations for a certain secondleveldomain-id.
	 * @param secondLevelID secondleveldomain-id to remove reservation for.
	 * @param addSchedule reschedule crawling (in days).
	 */
	void RemoveSecondLevelReservation(const long long secondLevelID, const int addSchedule);

private:
	bool urlsFound;
	std::map<long long,time_t> syncSecondLevelDomains;
};

}
