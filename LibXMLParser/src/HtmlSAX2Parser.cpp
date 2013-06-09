/*
 * HtmlSAX2Parser.cpp
 *
 *  Created on: 01.02.2012
 *      Author: Moritz Wagner
 */

#include "HtmlSAX2Parser.h"

#include <Logging.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <libxml/HTMLtree.h>
#include <libxml/parser.h>

#include <StringTools.h>
#include <HtmlData.h>
#include <HttpUrlParser.h>
#include <HttpUrlParserException.h>
#include <DatabaseUrl.h>

#include "HtmlSAX2Document.h"
#include "LibXMLParserResult.h"

namespace libxmlparser {

volatile bool HtmlSAX2Parser::errorFuncInitialized = false;

void HtmlSAX2ParserContext::Reset()
{
	htmlDocument->Reset();
}

HtmlSAX2Parser::HtmlSAX2Parser()
: parserCtxt(0)
{
	if(!errorFuncInitialized) {
		//prevent libxml from spilling out
		//logging trash on stdout...
		errorFuncInitialized = true;
		initGenericErrorDefaultFunc((xmlGenericErrorFunc*)&HtmlSAX2Parser::genericErrorFunc); }

	memset( &saxHandler, 0, sizeof(saxHandler) );

	saxHandler.initialized    = XML_SAX2_MAGIC;
	saxHandler.startElement   = &HtmlSAX2Parser::startElement;
	saxHandler.endElement     = &HtmlSAX2Parser::endElement;
	//saxHandler.startElementNs = &HtmlSAX2Parser::startElementNs;
	//saxHandler.endElementNs   = &HtmlSAX2Parser::endElementNs;
	saxHandler.warning        = &HtmlSAX2Parser::warning;
	saxHandler.error          = &HtmlSAX2Parser::error;
	saxHandler.fatalError     = &HtmlSAX2Parser::fatalError;
	saxHandler.characters     = &HtmlSAX2Parser::characters;
}

HtmlSAX2Parser::~HtmlSAX2Parser()
{
}

void HtmlSAX2Parser::startElement(void *ctx, const xmlChar *name, const xmlChar **atts)
{
	HtmlSAX2ParserContext* context = (HtmlSAX2ParserContext*)ctx;

	HtmlSAX2Element element;
	element.attribute.localname = name ? (char*)name : "";

	if(atts)
	{
		// The attrs parameter contains the attributes for the start tag.
		// The even indices in the array will be attribute names, the odd
		// indices are the values, and the final index will contain a NULL.
		unsigned int index = 0;
		for ( ;	atts[index] != 0; index += 2 ) {
			HtmlSAX2Attribute attribute;
			attribute.localname = atts[index] ? (char*)atts[index] : "";
			if(atts[index+1])
				attribute.value = std::string( (const char *)atts[index+1] );
			element.attributes.push_back(attribute);
		}
	}

    context->htmlDocument->elements.push_back(element);
    context->nCurrentElement = context->htmlDocument->elements.size() - 1;
}

void HtmlSAX2Parser::endElement(void *ctx, const xmlChar *name)
{
	HtmlSAX2ParserContext* context = (HtmlSAX2ParserContext*)ctx;

	if((int)context->htmlDocument->elements.size() != (context->nCurrentElement+1))
	{
		if(log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"closing wrong tag");
		return; //this is evil => closing wrong tag ....
	}
	HtmlSAX2Element& elementRef = context->htmlDocument->elements.at(context->nCurrentElement);

	if( !name || elementRef.attribute.localname.empty() )
	{
		if(log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"closing tag has no name");
		return; //this is evil => tag has no name....
	}

	if( strcmp((char*)name,elementRef.attribute.localname.c_str()) != 0 )
	{
		if(log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"closing tag " +elementRef.attribute.localname +" mismatches expected tag: " + std::string((const char*)name));
		return; //tag mismatch => this is evil
	}

	std::string curName = name ? (char*)name : "";
	curName = tools::StringTools::ToLowerNP(curName);
	if (
		(curName.compare("script")==0) ||
		(curName.compare("head")==0)   ||
		(curName.compare("html")==0)   ||
		(curName.compare("style")==0)  ||
		(curName.compare("table")==0)  ||
		(curName.compare("tr")==0)  ||
		(curName.compare("ul")==0)
	   )
	{
		//silently ignore content of above tags
	}
	else if(curName.compare("a")==0)
	{
		//href-attribute
		HtmlSAX2Attribute attributeHref;
		if(elementRef.GetAttributeByName("href", attributeHref))
		{
			network::HttpUrl theUrl;
			try
			{
				network::HttpUrlParser::ParseURL(*context->url,attributeHref.value,theUrl);
				context->htmlDocument->result.hyperlinks.push_back(theUrl);
			}
			catch(const network::HttpUrlParserException& ex)
			{
				if(log::Logging::IsLogLevelTrace()){
					log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"error while parsing url %s from document %s",attributeHref.value.c_str(),theUrl.GetFullUrl().c_str());
				}
			}
		}

		//title-attribute
		HtmlSAX2Attribute attributeTitle;
		if(elementRef.GetAttributeByName("title", attributeTitle))
		{
			//handle as content
			std::pair<std::string,std::string> tagContentPair;
			tagContentPair.first = "a";
			tagContentPair.second = elementRef.attribute.value;
			context->htmlDocument->result.content.push_back(tagContentPair);
		}

		//link content
		if (!elementRef.attribute.value.empty())
		{
			//handle as content
			std::pair<std::string,std::string> tagContentPair;
			tagContentPair.first = "a";
			tagContentPair.second = elementRef.attribute.value;
			context->htmlDocument->result.content.push_back(tagContentPair);
		}
	}
	else if (curName.compare("img")==0)
	{
		//src-attribute
		HtmlSAX2Attribute attributeSrc;
		if(elementRef.GetAttributeByName("src", attributeSrc))
		{
			network::HttpUrl theUrl;
			try
			{
				network::HttpUrlParser::ParseURL(*context->url,attributeSrc.value,theUrl);
				context->htmlDocument->result.images.push_back(theUrl);
			}
			catch(const network::HttpUrlParserException& ex)
			{
				if(log::Logging::IsLogLevelTrace()){
					log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"error while parsing image url %s from document %s",attributeSrc.value.c_str(),theUrl.GetFullUrl().c_str());
				}
			}
		}

