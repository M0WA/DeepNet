/**
 *
 * @file NodeFilter.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "NodeFilter.h"

#include "Node.h"

namespace domparser {

NodeFilter::NodeFilter() {
}

NodeFilter::~NodeFilter() {
}

FollowFilter::FollowFilter(Node* parent)
: NodeFilter()
, parent(parent) {
}

FollowFilter::~FollowFilter() {
}

FollowNodeNotFollowRootFilter::FollowNodeNotFollowRootFilter(Node* root,Node* checkNode)
: FollowFilter(checkNode)
, root(root) {
}

FollowNodeNotFollowRootFilter::~FollowNodeNotFollowRootFilter() {
}

NodeFilter::Result FollowFilter::acceptNode(Node* node) {

	if( (parent->compareDocumentPosition(node) & Node::DOCUMENT_POSITION_FOLLOWING) != Node::DOCUMENT_POSITION_FOLLOWING ) {
		return NodeFilter::FILTER_REJECT;
	}

	return NodeFilter::FILTER_ACCEPT;
}

NodeFilter::Result FollowNodeNotFollowRootFilter::acceptNode(Node* node) {

	if( (root->compareDocumentPosition(node) & Node::DOCUMENT_POSITION_FOLLOWING) > 0 ) {
		return NodeFilter::FILTER_REJECT;
	}

	return FollowFilter::acceptNode(node);

}

}
