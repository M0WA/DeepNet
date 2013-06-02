/*
 * HtmlSAX2Element.h
 *
 *  Created on: 02.02.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <vector>

#include "HtmlSAX2Namespace.h"
#include "HtmlSAX2Attribute.h"

namespace htmlparser {

class HtmlSAX2Element {
public:
	HtmlSAX2Element();
	virtual ~HtmlSAX2Element();

public:
	bool GetAttributeByName(const std::string& attributeName, HtmlSAX2Attribute& attribute);

	HtmlSAX2Attribute attribute;
	std::vector<HtmlSAX2Namespace> namespaces;
	std::vector<HtmlSAX2Attribute> attributes;
	int nb_defaulted;
};

}
