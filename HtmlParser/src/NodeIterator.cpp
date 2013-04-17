/**
 *
 * @file NodeIterator.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "NodeIterator.h"

namespace htmlparser {

NodeIterator::NodeIterator(Node* root, NodeFilter::Type whatToShow, NodeFilter* filter)
: Traverser(root, whatToShow, filter)
, referenceNode(root)
, pointerBeforeReferenceNode(true){
}

NodeIterator::~NodeIterator() {
}

Node* NodeIterator::Traverse(const Direction dir) {

	Node* node = referenceNode;
	bool beforeNode = pointerBeforeReferenceNode;

	node = TraverseSubstep(dir, node, beforeNode);

	pointerBeforeReferenceNode = beforeNode;
	referenceNode = node;
	return node;
}

Node* NodeIterator::TraverseNext(Node* node, bool& beforeNode) {

	if(!beforeNode) {
		//TODO:
	}
	else {
		beforeNode = false;
	}
	return node;
}

Node* NodeIterator::TraversePrevious(Node* node, bool& beforeNode) {

	if(beforeNode) {
		//TODO:
	}
	else {
		beforeNode = true;
	}
	return node;
}

Node* NodeIterator::TraverseSubstep(const Direction dir, Node* node, bool& beforeNode){

	switch(dir) {

	case NEXT:
		node = TraverseNext(node, beforeNode);
		break;

	case PREVIOUS:
		node = TraversePrevious(node, beforeNode);
		break;
	}

	NodeFilter::Result result = FilterNode(node);
	if(result == NodeFilter::FILTER_ACCEPT)
		return node;
	else
		return TraverseSubstep(dir, node, beforeNode);
}

}
