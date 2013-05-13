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
#include "DatabaseUrl.h"
#include "Node.h"
#include "HTMLCollection.h"
#include "NodeIterator.h"
#include "TreeWalker.h"
#include "NodeFilter.h"
#include "DOMImplementation.h"

namespace toolbot {
	class UnitTestHtmlDocumentFactory;
}

namespace htmlparser {
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
 * @brief class wrapping an html document
 * this class can not be instanciated without
 * the help of htmlparser::DocumentFactory
 * @see htmlparser::DocumentFactory
 */
class Document : public Node {

	friend class DocumentFactory;
	friend class NodeFactory;

	friend class toolbot::UnitTestHtmlDocumentFactory;

private:
	Document(const DatabaseUrl& url, const char* characterSet = "utf-8", const char* contentType = "application/xml");
public:
	virtual ~Document();

public:
	/**
	 * returns all elements of a certain type
	 * @param localName name/type of the element
	 */
	HTMLCollection getElementsByTagName(const DOMString& localName);

	/**
	 * returns all elements of a certain type, considering namespaces
	 * @param nameSpace namespace of the elements
	 * @param localName name/type of the elements
	 */
	HTMLCollection getElementsByTagNameNS(const DOMString& nameSpace, const DOMString& localName);

	/**
	 * returns all elements of a certain class
	 * @param className name of the classes of the elements to return
	 */
	HTMLCollection getElementsByClassName(const DOMString& className);

	/**
	 * returns an element by it's id
	 * @param elementId id of the element
	 */
	Element* getElementById(const DOMString& elementId);

	/**
	 * creates an html element using a name
	 * @param name name of the element
	 */
	Element* createElement(const DOMString& localName);

	/**
	 * creates an html element using a name and namespace
	 * @param nameSpace namespace of the element
	 * @param qualifiedName name of the element
	 */
	Element* createElementNS(const DOMString* nameSpace, const DOMString& qualifiedName);

	/**
	 * creates a document fragment, normally used for iframes etc.
	 */
	DocumentFragment* createDocumentFragment();

	/**
	 * creates a node containing text
	 * @param data character data of the new text node
	 */
	Text* createTextNode(const DOMString& data);

	/**
	 * creates a comment node containing character data
	 * @param data character data of the comment
	 */
	Comment* createComment(const DOMString& data);

	/**
	 * creates a processing instruction
	 * @param target //TODO
	 * @param data
	 */
	ProcessingInstruction* createProcessingInstruction(const DOMString& target, const DOMString& data);

	/**
	 * imports a node
	 * @param node node to import from
	 * @param deep true if node is imported recursively
	 */
	Node* importNode(Node* node, bool deep = true);

	/**
	 * adopts a node from another document, removing it from
	 * it's source document
	 * @param node node to adopt
	 */
	Node* adoptNode(Node* node);

	/**
	 * creates an event
	 * @param interface //TODO
	 */
	Event* createEvent(const DOMString& interface);

	/**
	 * creates a range of nodes
	 * which is used for enumeration of
	 * nodes contained by this document
	 */
	Range* createRange();

	/**
	 * creates a iterator for this documents nodes
	 * @param root root node of the returned iterator
	 * @param whatToShow filter certain node types if neccessary
	 * @param filter generic NodeFilter
	 * @see htmlparser::NodeFilter
	 */
	NodeIterator createNodeIterator(Node* root, NodeFilter::Type whatToShow = NodeFilter::SHOW_ALL, NodeFilter* filter = 0);

	/**
	 * creates a tree walker which is used for navigation in this documents nodes
	 * @param root root node of this treewalker
	 * @param whatToShow filter certain node types if neccessary
	 * @param filter generic NodeFilter
	 * @see htmlparser::NodeFilter
	 */
	TreeWalker createTreeWalker(Node* root, NodeFilter::Type whatToShow = NodeFilter::SHOW_ALL, NodeFilter* filter = 0);

private:
	Node* doAdoptNode(Node* node);

private:
	DatabaseUrl dbUrl;

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
