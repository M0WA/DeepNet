/*
 * HtmlSAX2Parser.h
 *
 *  Created on: 01.02.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <vector>
#include <map>

#include <libxml/HTMLparser.h>

namespace network {
	class HtmlData;
}

namespace htmlparser {

class DatabaseUrl;
class HtmlSAX2Document;
class HtmlSAX2Parser;

class HtmlSAX2ParserContext
{
public:
	HtmlSAX2ParserContext()
	: parserInstance(0)
	, htmlDocument(0)
	, url(0)
	, nCurrentElement(-1)
	{}

	void Reset();

	HtmlSAX2Parser* parserInstance;
	HtmlSAX2Document* htmlDocument;
	const DatabaseUrl* url;

	int nCurrentElement;
};

class HtmlSAX2Parser
{
public:
	HtmlSAX2Parser();
	virtual ~HtmlSAX2Parser();

public:
	bool Parse(const network::HtmlData& html, htmlparser::HtmlSAX2Document& htmlDocumentOut);

private:
	static void startElement(void *ctx, const xmlChar *name, const xmlChar **atts);
	static void endElement(void *ctx, const xmlChar *name);

	static void warning( void * ctx, const char * msg, ... );
	static void error( void * ctx, const char * msg, ... );
	static void fatalError( void * ctx, const char * msg, ... );
	static void genericErrorFunc(void * ctx, const char * msg, ...);
	static void characters(void *ctx, const xmlChar *ch, int len);

private:
	volatile static bool errorFuncInitialized;

private:
	htmlSAXHandler saxHandler;
	HtmlSAX2ParserContext parserContext;
	htmlParserCtxtPtr     parserCtxt;
};

}
