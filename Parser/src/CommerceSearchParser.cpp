/*
 * CommerceSearchParser.cpp
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#include "CommerceSearchParser.h"
#include "CommerceSearchParserParam.h"
#include "CommerceSearchParserThread.h"

namespace parser {

CommerceSearchParser::CommerceSearchParser()
: HtmlParserBase() {
}

CommerceSearchParser::~CommerceSearchParser() {
}

bool CommerceSearchParser::StartParser()
{
	for(unsigned int i = 0; i < parserParam->parserThreadCount; i++)
	{
		HtmlParserParam* param = dynamic_cast<HtmlParserParam*>(new CommerceSearchParserParam());
		param->maxPerSelect = parserParam->maxPerSelect;
		param->waitOnIdle = parserParam->waitOnIdle;
		param->databaseConfig = parserParam->databaseConfig;

		HtmlParserThread* parser = dynamic_cast<HtmlParserThread*>(new CommerceSearchParserThread());
		parser->StartThread(param);
		htmlParserThreads[parser] = param;
	}
	return true;
}

}
