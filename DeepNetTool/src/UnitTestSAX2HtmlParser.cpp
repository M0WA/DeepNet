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
#include <Pointer.h>

#include <HtmlData.h>
#include <IHtmlParser.h>
#include <HtmlParserFactory.h>

#include <DatabaseUrl.h>
#include <CacheDatabaseUrl.h>

namespace toolbot {

UnitTestSAX2HtmlParser::UnitTestSAX2HtmlParser(database::DatabaseConnection* db, const std::string& unitBaseDir)
: db(db)
, unitBaseDir(unitBaseDir){
	tools::FileTools::ListDirectory(contentFiles, unitBaseDir, ".*?\\.html$", true);
}

UnitTestSAX2HtmlParser::~UnitTestSAX2HtmlParser() {
}

bool UnitTestSAX2HtmlParser::Run() {
	bool success = true;
	try
	{
		tools::Pointer<htmlparser::DatabaseUrl> baseUrl;
		caching::CacheDatabaseUrl::GetByUrlString(db,"siridia.de",baseUrl);
		success = Test(*baseUrl.Get());
	}
	catch(...)
	{
		success = false;
	}
	return success;
}

bool UnitTestSAX2HtmlParser::Test(const htmlparser::DatabaseUrl& baseUrl)
{
	//remove all broken files
	std::vector<std::string> brokenFiles;
	tools::FileTools::ListDirectory(brokenFiles, unitBaseDir, ".*?\\.broken$", true);
	if(brokenFiles.size() > 0) {
		log::Logging::LogInfo("cleaning up old *.broken files before beginning unit test");

		std::vector<std::string>::const_iterator iBroken = brokenFiles.begin();
		for(;iBroken != brokenFiles.end();++iBroken) {
			tools::FileTools::DeleteFile(unitBaseDir+ "/"+*iBroken); }
	}

	bool success = true;

	tools::Pointer<htmlparser::IHtmlParser> parser;
	htmlparser::HtmlParserFactory::CreateInstance(htmlparser::HtmlParserFactory::LIBXML,parser);

	std::string html;
	network::HtmlData htmlData;
	std::ostringstream ssOut;
	std::vector<std::string>::const_iterator iter = contentFiles.begin();
	for(;iter != contentFiles.end();++iter) {

		std::string htmlFileName(unitBaseDir + "/" + *iter);
		if(htmlFileName.at(unitBaseDir.length() - 1) == '/' ) {
			htmlFileName = unitBaseDir + *iter; }

		html.clear();
		htmlData.Release();

		if(!tools::FileTools::ReadFile(htmlFileName,html)||html.length() == 0) {
			success = false;
			log::Logging::LogWarn("cannot read html file: %s, skipping",iter->c_str());
			continue;}

		htmlData.Append(html.c_str(),html.length());
		htmlData.SetContentType("text/html");

		tools::Pointer<htmlparser::IHtmlParserResult> result;
		try
		{
			success &= parser.Get()->Parse(baseUrl,htmlData,result);
		}
		catch(...)
		{
			success = false;
			continue;
		}

		std::string outFileContent;
		result.Get()->DumpXML(outFileContent);

		std::string tmplFileName = htmlFileName + ".tmpl.xml";
		if(!tools::FileTools::FileExists(tmplFileName)){
			tools::FileTools::WriteFile(tmplFileName, outFileContent, false);
			log::Logging::LogError("could not find template html, setting current result as template, please check it for correctness and rerun this unittest: " + tmplFileName);
		}

		std::string tmpFile = htmlFileName + ".temp";
		tools::FileTools::DeleteFile(tmpFile);
		tools::FileTools::WriteFile(tmpFile, outFileContent, false);
		bool isEqualToTemplate = tools::FileTools::CompareFiles(tmpFile,tmplFileName);
		tools::FileTools::DeleteFile(tmpFile);

		if(!isEqualToTemplate) {
			log::Logging::LogError("template and unittest output did not match, please check it for correctness and rerun this unittest: " + htmlFileName + ".broken");
			tools::FileTools::WriteFile(htmlFileName + ".broken",outFileContent,false);
			continue; }
	}
	return success;
}

}

