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

namespace htmlparser {
	class Element;
	class DocumentFactory;

/**
 * @brief wrapper class for a generic html element
 * this class cannot be instanciated without using
 * htmlparser::ElementFactory
 * @see htmlparser::ElementFactory
 */
class Element: public htmlparser::Node {

protected:
	Element(Document* ownerDocument, const DOMString& localname);
public:
	virtual ~Element();

	/**
	 * gets an attribute value by it's name
	 * @param name name of the attribute
	 * @return attribute value or NULL
	 */
	DOMStringPtr getAttribute(const DOMString& name);

	/**
	 * gets an attribute value by it's name and namespace
	 * @param nameSpace namespace of the attribute
	 * @param localName name of the attribute
	 * @return attribute value or NULL
	 */
	DOMStringPtr getAttributeNS(DOMString* nameSpace, const DOMString& localName);

	/**
	 * sets/adds an attribute from name and value
	 * @param name name of the element
	 * @param value value of the element
	 */
	void setAttribute(const DOMString& name, const DOMString& value);

	/**
	 * sets/adds an attribute from name and value
	 * also respecting it's namespace
	 * @param nameSpace namespace of the element
	 * @param name name of the element
	 * @param value value of the element
	 */
	void setAttributeNS(DOMString* nameSpace,  const DOMString& name,  const DOMString& value);

	/**
	 * removes an attribute from this element by it's name
	 * @param name name of the element
	 */
	void removeAttribute(const DOMString& name);

	/**
	 * removes an attribute from this element using it's local name and
	 * namespace
	 * @param nameSpace namespace of the element
	 * @param localName name of the attribute
	 */
	void removeAttributeNS(DOMString* nameSpace, const DOMString& localName);

	/**
	 * checks if this element has a certain attribute
	 * @param name name of the attribute to check for
	 * @return true if attribute exists, false if not
	 */
	bool hasAttribute(DOMString name);

	/**
	 * checks if this element has a certain attribute
	 * @param nameSpace namespace of the attribute to check for
	 * @param localName name of the attribute to check for
	 * @return true if attribute exists, false if not
	 */
	bool hasAttributeNS(DOMString* nameSpace, const DOMString& localName);

public:
	/**
	 * returns tag name as string
	 * @return this elements tag name
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
