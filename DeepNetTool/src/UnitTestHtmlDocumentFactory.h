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
	class DatabaseUrl;
}

namespace domparser {
	class Token;
}

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

class UnitTestHtmlDocumentFactory : public domparser::DocumentFactory {
public:
	UnitTestHtmlDocumentFactory(const htmlparser::DatabaseUrl& url);
	virtual ~UnitTestHtmlDocumentFactory();

public:
	static bool Test(database::DatabaseConnection* db, const std::string& url,const std::string& htmlFile);

private:
	virtual bool OnToken(const domparser::Token& token);
	virtual void SwitchMode(const domparser::DocumentFactory::InsertionMode& newInsertionMode);

private:
	std::stringstream ssXML;
};

}
