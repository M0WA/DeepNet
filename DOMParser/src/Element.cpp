/**
 *
 * @file Element.cpp
 * @author Moritz Wagner
 * @date Mar 3, 2013
 *
 * TODO: description for this file
 *
 */

#include "Element.h"

namespace domparser {

Element::Element(Document* ownerDocument, const DOMString& localname)
: Node(ownerDocument, ELEMENT_NODE)
, localName(localname)
, namespaceURI(0)
, prefix(0)
{
}

Element::~Element() {
}

DOMStringPtr Element::getAttribute(const DOMString& name) {
	DOMStringPtr ptr;
	return ptr;
}

DOMStringPtr Element::getAttributeNS(DOMString* nameSpace, const DOMString& localName) {
	DOMStringPtr ptr;
	return ptr;
}

void Element::setAttribute(const DOMString& name, const DOMString& value) {
}

void Element::setAttributeNS(DOMString* nameSpace,  const DOMString& name,  const DOMString& value) {
}

void Element::removeAttribute(const DOMString& name) {
}

void Element::removeAttributeNS(DOMString* nameSpace, const DOMString& localName) {
}

bool Element::hasAttribute(DOMString name) {
	return false;
}

bool Element::hasAttributeNS(DOMString* nameSpace, const DOMString& localName) {
	return false;
}

}
