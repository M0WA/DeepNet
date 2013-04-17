/*
 * HtmlSAX2Document.h
 *
 *  Created on: 02.02.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <vector>

#include "HtmlSAX2Element.h"

namespace htmlparser {

class HtmlSAX2Document {
public:
	HtmlSAX2Document();
	virtual ~HtmlSAX2Document();

public:
	inline void Reset() { elements.clear(); }

	std::vector<HtmlSAX2Element> elements;
};

}
