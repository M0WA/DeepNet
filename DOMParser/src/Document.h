/**
 *
 * @file Document.h
 * @author Moritz Wagner
 * @date Mar 2, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once


#include "DOMTypes.h"
#include "Node.h"
#include "HTMLCollection.h"
#include "NodeIterator.h"
#include "TreeWalker.h"
#include "NodeFilter.h"
#include "DOMImplementation.h"

#include <DatabaseUrl.h>

namespace toolbot {
	class UnitTestHtmlDocumentFactory;
}

namespace htmlparser {
	class DatabaseUrl;
}

namespace domparser {

class Token;
class DocumentType;
class Element;
class DocumentFragment;
class Text;
class Comment;
class ProcessingInstruction;
class Range;
class HTMLHeadElement;

class Document : public Node {

	friend class DocumentFactory;
	friend class NodeFactory;

	friend class toolbot::UnitTestHtmlDocumentFactory;

private:
	Document(const htmlparser::DatabaseUrl& url, const char* characterSet = "utf-8", const char* contentType = "application/xml");

public:
	virtual ~Document();

public:
	HTMLCollection getElementsByTagName(const DOMString& localName);
	HTMLCollection getElementsByTagNameNS(const DOMString& nameSpace, const DOMString& localName);
	HTMLCollection getElementsByClassName(const DOMString& classNames);
	Element* getElementById(const DOMString& elementId);

	Element* createElement(const DOMString& localName);
	Element* createElementNS(const DOMString* nameSpace, const DOMString& qualifiedName);

	DocumentFragment* createDocumentFragment();
	Text* createTextNode(const DOMString& data);
	Comment* createComment(const DOMString& data);
	ProcessingInstruction* createProcessingInstruction(const DOMString& target, const DOMString& data);

	Node* importNode(Node* node, bool deep = true);
	Node* adoptNode(Node* node);

	Event* createEvent(const DOMString& interface);
	Range* createRange();

	NodeIterator createNodeIterator(Node* root, NodeFilter::Type whatToShow = NodeFilter::SHOW_ALL, NodeFilter* filter = 0);
	TreeWalker createTreeWalker(Node* root, NodeFilter::Type whatToShow = NodeFilter::SHOW_ALL, NodeFilter* filter = 0);

private:
	Node* doAdoptNode(Node* node);

private:
	htmlparser::DatabaseUrl dbUrl;

	DOMImplementation implementation;
	DOMString documentURI;
	DOMString URL;

	DOMString compatMode;
	DOMString characterSet;
	DOMString contentType;

	DocumentType* doctype;
	Element* documentElement;

	HTMLHeadElement* headElement;
};

}
