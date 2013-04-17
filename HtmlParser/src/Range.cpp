/**
 *
 * @file Range.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "Range.h"

#include "Document.h"

#include <list>
#include <algorithm>

#include "Node.h"

namespace htmlparser {

std::list<Range*> Range::ranges;

Range::Range(Node* context, unsigned long offset)
: start(context,offset)
, end(context,offset) {
	RegisterRange();
}

Range::~Range() {
	UnregisterRange();
}

void Range::RegisterRange() {
	ranges.push_back(this);
}

void Range::UnregisterRange() {
	std::list<Range*>::iterator posRange = std::find(ranges.begin(),ranges.end(),this);
	if(posRange != ranges.end())
		ranges.erase(posRange);
}

Range::BoundaryPointPosition Range::ComparePoints(BoundaryPoint& a, BoundaryPoint& b) {
	return Range::ComparePoints(a.container, a.offset, b.container, b.offset);
}

Range::BoundaryPointPosition Range::ComparePoints(Node* nodeA, unsigned long offsetA, Node* nodeB, unsigned long offsetB) {

	if(nodeA == nodeB) {
		if(offsetA < offsetB)
			return BEFORE;
		if(offsetA > offsetB)
			return AFTER;
		return EQUAL;
	}

	Node::DocumentPosition docPos = nodeA->compareDocumentPosition(nodeB);
	if((docPos & Node::DOCUMENT_POSITION_FOLLOWING) == Node::DOCUMENT_POSITION_FOLLOWING) {
		switch( ComparePoints(nodeB,offsetB,nodeA,offsetA) ) {
		case BEFORE:
			return AFTER;
		case AFTER:
			return BEFORE;
		case EQUAL:
			return EQUAL;
		}
	}

	if(nodeA->contains(nodeB)) {
		Node* child = nodeB;
		//TODO: use TreeWalker for this
		while(child) {
			NodeList& childTmp = nodeA->GetChildNodes();
			for(size_t idx = 0; idx < childTmp.GetLength(); idx++) {
				if(childTmp.GetItem(idx) == child) {
					if(idx < offsetA)
						return AFTER;
					else
						return BEFORE;
				}
			}
			child = child->GetParentNode();
		}
	}
	return BEFORE;
}

void Range::SetBoundaryPoint(const RangePos pos, Node* node, unsigned long offset) {

	if(node->GetNodeType() == Node::DOCUMENT_TYPE_NODE) {
		//TODO: throw InvalidNodeTypeError
		return;
	}

	if( offset > node->GetChildNodes().GetLength() ){
		//TODO: throw IndexSizeError
		return;
	}

	BoundaryPoint bp(node, offset);
	switch(pos) {
	case START:
		// ////////////////////////////
		//TODO:
		// ////////////////////////////
		break;
	case END:
		// ////////////////////////////
		//TODO:
		// ////////////////////////////
		break;
	}
}

Range::BoundaryPointPosition Range::comparePoint(Node* node, unsigned long offset) {

	if(node->GetOwnerDocument() != start.container->GetOwnerDocument()) {
		//TODO: throw WrongDocumentError
		throw;
	}

	if(node->GetNodeType() == Node::DOCUMENT_TYPE_NODE) {
		//TODO: throw InvalidNodeTypeError
		throw;
	}

	if(offset > node->GetChildNodes().GetLength()) {
		//TODO: throw IndexSizeError
		throw;
	}

	return ComparePoints(node, offset, start.container, start.offset);
}

Range::BoundaryPointPosition Range::compareBoundaryPoints(RangeType how, Range* sourceRange) {

	if(start.container->GetOwnerDocument() != sourceRange->start.container->GetOwnerDocument()) {
		//TODO: throw WrongDocumentError
		throw;
	}

	BoundaryPoint thisPoint, otherPoint;
	switch(how)
	{
	case START_TO_START:
		thisPoint = start;
		otherPoint = sourceRange->start;
		break;

	case START_TO_END:
		thisPoint = end;
		otherPoint = sourceRange->start;
		break;

	case END_TO_END:
		thisPoint = end;
		otherPoint = sourceRange->end;
		break;

	case END_TO_START:
		thisPoint = start;
		otherPoint = sourceRange->end;
		break;
	}

	return ComparePoints(thisPoint, otherPoint);
}

void Range::setStartBefore(Node* refNode) {

	Node* parent = refNode->GetParentNode();
	if(!parent) {
		//TODO: throw InvalidNodeTypeError
		return;
	}

	NodeList& childs = parent->GetChildNodes();
	for(size_t idx = 0; idx < childs.GetLength(); idx++) {
		if(childs.GetItem(idx) == refNode){
			setStart(parent,idx);
			break;
		}
	}
}

void Range::setStartAfter(Node* refNode) {

	Node* parent = refNode->GetParentNode();
	if(!parent) {
		//TODO: throw InvalidNodeTypeError
		return;
	}

	NodeList& childs = parent->GetChildNodes();
	for(size_t idx = 0; idx < childs.GetLength(); idx++) {
		if(childs.GetItem(idx) == refNode){
			setStart(parent,idx+1);
			break;
		}
	}
}

void Range::setEndBefore(Node* refNode) {

	Node* parent = refNode->GetParentNode();
	if(!parent) {
		//TODO: throw InvalidNodeTypeError
		return;
	}

	NodeList& childs = parent->GetChildNodes();
	for(size_t idx = 0; idx < childs.GetLength(); idx++) {
		if(childs.GetItem(idx) == refNode){
			setEnd(parent,idx);
			break;
		}
	}
}

void Range::setEndAfter(Node* refNode) {

	Node* parent = refNode->GetParentNode();
	if(!parent) {
		//TODO: throw InvalidNodeTypeError
		return;
	}

	NodeList& childs = parent->GetChildNodes();
	for(size_t idx = 0; idx < childs.GetLength(); idx++) {
		if(childs.GetItem(idx) == refNode){
			setEnd(parent,idx+1);
			break;
		}
	}
}

void Range::selectNode(Node* refNode) {

	Node* parent = refNode->GetParentNode();
	if(!parent) {
		//TODO: throw InvalidNodeTypeError
		return;
	}

	NodeList& childs = parent->GetChildNodes();
	for(size_t idx = 0; idx < childs.GetLength(); idx++) {
		if(childs.GetItem(idx) == refNode){
			setStart(parent,idx);
			setEnd(parent,idx+1);
			break;
		}
	}
}

void Range::selectNodeContents(Node* refNode) {

	if(refNode->GetNodeType() == Node::DOCUMENT_TYPE_NODE) {
		//TODO: throw InvalidNodeTypeError
		return;
	}

	setStart(refNode,0);
	setEnd(refNode,refNode->GetChildNodes().GetLength());
}

void Range::collapse(bool toStart) {
	if(toStart)
		setEnd(start.container,start.offset);
	else
		setStart(end.container,end.offset);
}

Node* Range::GetCommonAncestorContainer() {

	//TODO: check if this really does what it's supposed to do ;)
	//TODO: use TreeWalker for this..  TreeWalker::parentNode()...
	Node* container = start.container;
	for(;container != 0; container = container->GetParentNode()) {

		if(container->GetParentNode() == end.container || container->contains(end.container)) {
			break;
		}
	}
	return container;
}

}
