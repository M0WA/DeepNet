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

#include <DatabaseUrl.h>
#include <Document.h>
#include <Node.h>

#include <FileTools.h>
#include <CacheDatabaseUrl.h>


namespace toolbot {

UnitTestHtmlDocumentFactory::UnitTestHtmlDocumentFactory(const htmlparser::DatabaseUrl& url)
: htmlparser::DocumentFactory(url) {
}

UnitTestHtmlDocumentFactory::~UnitTestHtmlDocumentFactory() {
}

bool UnitTestHtmlDocumentFactory::Test(database::DatabaseConnection* db, const std::string& url,const std::string& htmlFile){

	std::string htmlContent;
	tools::FileTools::ReadFile(htmlFile,htmlContent);

	htmlparser::DatabaseUrl dbUrl = caching::CacheDatabaseUrl::GetByUrlString(db, url);
	UnitTestHtmlDocumentFactory instance(dbUrl);
	UnitTestHtmlTokeniser tokeniserImpl(instance);
	instance.curDoc = new htmlparser::Document(dbUrl, "utf-8", "text/html");
	instance.tokeniser = &tokeniserImpl;
	tokeniserImpl.Parse(htmlContent.c_str(),htmlContent.length());
	delete instance.curDoc;

	tools::FileTools::DeleteFile(htmlFile + ".tokeniser.xml");
	tools::FileTools::WriteFile(htmlFile + ".tokeniser.xml", instance.ssXML.str(), false);
	return false;
}

bool UnitTestHtmlDocumentFactory::OnToken(const htmlparser::Token& token) {

	std::ostringstream ssStream;
	ssStream << tokeniser->GetLineColumnString();

	bool success = DocumentFactory::OnToken(token);

	ssStream << " token received: \"" << (success ? "success" : "tree construction error") << "\" state: \"" << DocumentFactory::InsertionModeToString(insertionMode) << "\" " << token.ToString();

	log::Logging::LogTrace(ssStream.str());

	ssXML << token.ToXML() << std::endl;
	return success;
}

void UnitTestHtmlDocumentFactory::SwitchMode(const htmlparser::DocumentFactory::InsertionMode& newInsertionMode) {

	std::ostringstream ssStream;
	ssStream << tokeniser->GetLineColumnString();
	ssStream << " switch mode " << DocumentFactory::InsertionModeToString(insertionMode) << " => " << DocumentFactory::InsertionModeToString(newInsertionMode);
	log::Logging::LogTrace(ssStream.str());

	DocumentFactory::SwitchMode(newInsertionMode);
}

}
