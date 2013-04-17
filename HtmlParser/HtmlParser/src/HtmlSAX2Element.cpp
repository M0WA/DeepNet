/*
 * HtmlSAX2Element.cpp
 *
 *  Created on: 02.02.2012
 *      Author: Moritz Wagner
 */

#include "HtmlSAX2Element.h"

namespace htmlparser {

HtmlSAX2Element::HtmlSAX2Element()
{
}

HtmlSAX2Element::~HtmlSAX2Element()
{
}

bool HtmlSAX2Element::GetAttributeByName(const std::string& attributeName, HtmlSAX2Attribute& attribute)
{
	std::vector<HtmlSAX2Attribute>::iterator iterAttr = attributes.begin();
	for(; iterAttr != attributes.end(); ++iterAttr)
		if(iterAttr->localname.compare( attributeName ) == 0)
		{
			attribute = *iterAttr;
			return true;
		}

	return false;
}

}
