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
}

namespace caching {
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
			tools::Pointer<htmlparser::IHtmlParserResult>& result);

	static void InsertLinks(
			database::DatabaseConnection* db,
			const HtmlParserEntry& entry,
			const std::vector<network::HttpUrl>& hyperlinks,
			std::vector<caching::DatabaseUrl>& dbLinks);

	static void InsertMeta(
			database::DatabaseConnection* db,
			const HtmlParserEntry& entry,
			const std::vector<std::pair<std::string,std::string> >& meta);

	static void UpdateUrlstageInfos(
			database::DatabaseConnection* db,
			const long long internLinks,
			const long long externLinks,
			const long long urlID,
			const long long urlstageID);

private:
	virtual bool ParsePage(
			const HtmlParserEntry& entry,
			tools::Pointer<htmlparser::IHtmlParserResult>& result);

	virtual void OnAfterParsePage(
			const HtmlParserEntry& entry,
			tools::Pointer<htmlparser::IHtmlParserResult>& result,
			const std::vector<std::string> &content,
			const std::vector<caching::DatabaseUrl>& hyperlinks,
			const std::vector<network::HttpUrl>& images)
	{}
};

}
