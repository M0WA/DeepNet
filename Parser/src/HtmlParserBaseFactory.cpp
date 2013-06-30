/**
 *
 * @file HtmlParserBaseFactory.cpp
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#include "HtmlParserBaseFactory.h"

#include "CommerceSearchParser.h"
#include "GenericWebHtmlParser.h"

namespace parser {

HtmlParserBaseFactory::HtmlParserBaseFactory() {
}

HtmlParserBaseFactory::~HtmlParserBaseFactory() {
}

HtmlParserBase* HtmlParserBaseFactory::CreateCommerceSearchParser(const HtmlParserParam* parserParam) {
	return new CommerceSearchParser(parserParam);
}

HtmlParserBase* HtmlParserBaseFactory::CreateGenericWebParser(const HtmlParserParam* parserParam) {
	return new GenericWebHtmlParser(parserParam);
}

}
