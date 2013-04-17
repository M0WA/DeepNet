/**
 *
 * @file ElementFactory.h
 * @author Moritz Wagner
 * @date Mar 5, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "DOMTypes.h"

namespace htmlparser {
	class Document;
	class Element;

class ElementFactory {
private:
	ElementFactory(Document* doc,const DOMString& localName);
public:
	virtual ~ElementFactory();

public:
	static Element* FromName(Document* doc, const DOMString& localName);
	static Element* FromName(Document* doc, const DOMString* nameSpace, const DOMString& qualifiedName);

private:
	Element* FromName();

private:
	Document* doc;
	const DOMString& localName;
};

}
