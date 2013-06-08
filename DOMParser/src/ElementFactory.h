/**
 *
 * @file ElementFactory.h
 * @author Moritz Wagner
 * @date 05.03.2013
 *
 */

#pragma once

#include "DOMTypes.h"

namespace domparser {
	class Document;
	class Element;

class ElementFactory {
private:
	/**
	 * constructs an ElementFactory object by it's parent
	 * document and tag name
	 * @param doc parent document
	 * @param localName tag name
	 * @see domparser::ElementFactory::FromName
	 */
	ElementFactory(Document* doc,const DOMString& localName);
public:
	virtual ~ElementFactory();

public:
	/**
	 * constructs an element by it's parent document and it's tag name
	 * @param doc parent document
	 * @param localName tag name of the element
	 * @return constructed element
	 */
	static Element* FromName(Document* doc, const DOMString& localName);

	/**
	 * constructs an element by it's parent document and it's tag name
	 * @param doc parent document
	 * @param nameSpace namespace of the element
	 * @param qualifiedName tag name of the element
	 * @return constructed element
	 */
	static Element* FromName(Document* doc, const DOMString* nameSpace, const DOMString& qualifiedName);

private:
	Element* FromName();

private:
	Document* doc;
	const DOMString& localName;
};

}
