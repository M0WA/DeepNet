/**
 *
 * @file UnitTestHtmlDocumentFactory.h
 * @author Moritz Wagner
 * @date Mar 9, 2013
 *
 */

#pragma once

#include <string>
#include <sstream>

#include <DocumentFactory.h>
#include "UnitTest.h"

#include <HttpUrl.h>

namespace domparser {
	namespace generic {
		class Token;
	}
}

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

class UnitTestHtmlDocumentFactory : public domparser::DocumentFactory, public toolbot::UnitTest {

public:
	UnitTestHtmlDocumentFactory( const network::HttpUrl& url, const std::string& htmlDirectory );
	virtual ~UnitTestHtmlDocumentFactory();

private:
	virtual bool OnToken(const domparser::generic::Token& token);
	virtual void SwitchMode(const domparser::DocumentFactory::InsertionMode& newInsertionMode);

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestHtmlDocumentFactory"; }

private:
	std::stringstream ssXML;
	network::HttpUrl url;
	std::string htmlDirectory;
};

}
