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
#include <IHtmlParser.h>
#include <HtmlParserFactory.h>

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

bool UnitTestSAX2HtmlParser::Test(const htmlparser::DatabaseUrl& baseUrl)
{
	bool success = true;

	tools::Pointer<htmlparser::IHtmlParser> parser;
	htmlparser::HtmlParserFactory::CreateInstance(htmlparser::IHtmlParser::LIBXML,parser);

	std::string html;
	network::HtmlData htmlData;
	std::ostringstream ssOut;
	std::vector<std::string>::const_iterator iter = htmlFilenames.begin();
	for(;iter != htmlFilenames.end();++iter) {

		std::string htmlFileName = unitBaseDir +"/" + *iter;

		html.clear();
		htmlData.Release();

		if(!tools::FileTools::ReadFile(htmlFileName,html)||html.length() == 0) {
			success = false;
			log::Logging::Log(log::Logging::LOGLEVEL_WARN,"cannot read html file: %s, skipping",iter->c_str());
			continue;}

		htmlData.Append(html.c_str(),html.length());
		htmlData.SetContentType("text/html");

		tools::Pointer<htmlparser::IHtmlParserResult> result;
		try
		{
			success &= parser.Get()->Parse(htmlData,result);
		}
		catch(...)
		{
			success = false;
			continue;
		}

		std::string outFileContent;
		result.Get()->DumpXML(outFileContent);

		std::string unitTestOutFile = htmlFileName + ".unittest.xml";
		std::string unitTestTemplateFile = unitBaseDir +"/" + *iter + ".unittest.template.xml";

		tools::FileTools::DeleteFile(unitTestOutFile);
		tools::FileTools::WriteFile(unitTestOutFile, outFileContent, false);

		if(tools::FileTools::FileExists(unitTestTemplateFile)){
			bool tmpSuccess = tools::FileTools::CompareFiles(unitTestOutFile,unitTestTemplateFile);
			if(!tmpSuccess) {
				log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"template and unittest output did not match, please check it for correctness and rerun this unittest: %s",unitTestOutFile.c_str());
				success = false;
			}
		}
		else {
			tools::FileTools::WriteFile(unitTestTemplateFile, outFileContent, false);
			success = false;
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"could not find template html: %s, setting current result as template, please check it for correctness and rerun this unittest",unitTestTemplateFile.c_str());
		}
	}
	return success;
}

}

