/*
 * CommerceSearchParser.h
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "HtmlParserBase.h"

namespace parser {

class CommerceSearchParser : public parser::HtmlParserBase {
public:
	CommerceSearchParser();
	virtual ~CommerceSearchParser();

private:
	virtual bool StartParser();
};

}
