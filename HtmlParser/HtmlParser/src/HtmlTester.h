/*
 * HtmlTester.h
 *
 *  Created on: 22.04.2012
 *      Author: Moritz Wagner
 */


#pragma once

#include <StringTools.h>
#include <string>
#include <vector>
#include <map>

#include "URL.h"

namespace database {

	class DatabaseConnection;
}

namespace htmlparser {

class HtmlTesterResult
{
public:
	std::string ToString(database::DatabaseConnection* db) const;
	std::string ToXML(database::DatabaseConnection* db,const URL& baseURL) const;
	std::string ToXML(database::DatabaseConnection* db) const;

public:
	std::vector<std::pair<std::string,std::string> > contentElements;
	std::vector<std::string> hyperLinks;
	std::vector<std::string> images;
	std::vector<std::pair<std::string,std::string> > metaElements;
	std::vector<std::string> warnings;
	std::vector<std::string> errors;
	std::vector<std::string> fatals;

	std::string url;

private:
	std::string ToXML_intern(database::DatabaseConnection* db) const;
};

class HtmlTester {
public:

private:
	HtmlTester();
public:
	virtual ~HtmlTester();

public:
	static bool ParseHtmlFromFile(database::DatabaseConnection* db,const std::string& url, const std::string& htmlFile, HtmlTesterResult& result);
	static bool ParseHtml(database::DatabaseConnection* db,const std::string& url, const std::string& htmlCode, HtmlTesterResult& result);
};

}
