/**
 * @file CacheHtml.cpp
 * @author Moritz Wagner
 * @date 08.03.2012
 */

#include "CacheHtml.h"

#include "DatabaseUrl.h"
#include <HtmlData.h>

namespace caching {

CacheHtml CacheHtml::cacheInstance;

CacheHtml::CacheHtml(size_t limit)
: cacheHtmlCode(limit, true)
{
}

CacheHtml::~CacheHtml()
{
}

void CacheHtml::Add(const long long& ID, const DatabaseUrl& url, const network::HtmlData& html, const long long urlStageID)
{
	cacheInstance.cacheHtmlCode.AddItem(ID,CacheHtmlEntry(ID,url,html,urlStageID));
}

bool CacheHtml::Get(std::map<long long,CacheHtmlEntry>& entries, const int count)
{
	return cacheInstance.cacheHtmlCode.GetItem(entries,count);
}

}
