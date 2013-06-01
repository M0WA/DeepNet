/**
 *
 * @file UnitTestHtmlDocumentFactory.cpp
 * @author Moritz Wagner
 * @date Mar 9, 2013
 *
 * TODO: description for this file
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

UnitTestHtmlDocumentFactory::UnitTestHtmlDocumentFactory( const network::HttpUrl& url, const std::string& htmlFile )
: domparser::DocumentFactory(url)
, toolbot::UnitTest()
, htmlFile(htmlFile){

}

UnitTestHtmlDocumentFactory::~UnitTestHtmlDocumentFactory() {
}

bool UnitTestHtmlDocumentFactory::Run(){

	std::string htmlContent;
	tools::FileTools::ReadFile(htmlFile,htmlContent);

	/*
	try {
		network::HttpUrlParser::ParseURL(url);
	}
	catch(tools::Exception& e) {
		return false;
	}
	*/

	UnitTestHtmlTokeniser tokeniserImpl(*this);
	curDoc = new domparser::Document(url, "utf-8", "text/html");
	tokeniser = &tokeniserImpl;
	tokeniserImpl.Parse(htmlContent.c_str(),htmlContent.length());
	delete curDoc;

	tools::FileTools::DeleteFile(htmlFile + ".tokeniser.xml");
	tools::FileTools::WriteFile(htmlFile + ".tokeniser.xml", ssXML.str(), false);
	return false;
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
