/**
 *
 * @file HtmlParserFactory.h
 * @author Moritz Wagner
 * @date Jun 2, 2013
 *
 */

#pragma once

#include "IHtmlParser.h"
#include <Pointer.h>

namespace htmlparser {

class HtmlParserFactory {
private:
	HtmlParserFactory();
public:
	virtual ~HtmlParserFactory();

	static void CreateInstance( const IHtmlParser::HtmlParserType& type, tools::Pointer<IHtmlParser>& client );
};

}
