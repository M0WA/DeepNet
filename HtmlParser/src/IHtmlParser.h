#pragma once

namespace htmlparser {

class IHtmlParser {

public:
	typedef enum {
		LIBXML = 0,
		DOM,
		MAX_HTML_PARSER_TYPE,
	} HTML_PARSER_TYPE;

public:
	virtual ~IHtmlParser() {}
};

}
