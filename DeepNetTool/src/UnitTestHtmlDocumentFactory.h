/**
 *
 * @file UnitTestHtmlDocumentFactory.h
 * @author Moritz Wagner
 * @date Mar 9, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <string>
#include <sstream>

#include <DocumentFactory.h>

namespace htmlparser {
	class Token;
	class DatabaseUrl;
}

namespace toolbot {

class UnitTestHtmlDocumentFactory : public htmlparser::DocumentFactory {
public:
	UnitTestHtmlDocumentFactory(const htmlparser::DatabaseUrl& url);
	virtual ~UnitTestHtmlDocumentFactory();

public:
	static bool Test(database::DatabaseConnection* db, const std::string& url,const std::string& htmlFile);

private:
	virtual bool OnToken(const htmlparser::Token& token);
	virtual void SwitchMode(const htmlparser::DocumentFactory::InsertionMode& newInsertionMode);

private:
	std::stringstream ssXML;
};

}
