/*
 * GenericWebHtmlParser.cpp
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#include "GenericWebHtmlParser.h"
#include "GenericWebHtmlParserThread.h"

namespace parser {

GenericWebHtmlParser::GenericWebHtmlParser(const HtmlParserParam* parserParam)
: HtmlParserBase(parserParam){
}

GenericWebHtmlParser::~GenericWebHtmlParser() {
}

bool GenericWebHtmlParser::StartParser()
{
	for(unsigned int i = 0; i < parserParam->parserThreadCount; i++)
	{
		HtmlParserParam* param = new HtmlParserParam(*parserParam);
		HtmlParserThread* parser = dynamic_cast<HtmlParserThread*>(new GenericWebHtmlParserThread());
		parser->StartThread(param);

		htmlParserThreads[parser] = param;
	}
	return true;
}

}
