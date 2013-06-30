/*
 * GenericWebHtmlParser.h
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "HtmlParserBase.h"

namespace parser {

class HtmlParserBaseFactory;
class HtmlParserParam;

class GenericWebHtmlParser: public parser::HtmlParserBase {

	friend class HtmlParserBaseFactory;

private:
	GenericWebHtmlParser(const HtmlParserParam* parserParam);
public:
	virtual ~GenericWebHtmlParser();

private:
	virtual bool StartParser();
};

}
