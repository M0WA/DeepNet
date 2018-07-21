/**
 * @file CacheHtmlEntry.h
 * @author Moritz Wagner
 * @date 23.11.2012
 */

#pragma once

#include "DatabaseUrl.h"
#include <HtmlData.h>

namespace caching {

/**
 * @struct CacheHtmlEntry
 * @brief container for caching html code.
 */
struct CacheHtmlEntry
{
	CacheHtmlEntry(const long long& ID, const DatabaseUrl& url, const network::HtmlData& html, const long long urlStageID)
	: ID(ID)
	, url(url)
	, html(html)
	, urlStageID(urlStageID)
	{}

	/**
	 * url-id.
	 */
	long long ID;

	/**
	 * url.
	 */
	DatabaseUrl url;

	/**
	 * html code.
	 */
	network::HtmlData html;

	/**
	 * urlstage-id.
	 */
	long long urlStageID;

};

}

