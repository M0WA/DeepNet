/**
 * @file UrlFetcherThread.h
 * @author Moritz Wagner
 * @date 06.03.2012
 */

#pragma once

#include <map>
#include <vector>
#include <string>

#include <Thread.h>
#include <DatabaseLayer.h>
#include <HttpClientFactory.h>

#include "UrlFetchParam.h"
#include "CrawlerParam.h"

namespace htmlparser {
	class DatabaseUrl;
}

namespace network {
	class HtmlData;
}

namespace crawler {

	class UrlFetcherThreadParam;

/**
 * @brief generic url fetcher thread implementation.
 */
class UrlFetcherThread: public threading::Thread {

public:
	UrlFetcherThread();
	virtual ~UrlFetcherThread();

public:
	/**
	 * gets old crawler session id after this thread ended
	 */
	long long GetOldCrawlerSessionID() const;

private:
	static void* UrlFetcherThreadFunction(Thread::THREAD_PARAM* threadParam);

protected:
	/**
	 * gets the database.
	 * @return database helper.
	 */
	database::DatabaseHelper& DB() { return databaseHelper; }

protected:
	//called by UrlFetcherThreadFunction()
	/**
	 * fetches urls from cache/database and reserves them for crawling.
	 * @param urls gets filled with url-ids and urls.
	 * @return false on error, true on success.
	 */
	bool FetchUrls(std::map<long long,htmlparser::DatabaseUrl>& urls);

	/**
	 * fetches html from given urls.
	 * @param urls map of url-ids and urls to be crawler.
	 * @param fetchParameters gets filled with info from crawled pages
	 * @return false on error, true on success.
	 */
	bool FetchHtmlCode(const std::map<long long,htmlparser::DatabaseUrl>& urls, std::vector<UrlFetchParam>& fetchParameters);

	/**
	 * saves crawled urls and results to database.
	 * @param fetchParameters
	 * @return false on error, true on success.
	 */
	bool CommitPages(const std::vector<UrlFetchParam>& fetchParameters);

	/**
	 * called when no urls are available.
	 */
	void OnIdle();

	//(pure-)virtual functions
	/**
	 * called when secondleveldomain id should be changed if possible.
	 * @return false on error, true on success.
	 */
	virtual bool GetNextSecondLevelDomain()=0;

	/**
	 * called when more url-ids are needed and should be reserved
	 * @param urlIDs gets filled with reserved url ids.
	 * @return false on error, true on success.
	 */
	virtual bool ReserveNextUrls(std::vector<long long>& urlIDs)=0;

	/**
	 * called when fetcher thread is going to exit.
	 */
	virtual void OnExit() {};

	/**
	 * called when a new crawlersession-id is needed.
	 * result is written to UrlFetcherThread::crawlerSessionID.
	 * @return false on error, true on success.
	 */
	bool GetNextCrawlerSessionID();

	/**
	 * called when url-ids are needed from database.
	 * @param urlIDs url-ids to look for.
	 * @param urls gets filled with url-ids and urls.
	 * @return false on error, true on success.
	 */
	bool GetUrlsFromDatabase(const std::vector<long long>& urlIDs, std::map<long long,htmlparser::DatabaseUrl>& urls);

	/**
	 * removes active crawlersession-id from database.
	 */
	void RemoveCrawlerSessionID();

	/**
	 * removes pending reservations for url-ids from database.
	 */
	void RemoveCrawlerReservation();

	/**
	 * helper function for crawler:.UrlFetcherThread::FetchHtmlCode.
	 * @param urlID url-id
	 * @param url parsed url.
	 * @param htmlCode gets filled with html code.
	 * @param httpCode returned http status code.
	 * @param urlStageID urlstage-id.
	 * @return false on error, true on success.
	 */
	bool GetHtmlCodeFromUrl(const long long urlID, const htmlparser::DatabaseUrl& url, network::HtmlData& htmlCode, long& httpCode, long long& urlStageID);

protected:
	/**
	 * current crawlersession-id.
	 */
	long long crawlerSessionID;

	/**
	 * parameters attached to this url fetcher thread.
	 */
	UrlFetcherThreadParam* fetcherThreadParam;

private:
	database::DatabaseHelper databaseHelper;
	long long oldCrawlerSessionID;
};

}
