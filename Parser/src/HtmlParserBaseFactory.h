/**
 *
 * @file HtmlParserBaseFactory.h
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#pragma once

namespace parser {

	class HtmlParserBase;
	class HtmlParserParam;

class HtmlParserBaseFactory {
private:
	HtmlParserBaseFactory();
public:
	virtual ~HtmlParserBaseFactory();

public:
	static HtmlParserBase* CreateCommerceSearchParser(const HtmlParserParam* parserParam);
	static HtmlParserBase* CreateGenericWebParser(const HtmlParserParam* parserParam);
};

}
