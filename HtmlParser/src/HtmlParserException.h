/*
 * HtmlParserException.h
 *
 *  Created on: 21.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <Exception.h>

namespace htmlparser {

class HtmlParserException: public errors::Exception {
public:
	HtmlParserException(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& exceptionName,
			const std::string& message);
	virtual ~HtmlParserException();
};

}