		//alt-attribute
		HtmlSAX2Attribute attributeAlt;
		if(elementRef.GetAttributeByName("alt", attributeAlt))
		{
			//handle as content
			std::pair<std::string,std::string> tagContentPair;
			tagContentPair.first = "img";
			tagContentPair.second = attributeAlt.value;
			context->htmlDocument->result.content.push_back(tagContentPair);
		}
	}
	//special case: title tag => counts as meta information
	else if(curName.compare("title")==0)
	{
		std::string content = elementRef.attribute.value;
		tools::StringTools::Trim(content);

		if(!content.empty()) {
			std::pair<std::string,std::string> tagContentPair;
			tagContentPair.first  = curName;
			tagContentPair.second = content;
			context->htmlDocument->result.meta.push_back(tagContentPair);
		}
	}
	else if(curName.compare("meta")==0)
	{
		HtmlSAX2Attribute nameAttributeRef;
		HtmlSAX2Attribute contentAttributeRef;
		if(
			(elementRef.GetAttributeByName("name", nameAttributeRef)) &&
			(elementRef.GetAttributeByName("content", contentAttributeRef)) &&
			(
				(nameAttributeRef.value.compare("keywords")==0)    ||
				(nameAttributeRef.value.compare("description")==0) ||
				(nameAttributeRef.value.compare("robots")==0)      ||
				(nameAttributeRef.value.compare("language")==0)    ||
				(nameAttributeRef.value.compare("author")==0)      ||
				(nameAttributeRef.value.compare("copyright")==0)   ||
				(nameAttributeRef.value.compare("page-topic")==0)
			)
		  )
		{
			std::pair<std::string,std::string> tagContentPair;
			tagContentPair.first  = nameAttributeRef.value;
			tagContentPair.second = contentAttributeRef.value;
			context->htmlDocument->result.meta.push_back(tagContentPair);
		}
	}
	else if (
		!elementRef.attribute.value.empty() &&
		(
			(curName.compare("td")==0)    ||
			(curName.compare("h1")==0)    ||
			(curName.compare("h2")==0)    ||
			(curName.compare("h3")==0)    ||
			(curName.compare("h4")==0)    ||
			(curName.compare("h5")==0)    ||
			(curName.compare("h6")==0)    ||
			(curName.compare("b")==0)     ||
			(curName.compare("i")==0)     ||
			(curName.compare("u")==0)     ||
			(curName.compare("li")==0)    ||
			(curName.compare("p")==0)     ||
			(curName.compare("div")==0)   ||
			(curName.compare("span")==0)  ||
			(curName.compare("font")==0)  ||
			(curName.compare("small")==0) ||
			(curName.compare("big")==0)   ||
			(curName.compare("pre")==0)   ||
			(curName.compare("code")==0)  ||
			(curName.compare("blockquote")==0) ||
			(curName.compare("textarea")==0)   ||
		//	(curName.compare("body")==0)  ||
			(curName.compare("center")==0)||
			(curName.compare("select")==0)||
			(curName.compare("strike")==0)||
			(curName.compare("strong")==0)||
			(curName.compare("cite")==0)  ||
			(curName.compare("sub")==0)   ||
			(curName.compare("sup")==0)   ||
			(curName.compare("th")==0)    ||
			(curName.compare("em")==0)    ||
			(curName.compare("label")==0) ||
			(curName.compare("menu")==0)  ||
			(curName.compare("button")==0)||
			(curName.compare("option")==0)||
			(curName.compare("noscript")==0)
		)
	)
	{
		//handle as content
		std::string content = elementRef.attribute.value;
		tools::StringTools::Trim(content);
		if ( !content.empty() )
		{
			std::pair<std::string,std::string> tagContentPair;
			tagContentPair.first = elementRef.attribute.localname;
			tagContentPair.second = content;
			context->htmlDocument->result.content.push_back(tagContentPair);
		}
	}
	else if (!elementRef.attribute.value.empty())
	{
		if(log::Logging::IsLogLevelTrace()){
			std::string content = elementRef.attribute.value;
			tools::StringTools::Trim(content);
			if(!content.empty())
				log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"a <%s> tag has unsaved content: \"%s\"",curName.c_str(),elementRef.attribute.value.c_str());
		}
	}
	else
	{
		//ommit the rest
	}

	context->htmlDocument->elements.erase(context->htmlDocument->elements.end());
    context->nCurrentElement = context->htmlDocument->elements.size() - 1;
}

