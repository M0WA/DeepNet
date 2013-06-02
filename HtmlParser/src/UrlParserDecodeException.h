/*
 * UrlParserDecodeException.h
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "HtmlParserException.h"

namespace htmlparser {

class UrlParserDecodeException : public HtmlParserException {
public:
	UrlParserDecodeException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& url);
	virtual ~UrlParserDecodeException();
};

}
