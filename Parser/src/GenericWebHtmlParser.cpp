/*
 * GenericWebHtmlParser.cpp
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#include "GenericWebHtmlParser.h"
#include "GenericWebHtmlParserParam.h"
#include "GenericWebHtmlParserThread.h"

namespace parser {

GenericWebHtmlParser::GenericWebHtmlParser() {
}

GenericWebHtmlParser::~GenericWebHtmlParser() {
}

bool GenericWebHtmlParser::StartParser()
{
	for(unsigned int i = 0; i < parserParam->parserThreadCount; i++)
	{
		HtmlParserParam* param = dynamic_cast<HtmlParserParam*>(new GenericWebHtmlParserParam());
		param->maxPerSelect = parserParam->maxPerSelect;
		param->waitOnIdle = parserParam->waitOnIdle;
		param->databaseConfig = parserParam->databaseConfig;

		HtmlParserThread* parser = dynamic_cast<HtmlParserThread*>(new GenericWebHtmlParserThread());
		parser->StartThread(param);

		htmlParserThreads[parser] = param;
	}
	return true;
}

}
