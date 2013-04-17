/**
 *
 * @file Attr.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "DOMTypes.h"

namespace htmlparser {

class Attr {
public:
	Attr(const DOMString& name, const DOMString& value, const DOMString* namespaceURI = 0, const DOMString* prefix = 0);
	virtual ~Attr();

private:
	DOMString localName;
	DOMString value;

	DOMStringPtr namespaceURI;
	DOMStringPtr prefix;
};

}