void HtmlSAX2Parser::characters(void *ctx,
	const xmlChar *ch,
	int len)
{
	if(len<=0||ch ==0)
		return;

	//HtmlSAX2ParserContext* context = (HtmlSAX2ParserContext*)((xmlParserCtxtPtr)ctx)->_private;
	HtmlSAX2ParserContext* context = (HtmlSAX2ParserContext*)ctx;
	if( context->nCurrentElement < 0 || !context->htmlDocument->elements.size())
		return;

	char* pszChunk = new char[len+1];
	memcpy(pszChunk,ch,len);
	pszChunk[len] = 0;

	HtmlSAX2Element& refElement = context->htmlDocument->elements.at(context->nCurrentElement);
	refElement.attribute.value += pszChunk;
	delete [] pszChunk;
}

void HtmlSAX2Parser::error( void * ctx,	const char * msg, ... )
{
	HtmlSAX2ParserContext* context = (HtmlSAX2ParserContext*)ctx;

	std::string errorMsg;
	va_list args;
	va_start(args, msg);
	tools::StringTools::FormatVAString(errorMsg,msg,args);
	va_end(args);

	std::stringstream ssInfo;
	if(context->nCurrentElement != -1){
		HtmlSAX2Element& elementRef = context->htmlDocument->elements.at(context->nCurrentElement);

		ssInfo
			<< std::endl
			<< "element: " << elementRef.attribute.localname;
	}

	if(context->parserInstance->parserCtxt->input) {
		size_t nMaxSize = 20;
		size_t sizeC = context->parserInstance->parserCtxt->input->end - context->parserInstance->parserCtxt->input->cur;
		size_t sizeI = (sizeC > nMaxSize) ? nMaxSize : sizeC;
		char* pszInputExcerpt = new char[sizeI+1];
		pszInputExcerpt[sizeI] = 0;

		for(size_t i = 0; i < sizeI; i++){
			pszInputExcerpt[i] = context->parserInstance->parserCtxt->input->cur[i]; }
		std::string sCurrentPos = std::string(pszInputExcerpt);

		ssInfo
			<< ", line: " << context->parserInstance->parserCtxt->input->line
			<< ", col: " << context->parserInstance->parserCtxt->input->col
			<< std::endl << "\"" << sCurrentPos << "\"" << std::endl;

		delete [] pszInputExcerpt;
	}
	errorMsg = ssInfo.str() + errorMsg;
	context->htmlDocument->result.errors.push_back(errorMsg);
}

