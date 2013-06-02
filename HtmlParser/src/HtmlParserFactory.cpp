/**
 *
 * @file HtmlParserFactory.cpp
 * @author Moritz Wagner
 * @date 02.06.2013
 *
 */

#include "HtmlParserFactory.h"

#include <HtmlSAX2Parser.h>

namespace htmlparser {

HtmlParserFactory::HtmlParserFactory() {
}

HtmlParserFactory::~HtmlParserFactory() {
}

void HtmlParserFactory::CreateInstance( const HtmlParserType& type, tools::Pointer<IHtmlParser>& client ){

	switch(type)
	{
	case LIBXML:
		client.Set(new libxmlparser::HtmlSAX2Parser(),true);
		break;

	case DOM:
		client.Set((IHtmlParser*)0,true);
		break;

	default:
		client.Set((IHtmlParser*)0,true);
		break;
	}
}

}
