/*
 * HtmlSAX2Attribute.h
 *
 *  Created on: 02.02.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

#include "HtmlSAX2Namespace.h"

namespace htmlparser {

class HtmlSAX2Attribute {
public:
	HtmlSAX2Attribute();
	virtual ~HtmlSAX2Attribute();

public:
	std::string localname;
	std::string value;
	HtmlSAX2Namespace htmlNamespace;
};

}
