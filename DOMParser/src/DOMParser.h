/**
 *
 * @file src/DOMParser.h
 * @author Moritz Wagner
 * @date 09.06.2013
 *
 */

#pragma once

#include <IHtmlParser.h>

namespace caching {
	class DatabaseUrl;
}

namespace domparser {

class DOMParser: public htmlparser::IHtmlParser {
public:
	DOMParser();
	virtual ~DOMParser();

	virtual bool Parse(const caching::DatabaseUrl& url,const network::HtmlData& html, tools::Pointer<htmlparser::IHtmlParserResult>& result);
};

}
