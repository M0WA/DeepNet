/**
 *
 * @file src/Element.h
 * @author Moritz Wagner
 * @date 03.03.2013
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

/**
 * @brief implementation of a generic DOM element
 */
class Element: public domparser::Node {

protected:
	/**
	 * constructs an element given it's owning document and it's
	 * tag name
	 * @param ownerDocument parent document
	 * @param localname tag name of this element
	 * @see domparser::ElementFactory
	 */
	Element(Document* ownerDocument, const DOMString& localname);

public:
	virtual ~Element();

	/**
	 * get's an attribute by it's name
	 * @param name name of the attribute
	 * @return attribute content or null
	 */
	DOMStringPtr getAttribute(const DOMString& name);

	/**
	 * get's an attribute by it's name and namespace
	 * @param nameSpace namespace of the attribute
	 * @param localName unqualified name of the attribute
	 * @return attribute content or null
	 */
	DOMStringPtr getAttributeNS(DOMString* nameSpace, const DOMString& localName);

	/**
	 * set's an attribute by name and value
	 * @param name name of the new attribute and it's value
	 * @param value value of the attribute
	 */
	void setAttribute(const DOMString& name, const DOMString& value);

	/**
	 * set's an attribute by name, namespace and value
	 * @param nameSpace namespace of the attribute
	 * @param name name of the attribute
	 * @param value value of the attribute
	 */
	void setAttributeNS(DOMString* nameSpace,  const DOMString& name,  const DOMString& value);

	/**
	 * removes attributes by their name
	 * @param name name of the attribute
	 */
	void removeAttribute(const DOMString& name);

	/**
	 * removes an attribute by it's name and namespace
	 * @param nameSpace namespace of the attribute
	 * @param localName name of the attribute
	 */
	void removeAttributeNS(DOMString* nameSpace, const DOMString& localName);

	/**
	 * checks if this element has a certain attribute
	 * @param name name of the attribute
	 * @return true if it exists, false if not
	 */
	bool hasAttribute(DOMString name);

	/**
	 * checks if this element has a certain attribute
	 * @param nameSpace namespace of the attribute
	 * @param localName name of the attribute
	 * @return true if it exists, false if not
	 */
	bool hasAttributeNS(DOMString* nameSpace, const DOMString& localName);

public:
	/**
	 * gets the name of this element's tag
	 * @return name of this element
	 */
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
