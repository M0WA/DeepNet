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
#include <SyncClient.h>
#include <Pointer.h>

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
 * @brief generic url fetcher thread implementation
 * @see crawler::GenericWebUrlFetcherThread
 * @see crawler::FencedUrlFetcherThread
 */
class UrlFetcherThread: public threading::Thread {

protected:
	/**
	 * do not use directly, instead inherit from this class
	 */
	UrlFetcherThread();

public:
	virtual ~UrlFetcherThread();

private:
	static void* UrlFetcherThreadFunction(Thread::THREAD_PARAM* threadParam);

protected:
	/**
	 * called when more url-ids are needed and should be reserved
	 * @param maxUrls max number of urls reserved for crawling
	 * @param urlIDs gets filled with reserved url ids
	 * @return false on error, true on success.
	 */
	virtual bool GetNextUrlIDs(const long long& maxUrls,std::vector<long long>& urlIDs)=0;

	/**
	 * called when fetcher thread is going to exit.
	 */
	virtual void OnExit();

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

	/**
	 * called when url-ids are needed from database.
	 * @param urlIDs url-ids to look for.
	 * @param urls gets filled with url-ids and urls.
	 * @return false on error, true on success.
	 */
	bool GetUrlsFromDatabase(const std::vector<long long>& urlIDs, std::map<long long,htmlparser::DatabaseUrl>& urls);

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
	 * gets instance of syncing::SyncClient for this url fetcher thread
	 * @return instance of syncing::SyncClient
	 */
	syncing::SyncClient* SyncClient() { return syncCliPtr.Get(); }

protected:
	/**
	 * parameters attached to this url fetcher thread.
	 */
	UrlFetcherThreadParam* fetcherThreadParam;


private:
	tools::Pointer<syncing::SyncClient> syncCliPtr;
	database::DatabaseHelper databaseHelper;
};

}
