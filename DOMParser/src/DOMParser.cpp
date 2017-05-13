/**
 *
 * @file DOMParser.cpp
 * @author Moritz Wagner
 * @date 09.06.2013
 *
 */

#include "DOMParser.h"

#include <HtmlParserException.h>
#include <Logging.h>

#include "Document.h"
#include "DocumentFactory.h"
#include "DOMParserResult.h"

namespace domparser {

DOMParser::DOMParser() {
}

DOMParser::~DOMParser() {
}

bool DOMParser::Parse(const htmlparser::DatabaseUrl& url,const network::HtmlData& html, tools::Pointer<htmlparser::IHtmlParserResult>& result) {

	Document* doc = 0;
	try {
		doc = DocumentFactory::FromHtmlData(url,html);
	}
	CATCH_EXCEPTION(htmlparser::HtmlParserException,ex,!log::Logging::IsLogLevelTrace())
	}

	tools::Pointer<Document> docPtr(doc);
	if(docPtr.IsNull())
		return false;

	result.Set(new DOMParserResult(url),true);

	return false;
}

}
