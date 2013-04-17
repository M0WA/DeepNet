/*
 * HtmlParserException.cpp
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#include "HtmlParserException.h"

namespace htmlparser {

HtmlParserException::HtmlParserException(
	const std::string& file,
	const int line,
	const std::string& function,
	const std::string& exceptionName,
	const std::string& message)
: Exception(file,line,function,"htmlparser", exceptionName, message) {
}

HtmlParserException::~HtmlParserException() {
}

}
