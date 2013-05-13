/**
 *
 * @file ElementFactory.h
 * @author Moritz Wagner
 * @date Mar 5, 2013
 *
 */

#pragma once

#include "DOMTypes.h"

namespace htmlparser {
	class Document;
	class Element;

/**
 * factory class for html elements
 */
class ElementFactory {
private:
	ElementFactory(Document* doc,const DOMString& localName);
public:
	virtual ~ElementFactory();

public:
	/**
	 * creates a new element from a name
	 * @param doc owning document
	 * @param localName name of new element
	 * @return new element
	 */
	static Element* FromName(Document* doc, const DOMString& localName);

	/**
	 * creates a new element from a name
	 * @param doc owning document
	 * @param nameSpace namespace of the element
	 * @param qualifiedName name of new element
	 * @return new element
	 */
	static Element* FromName(Document* doc, const DOMString* nameSpace, const DOMString& qualifiedName);

private:
	Element* FromName();

private:
	Document* doc;
	const DOMString& localName;
};

}
