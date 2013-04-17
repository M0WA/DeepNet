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

namespace htmlparser {
	class DatabaseUrl;
	class Document;
}

namespace parser {

class GenericWebHtmlParserThread: public parser::HtmlParserThread {
public:
	GenericWebHtmlParserThread();
	virtual ~GenericWebHtmlParserThread();

private:
	virtual bool ParsePage(const HtmlParserEntry& entry,htmlparser::Document* parsedDoc);

private:
	void InsertImages(const HtmlParserEntry& entry, const std::vector<htmlparser::DatabaseUrl>& images);
	void InsertLinks(const HtmlParserEntry& entry, const std::vector<htmlparser::DatabaseUrl>& hyperlinks);
	void InsertMeta(const HtmlParserEntry& entry, const std::vector<std::pair<std::string,std::string> >& meta);
};

}
