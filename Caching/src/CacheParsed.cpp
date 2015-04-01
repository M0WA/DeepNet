/**
 * @file CacheParsed.cpp
 * @author Moritz Wagner
 * @date 08.03.2012
 */

#include "CacheParsed.h"

namespace caching {

CacheParsed CacheParsed::cacheInstance;

CacheParsed::CacheParsed(size_t limit)
: cacheParsed(limit, true)
{
}

CacheParsed::~CacheParsed()
{
}

void CacheParsed::Add(CacheParsedEntry& entry)
{
	cacheInstance.cacheParsed.AddItem(entry.urlID,entry);
}

bool CacheParsed::Get(std::map<long long,CacheParsedEntry>& entries, const int count)
{
	return cacheInstance.cacheParsed.GetItem(entries,count);
}

}
