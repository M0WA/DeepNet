/**
 *
 * @file src/Document.cpp
 * @author Moritz Wagner
 * @date Mar 2, 2013
 *
 * TODO: description for this file
 *
 */

#include "Document.h"

#include <algorithm>

#include "Comment.h"
#include "ProcessingInstruction.h"
#include "Text.h"
#include "DocumentFragment.h"
#include "Range.h"

#include "HTMLCollection.h"
#include "ElementFactory.h"

namespace domparser {

Document::Document(const network::HttpUrl& url, const char* characterSet, const char* contentType)
: Node(this,DOCUMENT_NODE)
, dbUrl(url)
, URL(url.GetFullUrl())
, characterSet(characterSet)
, contentType(contentType){
}

Document::~Document() {
}

HTMLCollection Document::getElementsByTagName(const DOMString& localName) {
	return HTMLCollection();
}

HTMLCollection Document::getElementsByTagNameNS(const DOMString& nameSpace, const DOMString& localName) {
	return HTMLCollection();
}

HTMLCollection Document::getElementsByClassName(const DOMString& classNames) {
	return HTMLCollection();
}

Element* Document::getElementById(const DOMString& elementId) {
	return 0;
}

Element* Document::createElement(const DOMString& localName) {
	return ElementFactory::FromName(this,localName);
}

Element* Document::createElementNS(const DOMString* nameSpace, const DOMString& qualifiedName) {
	return ElementFactory::FromName(this, nameSpace, qualifiedName);
}

DocumentFragment* Document::createDocumentFragment() {
	return new DocumentFragment(this);
}

Text* Document::createTextNode(const DOMString& data) {

	Text* pText = new Text(this);
	if(!data.empty())
		pText->appendData(data);
	return pText;
}

Comment* Document::createComment(const DOMString& data) {

	Comment* pComment = new Comment(this);
	if(!data.empty())
		pComment->appendData(data);
	return pComment;
}

ProcessingInstruction* Document::createProcessingInstruction(const DOMString& target, const DOMString& data) {

	ProcessingInstruction* pInstruction = new ProcessingInstruction(this,target);
	if(!data.empty())
		pInstruction->appendData(data);
	return pInstruction;
}

Node* Document::importNode(Node* node, bool deep) {
	return 0;
}

Node* Document::adoptNode(Node* node) {

	if(node->GetNodeType() == DOCUMENT_NODE) {
		//TODO: throw NotSupportedError
		throw;
	}

	return doAdoptNode(node);
}

Event* Document::createEvent(const DOMString& interface) {
	return 0;
}

Range* Document::createRange() {

	Range* range = new Range(this,0);
	return range;
}

NodeIterator Document::createNodeIterator(Node* root, NodeFilter::Type whatToShow, NodeFilter* filter) {
	return NodeIterator(root, whatToShow, filter);
}

TreeWalker Document::createTreeWalker(Node* root, NodeFilter::Type whatToShow, NodeFilter* filter) {
	return TreeWalker(root, whatToShow, filter);
}

Node* Document::doAdoptNode(Node* node) {

	Node* adoptParent = node->GetParentNode();
	if(adoptParent) {
		ownerDocument->removeChild(node);
	}

	//TODO: not fully implemented
	return 0;
}

}
