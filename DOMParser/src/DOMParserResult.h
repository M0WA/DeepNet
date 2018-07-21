/**
 *
 * @file src/DOMParserResult.h
 * @author Moritz Wagner
 * @date 09.07.2013
 *
 */

#pragma once

#include <IHtmlParser.h>

namespace caching {
	class DatabaseUrl;
}

namespace domparser {

class DOMParserResult: public htmlparser::IHtmlParserResult {
public:
	DOMParserResult(const caching::DatabaseUrl& url);
	virtual ~DOMParserResult();
};

}
