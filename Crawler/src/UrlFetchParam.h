/**
 * @file UrlFetchParam.h
 * @author Moritz Wagner
 * @date 23.11.2012
 */

#pragma once

#include <DatabaseUrl.h>
#include <HtmlData.h>

namespace crawler {

/**
 * @struct UrlFetchParam
 * @brief used internally.
 * used internally only.
 */
struct UrlFetchParam
{
	UrlFetchParam(const caching::DatabaseUrl& url)
	: urlID(-1)
	, urlStageID(-1)
	, responseCode(-1)
	, url(url){
	}

	long long urlID;
	long long urlStageID;
	long responseCode;

	caching::DatabaseUrl url;
	network::HtmlData html;

};

}

