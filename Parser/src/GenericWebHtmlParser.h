/*
 * GenericWebHtmlParser.h
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "HtmlParserBase.h"

namespace parser {

class GenericWebHtmlParser: public parser::HtmlParserBase {
public:
	GenericWebHtmlParser();
	virtual ~GenericWebHtmlParser();

private:
	virtual bool StartParser();
};

}
