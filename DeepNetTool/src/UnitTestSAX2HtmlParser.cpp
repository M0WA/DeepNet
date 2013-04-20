/**
 *
 * @file UnitTestSAX2HtmlParser.cpp
 * @author Moritz Wagner
 * @date Apr 20, 2013
 *
 */

#include "UnitTestSAX2HtmlParser.h"

#include <sstream>

#include <FileTools.h>
#include <Logging.h>

#include <HtmlData.h>
#include <HtmlSAX2Parser.h>
#include <HtmlSAX2Document.h>
#include <DatabaseUrl.h>
#include <CacheDatabaseUrl.h>

namespace toolbot {

UnitTestSAX2HtmlParser::UnitTestSAX2HtmlParser(database::DatabaseConnection* db, const std::string& unitBaseDir,const std::vector<std::string>& htmlFilenames)
: db(db)
, unitBaseDir(unitBaseDir)
, htmlFilenames(htmlFilenames){
}

UnitTestSAX2HtmlParser::~UnitTestSAX2HtmlParser() {
}

bool UnitTestSAX2HtmlParser::Run() {
	bool success = true;
	try
	{
		htmlparser::DatabaseUrl baseUrl = caching::CacheDatabaseUrl::GetByUrlString(db,"siridia.de");
		success = Test(baseUrl);
	}
	catch(...)
	{
		success = false;
	}
	return success;
}

bool UnitTestSAX2HtmlParser::Test(htmlparser::DatabaseUrl& baseUrl)
{
	bool success = true;
	htmlparser::HtmlSAX2Parser parser;
	std::string html;
	network::HtmlData htmlData;
	htmlparser::HtmlSAX2Document document(baseUrl);
	std::ostringstream ssOut;
	std::vector<std::string>::const_iterator iter = htmlFilenames.begin();
	for(;iter != htmlFilenames.end();++iter) {

		html.clear();
		htmlData.Release();
		document.Reset();

		if(!tools::FileTools::ReadFile(unitBaseDir +"/" + *iter,html)||html.length() == 0) {
			success = false;
			log::Logging::Log(log::Logging::LOGLEVEL_WARN,"cannot read html file: %s, skipping",iter->c_str());
			continue;
		}
		htmlData.Append(iter->c_str(),iter->length());
		htmlData.SetContentType("text/html");

		try
		{
			success &= parser.Parse(htmlData,document);
		}
		catch(...)
		{
			success = false;
			continue;
		}

		std::string outFile;
		document.DumpXML(outFile);
		tools::FileTools::DeleteFile(unitBaseDir +"/" + *iter + ".unittest.xml");
		tools::FileTools::WriteFile(unitBaseDir +"/" + *iter + ".unittest.xml", outFile, false);

		if(tools::FileTools::FileExists(unitBaseDir +"/" + *iter + ".unittest.template.xml")){
			success &= tools::FileTools::CompareFiles(unitBaseDir +"/" + *iter + ".unittest.xml",unitBaseDir +"/" + *iter + ".unittest.template.xml");
		}
	}
}

}