void HtmlSAX2Parser::warning( void * ctx, const char * msg, ... )
{
	HtmlSAX2ParserContext* context = (HtmlSAX2ParserContext*)ctx;

	std::string errorMsg;
	va_list args;
	va_start(args, msg);
	tools::StringTools::FormatVAString(errorMsg,msg,args);
	va_end(args);
	context->htmlDocument->result.warnings.push_back(errorMsg);
}

void HtmlSAX2Parser::fatalError( void * ctx, const char * msg, ... )
{
	HtmlSAX2ParserContext* context = (HtmlSAX2ParserContext*)ctx;
	if((int)context->htmlDocument->elements.size() != (context->nCurrentElement+1))
	{
		if(log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"closing wrong tag");
		return; //this is evil => closing wrong tag ....
	}

	std::string errorMsg;
	va_list args;
	va_start(args, msg);
	tools::StringTools::FormatVAString(errorMsg,msg,args);
	va_end(args);
	context->htmlDocument->result.fatals.push_back(errorMsg);
}

void HtmlSAX2Parser::genericErrorFunc(void * ctx,
			 const char * msg,
			 ...)
{
	//HtmlSAX2ParserContext* context = (HtmlSAX2ParserContext*)ctx;

	std::string errorMsg;
	va_list args;
	va_start(args, msg);
	tools::StringTools::FormatVAString(errorMsg,msg,args);
	va_end(args);

	log::Logging::Log(log::Logging::LOGLEVEL_WARN,"libXML generic error: " + errorMsg);
}

bool HtmlSAX2Parser::Parse(const htmlparser::DatabaseUrl& url,const network::HtmlData& html, tools::Pointer<htmlparser::IHtmlParserResult>& result)
{
	if(html.GetCount() == 0)
		return false;

	HtmlSAX2Document htmlDocument(url);

	parserContext.parserInstance = this;
	parserContext.htmlDocument = &htmlDocument;
	parserContext.url = &url;

	if(parserCtxt)
		htmlFreeParserCtxt(parserCtxt);

	parserCtxt = htmlCreatePushParserCtxt(
		&saxHandler,
		&parserContext,
		html.GetBuffer(),
		html.GetBufferSize(),
		url.GetFullUrl().c_str(),
		XML_CHAR_ENCODING_NONE);
	if(!parserCtxt)
		return false;

	parserCtxt->linenumbers = 1;
	parserCtxt->replaceEntities = 1;

	htmlDocPtr htmlDoc = htmlCtxtReadMemory(
		parserCtxt,
		html.GetBuffer(),
		html.GetBufferSize(),
		url.GetFullUrl().c_str(),
		NULL,
		HTML_PARSE_RECOVER  |   //Relaxed parsing
		HTML_PARSE_NOBLANKS |   //remove blank nodes
		HTML_PARSE_COMPACT  );  //compact small text nodes

	//terminate parser
	htmlParseChunk(parserCtxt, html.GetBuffer(), 0, 1);
	htmlDoc = (htmlDocPtr)parserCtxt->myDoc;

	//check if well formed
	htmlDocument.result.wellformed = parserCtxt->wellFormed;

	//free all previously allocated stuff
	htmlFreeParserCtxt(parserCtxt);
	parserCtxt = 0;
	if(htmlDoc){
		xmlFreeDoc(htmlDoc);
		htmlDoc = 0;
	}

	result.Set(dynamic_cast<htmlparser::IHtmlParserResult*>(new LibXMLParserResult(htmlDocument.result)),true);
	return true;
}

}
