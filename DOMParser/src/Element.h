/**
 *
 * @file Element.h
 * @author Moritz Wagner
 * @date Mar 3, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <vector>

#include "Node.h"
#include "DOMTypes.h"
#include "DOMTokenList.h"
#include "Attr.h"
#include "HTMLCollection.h"

namespace domparser {
	class Element;
	class DocumentFactory;

class Element: public domparser::Node {

protected:
	Element(Document* ownerDocument, const DOMString& localname);
public:
	virtual ~Element();

	DOMStringPtr getAttribute(const DOMString& name);
	DOMStringPtr getAttributeNS(DOMString* nameSpace, const DOMString& localName);

	void setAttribute(const DOMString& name, const DOMString& value);
	void setAttributeNS(DOMString* nameSpace,  const DOMString& name,  const DOMString& value);

	void removeAttribute(const DOMString& name);
	void removeAttributeNS(DOMString* nameSpace, const DOMString& localName);

	bool hasAttribute(DOMString name);
	bool hasAttributeNS(DOMString* nameSpace, const DOMString& localName);

public:
	const DOMString& GetTagName() const { return tagName; }

private:
	DOMString localName;
	DOMStringPtr namespaceURI;
	DOMStringPtr prefix;
	DOMString tagName;
    DOMString id;
    DOMString className;

    DOMTokenList classList;
    std::vector<Attr> attributes;

	/*
	HTMLCollection getElementsByTagName(DOMString localName);
	HTMLCollection getElementsByTagNameNS(DOMString? namespace, DOMString localName);
	HTMLCollection getElementsByClassName(DOMString classNames);
	*/

	HTMLCollection children;
	Element* firstElementChild;
	Element* lastElementChild;
	Element* previousElementSibling;
	Element* nextElementSibling;

  // readonly attribute unsigned long childElementCount;
};

}
