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

#include <HttpUrl.h>

namespace toolbot {
	class UnitTestHtmlDocumentFactory;
}

namespace network {
	class HttpUrl;
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

/**
 * @brief implements a DOM compatible document
 * @see domparser::DocumentFactory and domparser::NodeFactory
 */
class Document : public Node {

	friend class DocumentFactory;
	friend class NodeFactory;

	friend class toolbot::UnitTestHtmlDocumentFactory;

private:
	Document(const network::HttpUrl& url, const char* characterSet = "utf-8", const char* contentType = "application/xml");

public:
	virtual ~Document();

public:
	/**
	 * @see domparser::Document::getElementsByTagNameNS
	 */
	HTMLCollection getElementsByTagName(const DOMString& localName);

	/**
	 * returns a collection of all tags with a certain name and namespace
	 * @param nameSpace namespace of the html tag to look for
	 * @param localName name of html tag to look for
	 * @return collection of all elements
	 */
	HTMLCollection getElementsByTagNameNS(const DOMString& nameSpace, const DOMString& localName);

	/**
	 *  returns a collection of all tags with a certain class
	 *  @param className name of the class to look for
	 *  @return collection of all elements of a certain class
	 */
	HTMLCollection getElementsByClassName(const DOMString& className);

	/**
	 * gets an element by it's id
	 * @param elementId id of the element
	 * @return element or NULL if not found
	 */
	Element* getElementById(const DOMString& elementId);

	/**
	 * @see domparser::Document::createElementNS
	 */
	Element* createElement(const DOMString& localName);

	/**
	 * creates an elements by a name and it's namespace
	 * @return created element
	 */
	Element* createElementNS(const DOMString* nameSpace, const DOMString& qualifiedName);

	/**
	 * creates an empty document fragment
	 * @return created document fragment
	 */
	DocumentFragment* createDocumentFragment();

	/**
	 * creates a text node containing data
	 * @param data initial data
	 * @return created text node
	 */
	Text* createTextNode(const DOMString& data);

	/**
	 * creates comment containing data
	 * @param data initial data
	 * @return created comment
	 */
	Comment* createComment(const DOMString& data);

	/**
	 * creates an processing instruction
	 * @see DOM5 specification
	 * @return created processing instruction
	 */
	ProcessingInstruction* createProcessingInstruction(const DOMString& target, const DOMString& data);

	/**
	 * imports/copies node from another document optionally containing
	 * all child nodes
	 * @param node node to import/copy
	 * @param deep copy child nodes too
	 */
	Node* importNode(Node* node, bool deep = true);

	/**
	 * adopts/swaps a node from a foreign document and removes it there
	 * @param node node to adopt
	 * @return adopted node
	 */
	Node* adoptNode(Node* node);

	/**
	 * creates a named event
	 * @param name of newly created event
	 * @return created event
	 */
	Event* createEvent(const DOMString& interface);

	/**
	 * creates range, all ranges are updated instantly when
	 * the document changes
	 * @return created range
	 */
	Range* createRange();

	/**
	 * creates node iterator
	 * @param root where to start iterating
	 * @param whatToShow type of nodes to consider
	 * @param nodeFilter predefined node filter
	 * @return created iterator
	 */
	NodeIterator createNodeIterator(Node* root, NodeFilter::Type whatToShow = NodeFilter::SHOW_ALL, NodeFilter* filter = 0);

	/**
	 * creates tree walker
	 * @param root where to start walking
	 * @param whatToShow type of nodes to consider
	 * @param filter predefined node filter
	 * @return created treewalker
	 */
	TreeWalker createTreeWalker(Node* root, NodeFilter::Type whatToShow = NodeFilter::SHOW_ALL, NodeFilter* filter = 0);

private:
	Node* doAdoptNode(Node* node);

private:
	network::HttpUrl dbUrl;

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
