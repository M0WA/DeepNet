/*
 * GenericWebHtmlParserThread.h
 *
 *  Created on: 26.07.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <vector>

#include "HtmlParserThread.h"

namespace database {
	class DatabaseConnection;
}

namespace network {
	class HttpUrl;
}

namespace htmlparser {
	class Document;
	class DatabaseUrl;
}

namespace parser {

class HtmlParserEntry;

class GenericWebHtmlParserThread: public parser::HtmlParserThread {
public:
	GenericWebHtmlParserThread();
	virtual ~GenericWebHtmlParserThread();

private:
	static void InsertImages(
			database::DatabaseConnection* db,
			const HtmlParserEntry& entry,
			const std::vector<network::HttpUrl>& images,
			const htmlparser::HtmlSAX2Document& document);

	static void InsertLinks(
			database::DatabaseConnection* db,
			const HtmlParserEntry& entry,
			const std::vector<network::HttpUrl>& hyperlinks,
			std::vector<htmlparser::DatabaseUrl>& dbLinks);

	static void InsertMeta(
			database::DatabaseConnection* db,
			const HtmlParserEntry& entry,
			const std::vector<std::pair<std::string,std::string> >& meta);

private:
	virtual bool ParsePage(
			const HtmlParserEntry& entry,
			const htmlparser::HtmlSAX2Document& document);

	virtual void OnAfterParsePage(
			const HtmlParserEntry& entry,
			const htmlparser::HtmlSAX2Document& document,
			const std::vector<std::string> &content,
			const std::vector<htmlparser::DatabaseUrl>& hyperlinks,
			const std::vector<network::HttpUrl>& images)
	{}

};

}
