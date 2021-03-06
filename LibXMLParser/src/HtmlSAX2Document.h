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
	HtmlSAX2Document(const caching::DatabaseUrl& url);
	virtual ~HtmlSAX2Document();

public:
	void Reset();
	const caching::DatabaseUrl& Url() const { return result.url; }

	std::vector<HtmlSAX2Element> elements;
	LibXMLParserResult result;
};

}
