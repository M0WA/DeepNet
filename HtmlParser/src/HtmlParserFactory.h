/**
 *
 * @file HtmlParserFactory.h
 * @author Moritz Wagner
 * @date Jun 2, 2013
 *
 */

#pragma once

#include "IHtmlParser.h"
#include <Pointer.h>

namespace htmlparser {

/**
 * @brief factory class for html parsers.
 */
class HtmlParserFactory {

public:
	/**
	 * @enum HtmlParserType
	 * @brief type of html parser
	 */
	typedef enum {
		/**
		* using libXML based html parser
		*/
		LIBXML = 0,

		/**
		* using own html5 parser implementation
		*/
		DOM,

		/**
		* do not use this
		*/
		MAX_HTML_PARSER_TYPE,
	} HtmlParserType;

private:
	HtmlParserFactory();
public:
	virtual ~HtmlParserFactory();

	/**
	 * creates a html parser based on the given type
	 * @param type type of html parser
	 * @param client created client instance
	 */
	static void CreateInstance( const HtmlParserType& type, tools::Pointer<IHtmlParser>& client );
};

}
