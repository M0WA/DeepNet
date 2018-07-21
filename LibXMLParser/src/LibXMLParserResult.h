/**
 *
 * @file LibXMLParserResult.h
 * @author Moritz Wagner
 * @date Jun 2, 2013
 *
 */

#pragma once

#include <IHtmlParser.h>

namespace libxmlparser {

class LibXMLParserResult: public htmlparser::IHtmlParserResult {
public:
	LibXMLParserResult(const caching::DatabaseUrl& url);
	virtual ~LibXMLParserResult();
};

}
