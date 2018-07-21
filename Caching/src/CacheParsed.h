/**
 * @file CacheParsed.h
 * @author Moritz Wagner
 * @date 08.03.2012
 */

#pragma once

#include "Cache.h"

#include <map>
#include <vector>
#include <string>

#include "DatabaseUrl.h"

namespace caching {

/**
 * @brief cache for parsed html data.
 */
class CacheParsed {
public:
	/**
	 * @struct CacheParsedEntry
	 * @brief container for caching parsed html.
	 */
	struct CacheParsedEntry {
		CacheParsedEntry(
				const long long urlID,
				const DatabaseUrl& url,
				const long long urlStageID,
				const std::vector<std::string>& content,
				const std::vector< std::pair<std::string,std::string> >& meta)
		: urlID(urlID)
		, url(url)
		, urlStageID(urlStageID)
		, content(content)
		, meta(meta)
		{}

		long long urlID;
		DatabaseUrl url;
		long long urlStageID;
		std::vector<std::string> content;
		std::vector< std::pair<std::string,std::string> > meta;
	};

private:
	CacheParsed(size_t limit = 0);
public:
	virtual ~CacheParsed();

public:
	/**
	 * add a new parsed site to cache.
	 * @param entry info for parsed site.
	 */
	static void Add(CacheParsedEntry& entry);

	/**
	 * gets multiple elements from cache.
	 * @param entries gets filled with elements from cache.
	 * @param count maximum number of elements in cache.
	 * @return false if cache is empty, true on success.
	 */
	static bool Get(
			std::map<long long,CacheParsedEntry>& entries,
			const int count);

	/**
	 * set current limit of cache.
	 * @param capacity maximum number of entries in cache.
	 */
	static void SetCapacity(const size_t capacity) { cacheInstance.cacheParsed.SetLimit(capacity); };

	/**
	 * gets current number of entries in cache.
	 * @return current number of entries in cache.
	 */
	static size_t GetSize() { return cacheInstance.cacheParsed.GetSize(); }

	/**
	 * get current match count of cache, clearing internal match counter.
	 * @return number of matches.
	 */
	static size_t GetMatches() { return cacheInstance.cacheParsed.GetMatches(); }

	/**
	 * get current miss count of cache, clearing internal miss counter.
	 * @return number of misses.
	 */
	static size_t GetMisses() { return cacheInstance.cacheParsed.GetMisses(); }

private:
	static CacheParsed cacheInstance;

private:
	Cache<long long, CacheParsedEntry> cacheParsed;
};

}
