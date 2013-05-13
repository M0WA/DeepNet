/**
 *
 * @file Attr.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 */

#pragma once

#include "DOMTypes.h"

namespace htmlparser {

/**
 * @brief class to wrap generic html attributes
 */
class Attr {
public:
	/**
	 * construct an html attribute
	 * @param name name of the attribute i.e. "class", "style" etc.
	 * @param value value of the attribute
	 * @param namespaceURI optional namespace URI (NULL for none)
	 * @param prefix optional prefix for attribute (NULL for none)
	 */
	Attr(const DOMString& name, const DOMString& value, const DOMString* namespaceURI = 0, const DOMString* prefix = 0);
	virtual ~Attr();

private:
	DOMString localName;
	DOMString value;

	DOMStringPtr namespaceURI;
	DOMStringPtr prefix;
};

}
