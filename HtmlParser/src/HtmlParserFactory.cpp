/**
 *
 * @file HtmlParserFactory.cpp
 * @author Moritz Wagner
 * @date Jun 2, 2013
 *
 */

#include "HtmlParserFactory.h"

#include <HtmlSAX2Parser.h>
//#include <DocumentFactory.h>

namespace htmlparser {

HtmlParserFactory::HtmlParserFactory() {
}

HtmlParserFactory::~HtmlParserFactory() {
}

void HtmlParserFactory::CreateInstance( const IHtmlParser::HTML_PARSER_TYPE& type, tools::Pointer<IHtmlParser>& client ){

	switch(type)
	{
	case IHtmlParser::LIBXML:
		client.Set(new libxmlparser::HtmlSAX2Parser(),true);
		break;

	case IHtmlParser::DOM:
		client.Set((IHtmlParser*)0,true);
		break;

	default:
		client.Set((IHtmlParser*)0,true);
		break;
	}
}

}
