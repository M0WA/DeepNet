/*
 * HtmlParserEntry.h
 *
 *  Created on: 05.09.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

#include <DatabaseUrl.h>
#include <HtmlData.h>

namespace parser {

class HtmlParserEntry {
public:
	HtmlParserEntry(long long urlID, const caching::DatabaseUrl& url, const network::HtmlData& html, const long long urlStageID);
	virtual ~HtmlParserEntry();

	long long urlID;
	caching::DatabaseUrl url;
	network::HtmlData html;
	long long urlStageID;
};

}

