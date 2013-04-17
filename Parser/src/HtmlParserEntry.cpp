/*
 * HtmlParserEntry.cpp
 *
 *  Created on: 05.09.2012
 *      Author: Moritz Wagner
 */

#include "HtmlParserEntry.h"

namespace parser {

HtmlParserEntry::HtmlParserEntry(long long urlID, const htmlparser::DatabaseUrl& url, const network::HtmlData& html, const long long urlStageID)
: urlID(urlID)
, url(url)
, html(html)
, urlStageID(urlStageID){
}

HtmlParserEntry::~HtmlParserEntry() {
}

}
