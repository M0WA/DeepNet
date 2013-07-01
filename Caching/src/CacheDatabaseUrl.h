/**
 * @file CacheDatabaseUrl.h
 * @author Moritz Wagner
 * @date 30.12.2012
 */

#pragma once

#include "Cache.h"

namespace network {
	class HttpUrl;
}

namespace htmlparser {
	class DatabaseUrl;
}

namespace database {
	class DatabaseConnection;
}

namespace tools {
	template <class T> class Pointer;
}

namespace caching {

/**
 * @brief cache for DatabaseUrl.
 * @see DatabaseUrl
 */
class CacheDatabaseUrl {
public:
	/**
	 * construct cache with size limit.
	 * @param limit maximum number of items in cache
	 */
	CacheDatabaseUrl(size_t limit = 0);

	virtual ~CacheDatabaseUrl();

public:
	/**
	 * gets an url by an url-id and loads them from database
	 * if non-existing in cache.
	 * @param db database connection.
	 * @param urlID url-id to search for.
	 * @param urlOut requested url [out]
	 * @return true if successful, false if unsuccessful.
	 */
	static bool GetByUrlID(
			database::DatabaseConnection* db,
			const long long& urlID,
			tools::Pointer<htmlparser::DatabaseUrl>& urlOut);

	/**
	 * gets an url by an url-id and inserts if non-existing.
	 * @param db database connection.
	 * @param IDs list of url-ids to get.
	 * @param urls map gets filled with url-id and url.
	 */
	static void GetByUrlID(
			database::DatabaseConnection* db,
			const std::vector<long long>& IDs,
			std::map<long long,htmlparser::DatabaseUrl>& urls);

	/**
	 * gets a database url by a preparsed http url.
	 * this function may insert new urls into the database.
	 * @param db database connection.
	 * @param urlIn preparsed http url.
	 * @param urlOut requested database url [out]
	 * @return true if successful, false if unsuccessful.
	 */
	static bool GetByUrl(
			database::DatabaseConnection* db,
			const network::HttpUrl& urlIn,
			tools::Pointer<htmlparser::DatabaseUrl>& urlOut);

	/**
	 * gets an url by a string.
	 * this function may insert new urls into the database.
	 * @param db database connection.
	 * @param url url as a string.
	 * @param urlOut requested database url [out]
	 * @return true if successful, false if unsuccessful.
	 */
	static bool GetByUrlString(
			database::DatabaseConnection* db,
			const std::string& url,
			tools::Pointer<htmlparser::DatabaseUrl>& urlOut);

	/**
	 * gets an url by a string and it's relative url (also a string).
	 * this function may insert new urls into the database.
	 * @param db database connection.
	 * @param url url as a string.
	 * @param baseUrl relative url.
	 * @param urlOut requested database url [out]
	 * @return true if successful, false if unsuccessful.
	 */
	static bool GetByUrlString(
			database::DatabaseConnection* db,
			const std::string& url,
			const std::string& baseUrl,
			tools::Pointer<htmlparser::DatabaseUrl>& urlOut);

	/**
	 * gets an url by a string and it's preparsed relative url.
	 * this function may insert new urls into the database.
	 * @param db database connection.
	 * @param url url as a string.
	 * @param baseUrl relative url.
	 * @param urlOut requested database url [out]
	 * @return true if successful, false if unsuccessful.
	 */
	static bool GetByUrlString(
			database::DatabaseConnection* db,
			const std::string& url,
			const network::HttpUrl& baseUrl,
			tools::Pointer<htmlparser::DatabaseUrl>& urlOut);

	/**
	 * gets an url by a string and it's preparsed relative url.
	 * this function may insert new urls into the database.
	 * @param db database connection.
	 * @param url url as a string.
	 * @param baseUrl relative url.
	 * @param urlOut requested database url [out]
	 * @return true if successful, false if unsuccessful.
	 */
	static bool GetByUrlString(
			database::DatabaseConnection* db,
			const std::string& url,
			const htmlparser::DatabaseUrl& baseUrl,
			tools::Pointer<htmlparser::DatabaseUrl>& urlOut);

	/**
	 * finds urls with a certain secondlevel/subdomain-id in the cache and in the database.
	 * @param db database connection.
	 * @param secondlevelID secondlevel domain id to look for.
	 * @param subdomainID subdomain id to look for,can be -1 if no subdomain.
	 * @param limitIn maximum number of urls to return.
	 * @param urls gets filled with urls.
	 */
	static void GetBySecondLevelIDSubdomainID(
			database::DatabaseConnection* db,
			const long long secondlevelID,
			const long long subdomainID,
			const int limitIn,
			std::vector<htmlparser::DatabaseUrl>& urls);

public:
	/**
	 * removes all items from cache.
	 */
	static void Clear(void);

	/**
	 * set current limit of cache.
	 * @param capacity maximum number of entries in cache.
	 */
	static void SetCapacity(const int capacity);

public:
	/**
	 * gets current number of entries in cache.
	 * @return current number of entries in cache.
	 */
	static size_t GetSize();

	/**
	 * get current match count of cache, clearing internal match counter.
	 * @return number of matches.
	 */
	static size_t GetMatches();

	/**
	 * get current miss count of cache, clearing internal miss counter.
	 * @return number of misses.
	 */
	static size_t GetMisses();

private:
	void Insert(database::DatabaseConnection* db, network::HttpUrl& url);
	void Add(database::DatabaseConnection* db, htmlparser::DatabaseUrl& url);

private:
	static CacheDatabaseUrl cacheInstance;

private:
	Cache<long long, htmlparser::DatabaseUrl> cacheIDUrl;
};

}
