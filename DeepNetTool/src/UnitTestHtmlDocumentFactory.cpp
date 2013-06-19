/**
 *
 * @file UnitTestHtmlDocumentFactory.cpp
 * @author Moritz Wagner
 * @date Mar 9, 2013
 *
 */

#include "UnitTestHtmlDocumentFactory.h"

#include "UnitTestHtmlTokeniser.h"

#include <Document.h>
#include <Node.h>

#include <FileTools.h>
#include <CacheDatabaseUrl.h>
#include <HttpUrlParser.h>
#include <Exception.h>

namespace toolbot {

UnitTestHtmlDocumentFactory::UnitTestHtmlDocumentFactory( const network::HttpUrl& url, const std::string& htmlDirectory )
: domparser::DocumentFactory(url)
, toolbot::UnitTest()
, htmlDirectory(htmlDirectory){

}

UnitTestHtmlDocumentFactory::~UnitTestHtmlDocumentFactory() {
}

bool UnitTestHtmlDocumentFactory::Run(){

	std::vector<std::string> files;
	tools::FileTools::ListDirectory(files, htmlDirectory, ".*?\\.html$", true);

	std::vector<std::string>::const_iterator iterFiles = files.begin();
	for(;iterFiles != files.end(); ++iterFiles) {
		std::string htmlContent;
		tools::FileTools::ReadFile(*iterFiles,htmlContent);

		log::Logging::LogTrace("parsing html file: "+*iterFiles);

		UnitTestHtmlTokeniser tokeniserImpl(*this);
		curDoc = new domparser::Document(url, "utf-8", "text/html");
		tokeniser = &tokeniserImpl;
		tokeniserImpl.Parse(htmlContent.c_str(),htmlContent.length());
		delete curDoc;

		tools::FileTools::DeleteFile(*iterFiles + ".tokeniser.xml");
		tools::FileTools::WriteFile(*iterFiles + ".tokeniser.xml", ssXML.str(), false);
	}

	return true;
}

bool UnitTestHtmlDocumentFactory::OnToken(const domparser::Token& token) {

	std::ostringstream ssStream;
	ssStream << tokeniser->GetLineColumnString();

	bool success = DocumentFactory::OnToken(token);

	ssStream << " token received: \"" << (success ? "success" : "tree construction error") << "\" state: \"" << DocumentFactory::InsertionModeToString(insertionMode) << "\" " << token.ToString();

	log::Logging::LogTrace(ssStream.str());

	ssXML << token.ToXML() << std::endl;
	return success;
}

void UnitTestHtmlDocumentFactory::SwitchMode(const domparser::DocumentFactory::InsertionMode& newInsertionMode) {

	std::ostringstream ssStream;
	ssStream << tokeniser->GetLineColumnString();
	ssStream << " switch mode " << DocumentFactory::InsertionModeToString(insertionMode) << " => " << DocumentFactory::InsertionModeToString(newInsertionMode);
	log::Logging::LogTrace(ssStream.str());

	DocumentFactory::SwitchMode(newInsertionMode);
}

}
