/*
 * HtmlSAX2Parser.h
 *
 *  Created on: 01.02.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include <libxml/HTMLparser.h>

#include <StringTools.h>
#include "HtmlSAX2Namespace.h"
#include "HtmlSAX2Attribute.h"
#include "HtmlSAX2Element.h"
#include "HtmlSAX2Document.h"

namespace htmlparser {

class HtmlSAX2Parser;
class HtmlSAX2ParserContext
{
public:
	HtmlSAX2ParserContext() : nCurrentElement(-1) {}

	void Reset() { htmlDocument->Reset(); }

	HtmlSAX2Parser* parserInstance;
	HtmlSAX2Document* htmlDocument;

	int nCurrentElement;
};

class HtmlSAX2Parser
{
public:
	HtmlSAX2Parser();
	virtual ~HtmlSAX2Parser();

public:
	static bool EncodeHtmlEntities(const unsigned char* pszIn, const int inLen, std::string& out);

public:
	bool Parse(const std::string& url,std::string html);

public:
	inline void HyperLinks(std::vector<std::string>& hyperlinks) const { hyperlinks = this->hyperlinks; }
	inline void Images(std::vector<std::string>& images) const { images = this->images; }
	inline void Content(std::vector< std::pair<std::string,std::string> >& content) const { content = this->content; }
	inline void Meta(std::vector< std::pair<std::string,std::string> >& meta) const { meta = this->meta; }

	inline void Warnings(std::vector<std::string>& warnings) const { warnings = this->warnings; }
	inline void Errors(std::vector<std::string>& errors) const { errors = this->errors; }
	inline void FatalErrors(std::vector<std::string>& fatals) const { fatals = this->fatals; }

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
	HtmlSAX2Document htmlDocument;
	HtmlSAX2ParserContext parserContext;
	htmlParserCtxtPtr     parserCtxt;

	std::vector<std::string> hyperlinks;
	std::vector<std::string> images;
	std::vector< std::pair<std::string,std::string> > content;
	std::vector< std::pair<std::string,std::string> > meta;

	std::vector<std::string> warnings;
	std::vector<std::string> errors;
	std::vector<std::string> fatals;
};

}
