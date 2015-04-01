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
	UrlFetchParam(const htmlparser::DatabaseUrl& url)
	: url(url){
	}

	long long urlID;
	long long urlStageID;
	long responseCode;

	htmlparser::DatabaseUrl url;
	network::HtmlData html;

};

}

