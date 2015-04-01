/**
 *
 * @file Attr.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "Attr.h"

namespace domparser {

Attr::Attr(const DOMString& name, const DOMString& value, const DOMString* namespaceURIIn, const DOMString* prefixIn)
: localName(name)
, value(value)
, namespaceURI(0)
, prefix(0) {

	if(!namespaceURIIn) {
		(*this->namespaceURI) = *namespaceURIIn;
	}

	if(!prefixIn) {
		(*this->prefix) = *prefixIn;
	}
}

Attr::~Attr() {
}

}
