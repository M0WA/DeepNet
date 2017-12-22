/**
 * @file CacheHtml.h
 * @author Moritz Wagner
 * @date 08.03.2012
 */

#pragma once

#include "Cache.h"

#include <map>
#include <vector>
#include <string>

#include "CacheHtmlEntry.h"

namespace network {
	class HtmlData;
}

namespace caching {

class DatabaseUrl;

/**
 * @brief cache for network::HtmlData and corresponding data.
 */
class CacheHtml
{
private:
	CacheHtml(size_t limit = 0);

public:
	virtual ~CacheHtml();

	/**
	 * add a new element to cache.
	 * @param ID url-id.
	 * @param url parsed url.
	 * @param html html code.
	 * @param urlStageID urlstage-id.
	 */
	static void Add(
			const long long& ID,
			const DatabaseUrl& url,
			const network::HtmlData& html,
			const long long urlStageID);

	/**
	 * get elements by count.
	 * @param entries gets filled with elements.
	 * @param count maximum number of elements to get.
	 * @return false if cache is empty, true on success.
	 */
	static bool Get(
			std::map<long long,CacheHtmlEntry>& entries,
			const int count);

public:
	/**
	 * set current limit of cache.
	 * @param capacity maximum number of entries in cache.
	 */
	static void SetCapacity(const size_t capacity) { cacheInstance.cacheHtmlCode.SetLimit(capacity); };

	/**
	 * gets current number of entries in cache.
	 * @return current number of entries in cache.
	 */
	static size_t GetSize() { return cacheInstance.cacheHtmlCode.GetSize(); }

	/**
	 * get current match count of cache, clearing internal match counter.
	 * @return number of matches.
	 */
	static size_t GetMatches() { return cacheInstance.cacheHtmlCode.GetMatches(); }

	/**
	 * get current miss count of cache, clearing internal miss counter.
	 * @return number of misses.
	 */
	static size_t GetMisses() { return cacheInstance.cacheHtmlCode.GetMisses(); }

private:
	static CacheHtml cacheInstance;

private:
	Cache<long long, CacheHtmlEntry> cacheHtmlCode;
};

}
