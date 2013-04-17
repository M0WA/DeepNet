/*
 * GenericWebHtmlParserThread.h
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <vector>

#include "HtmlParserThread.h"
#include "HtmlParserEntry.h"

namespace network {
	class HttpUrl;
}

namespace htmlparser {
	class Document;
}

namespace parser {

class GenericWebHtmlParserThread: public parser::HtmlParserThread {
public:
	GenericWebHtmlParserThread();
	virtual ~GenericWebHtmlParserThread();

private:
	virtual bool ParsePage(const HtmlParserEntry& entry,const htmlparser::HtmlSAX2Document& document);

private:
	void InsertImages(const HtmlParserEntry& entry, const std::vector<network::HttpUrl>& images,const htmlparser::HtmlSAX2Document& document);
	void InsertLinks(const HtmlParserEntry& entry, const std::vector<network::HttpUrl>& hyperlinks);
	void InsertMeta(const HtmlParserEntry& entry, const std::vector<std::pair<std::string,std::string> >& meta);
};

}
