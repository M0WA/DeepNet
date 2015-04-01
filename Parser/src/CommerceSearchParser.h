/*
 * CommerceSearchParser.h
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "HtmlParserBase.h"

namespace parser {

class HtmlParserBaseFactory;
class HtmlParserParam;

class CommerceSearchParser : public parser::HtmlParserBase {

	friend class HtmlParserBaseFactory;

private:
	CommerceSearchParser(const HtmlParserParam* parserParam);
public:
	virtual ~CommerceSearchParser();

private:
	virtual bool StartParser();
};

}
