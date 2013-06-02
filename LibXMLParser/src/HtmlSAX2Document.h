/*
 * HtmlSAX2Document.h
 *
 *  Created on: 02.02.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <vector>
#include <string>
#include <map>

#include <DatabaseUrl.h>

#include "LibXMLParserResult.h"
#include "HtmlSAX2Element.h"

namespace libxmlparser {

class HtmlSAX2Document {
public:
	HtmlSAX2Document(const htmlparser::DatabaseUrl& url);
	virtual ~HtmlSAX2Document();

public:
	void Reset();
	void DumpXML(std::string& xmlContent);

	const htmlparser::DatabaseUrl& Url() const { return url; }

	std::vector<HtmlSAX2Element> elements;
	LibXMLParserResult result;

	htmlparser::DatabaseUrl url;
	int wellformed;
};

}
