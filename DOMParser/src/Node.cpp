/**
 *
 * @file src/Node.cpp
 * @author Moritz Wagner
 * @date Mar 3, 2013
 *
 * TODO: description for this file
 *
 */

#include "Node.h"

#include <list>

#include "Document.h"
#include "Range.h"
#include "ProcessingInstruction.h"
#include "DocumentType.h"
#include "Element.h"
#include "NodeFilter.h"

namespace domparser {

Node::Node(Document* ownerDocument, NodeType type)
: ownerDocument(ownerDocument)
, nodeType(type){
}

Node::~Node() {
}

Document* Node::GetOwnerDocument() {

	if( GetNodeType() == DOCUMENT_NODE)
		return 0;
	return ownerDocument;
}

DOMString Node::GetNodeName() const {

	switch( GetNodeType() ) {

	case ELEMENT_NODE:
		return dynamic_cast<const Element*>(this)->GetTagName();

	case TEXT_NODE:
		return "#text";

	case PROCESSING_INSTRUCTION_NODE:
		return dynamic_cast<const ProcessingInstruction*>(this)->GetTarget();

	case COMMENT_NODE:
		return "#comment";

	case DOCUMENT_NODE:
		return "#document";

	case DOCUMENT_TYPE_NODE:
		return dynamic_cast<const DocumentType*>(this)->GetName();

	case DOCUMENT_FRAGMENT_NODE:
		return "#document-fragment";

	default:
		//TODO: this is an error
		throw;
	}

	return "";
}

const DOMString* Node::GetNodeValue() const {

	switch( GetNodeType() ) {

	case TEXT_NODE:
	case PROCESSING_INSTRUCTION_NODE:
	case COMMENT_NODE:
		return dynamic_cast<const CharacterData*>(this)->GetData();
	default:
		return 0;
	}
}

DOMStringPtr Node::GetTextContent() const {
	return DOMStringPtr();
}

void Node::SetNodeValue(const DOMString& value){
}

void Node::SetTextContent(const DOMString& value){
}


bool Node::doGetChildIdx(Node* node,size_t& pos) {

	size_t len = GetChildNodes().GetLength();
	for(pos = 0; pos < len; pos++) {
		if( GetChildNodes().GetItem(pos) == node )
			return true;
	}

	return false;
}

Node* Node::doPreInsert(Node* node, Node* child) {

	switch( GetNodeType() )
	{
	case ELEMENT_NODE:
	case DOCUMENT_NODE:
	case DOCUMENT_FRAGMENT_NODE:
		break;

	default:
		//TODO: throw HierarchyRequestError
		return 0;
	}

	if(node->contains(this)) {
		//TODO: throw HierarchyRequestError
		return 0;
	}

	if(!child && !contains(child)) {
		//TODO: throw NotFoundError
		return 0;
	}

	if( GetNodeType() == DOCUMENT_NODE) {
		switch(node->nodeType) {
		case DOCUMENT_FRAGMENT_NODE:
		case DOCUMENT_TYPE_NODE:
		case ELEMENT_NODE:
		case PROCESSING_INSTRUCTION_NODE:
		case COMMENT_NODE:
			break;
		default:
			//TODO: throw HierarchyRequestError
			return 0;
		}

		if(node->GetNodeType() == DOCUMENT_FRAGMENT_NODE) {
			//TODO:
		}
		else if(node->GetNodeType() == ELEMENT_NODE) {
			//TODO:
		}
		else if(node->GetNodeType() == DOCUMENT_TYPE_NODE) {
			//TODO:
		}
	}
	else{
		switch(node->GetNodeType()) {
		case DOCUMENT_FRAGMENT_NODE:
		case ELEMENT_NODE:
		case TEXT_NODE:
		case PROCESSING_INSTRUCTION_NODE:
		case COMMENT_NODE:
			break;
		default:
			//TODO: throw HierarchyRequestError
			return 0;
		}
	}

	Node* refChild = child;
	if(refChild == node) {
		refChild = node->GetNextSibling();
	}

	node = ownerDocument->adoptNode(node);
	node = doInsert(node, refChild);
	return node;
}

Node* Node::doInsert(Node* node, Node* child, bool supressObservers) {

	size_t count = 1;
	if(node->GetNodeType() == DOCUMENT_FRAGMENT_NODE) {
		count = node->GetChildNodes().GetLength();
	}

	size_t childIdx = 0;
	if(child && !doGetChildIdx(child,childIdx)) {
		//TODO: error: should not happen
		return 0;
	}

	std::list<Range*>& ranges = Range::GetRanges();
	std::list<Range*>::iterator iterRanges = ranges.begin();
	for(;iterRanges != ranges.end();++iterRanges) {

		Range* cur = (*iterRanges);
		if(cur->GetStartContainer() == this &&
		   cur->GetStartOffset() > childIdx) {
		   cur->setStart(cur->GetStartContainer(), cur->GetStartOffset() + count);
		}

		if(cur->GetEndContainer() == this &&
		   cur->GetEndOffset() > childIdx ) {
			cur->setEnd(cur->GetEndContainer(),cur->GetEndOffset() + count);
		}
	}

	NodeList nodes;
	switch( node->GetNodeType() ) {
	case DOCUMENT_FRAGMENT_NODE:
		break;
	default:
		break;
	}

	//TODO: not fully implemented

	return node;
}

Node* Node::doPreRemoveChild(Node* child) {

	if(child->GetParentNode() != this) {
		//TODO: throw NotFoundError
		return 0; }

	child = doRemoveChild(child);
	return child;
}

Node* Node::doRemoveChild(Node* child, bool supressObservers) {

	size_t index = 0;
	if(!GetParentNode()->doGetChildIdx(this,index)) {
		//TODO: error: should not happen
		return 0;
	}

	std::list<Range*>& ranges = Range::GetRanges();
	std::list<Range*>::iterator iterRanges = ranges.begin();
	for(;iterRanges != ranges.end();++iterRanges) {

		Range* cur = (*iterRanges);

		if( child->contains( cur->GetStartContainer() ) )
			cur->setStart(this,index);

		if( child->contains( cur->GetEndContainer() ) )
			cur->setEnd(this,index);

		if( cur->GetStartContainer() == this &&
			cur->GetStartOffset() > index ) {
			cur->setStart(this,cur->GetStartOffset() - 1);
		}

		if( cur->GetEndContainer() == this &&
			cur->GetEndOffset() > index ) {
			cur->setEnd(this,cur->GetEndOffset() - 1);
		}
	}

	if(!supressObservers) {
		MutationRecord record;
		record.target = this;
		record.type = "childList";
		record.addedNodes.AppendItem(child);
		record.nextSibling = child->GetNextSibling();
		record.previousSibling = child->GetPreviousSibling();
		QueueMutationRecord(record);
	}

	//TODO: not fully implemented

	childNodes.RemoveItem(child);

	if(!supressObservers) {
		OnNodeRemoved(child);
	}

	return child;
}

Node::DocumentPosition Node::compareDocumentPosition(Node* other) {

	Node* reference = this;
	if(other == reference){
		return DOCUMENT_POSITION_EQUAL;
	}

	if(other->GetOwnerDocument() != reference->GetOwnerDocument() ) {
		Node::DocumentPosition pos = static_cast<Node::DocumentPosition>( DOCUMENT_POSITION_DISCONNECTED + DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC );
		if(other > reference) {
			return static_cast<Node::DocumentPosition>(pos + DOCUMENT_POSITION_FOLLOWING);
		}
		else {
			return static_cast<Node::DocumentPosition>(pos + DOCUMENT_POSITION_PRECEDING);
		}
	}

	Node* ancestorNode = reference;
	while( (ancestorNode = reference->GetParentNode()) ) {
		if(ancestorNode == other) {
			return static_cast<Node::DocumentPosition>(DOCUMENT_POSITION_CONTAINS + DOCUMENT_POSITION_PRECEDING);
		}
	}

	FollowFilter filterFollow(reference);
	NodeIterator iterNodes = reference->GetOwnerDocument()->createNodeIterator(reference,NodeFilter::SHOW_ALL,&filterFollow);

	Node* followNode = 0;
	do {
		followNode = iterNodes.nextNode();
		if(followNode == other)
			return DOCUMENT_POSITION_PRECEDING;
	}
	while( followNode );

	return DOCUMENT_POSITION_FOLLOWING;
}

Node* Node::insertBefore(Node* node, Node* child) {
	return doPreInsert(node, child);
}

Node* Node::appendChild(Node* node) {
	return 0;
}

Node* Node::replaceChild(Node* node, Node* child) {
	return 0;
}

Node* Node::removeChild(Node* child) {
	return doPreRemoveChild(child);
}

void Node::normalize() {
}

Node* Node::cloneNode(bool deep) {
	return 0;
}

bool Node::isEqualNode(Node* node) {
	return false;
}

bool Node::contains(Node* other) {
	return false;
}

DOMStringPtr Node::lookupPrefix(const DOMString& nameSpace) {
	return DOMStringPtr();
}

DOMStringPtr Node::lookupNamespaceURI(const DOMString& prefix) {
	return DOMStringPtr();
}

bool Node::isDefaultNamespace(const DOMString& nameSpace) {
	return false;
}

void Node::RegisterObserver(const MutationObserver& observer) {
	registeredObservers.push_back(observer);
}

void Node::QueueMutationRecord(const MutationRecord& record) {
}

}
