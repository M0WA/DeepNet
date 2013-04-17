/**
 *
 * @file TreeWalker.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "TreeWalker.h"

#include "Document.h"
#include "Node.h"
#include "NodeIterator.h"

namespace htmlparser {

TreeWalker::TreeWalker(Node* root, NodeFilter::Type whatToShow, NodeFilter* filter)
: Traverser(root, whatToShow, filter)
{
	SetCurrentNode(root);
}

TreeWalker::~TreeWalker() {
}

Node* TreeWalker::parentNode() {

	Node* node = GetCurrentNode();

	while( node != 0 && node != GetRoot() ) {
		node = node->GetParentNode();
		if( node && (FilterNode(node) == NodeFilter::FILTER_ACCEPT) ) {
			SetCurrentNode(node);
			return node; }
	}
	return 0;
}

Node* TreeWalker::TraverseChildren(const ChildType type) {

	Node* node = GetCurrentNode();
	while(node) {
		node = TraverseChildrenSubstep(node, type);
	}
	return node;
}

Node* TreeWalker::TraverseChildrenSubstep(Node* node, const ChildType type) {

	NodeFilter::Result result = FilterNode(node);
	switch(result) {

	case NodeFilter::FILTER_ACCEPT:
		SetCurrentNode(node);
		return node;

	case NodeFilter::FILTER_SKIP:
		if(node->GetChildNodes().GetLength()) {

			switch(type) {

			case FIRST:
				node = node->GetChildNodes().GetItem(0);
				break;

			case LAST:
				node = node->GetChildNodes().GetItem( node->GetChildNodes().GetLength() - 1 );
				break;
			}
		}
		break;

	default:
		break;
	}

	node = TraverseChildrenSubstep(node, type);

	while(node) {
		node = TraverseChildrenInnerSubstep(node, type);
	}
	return node;
}

Node* TreeWalker::TraverseChildrenInnerSubstep(Node* node, const ChildType type) {

	Node* sibling = 0;
	switch(type) {

	case FIRST:
		sibling = node->GetNextSibling();
		break;

	case LAST:
		sibling = node->GetPreviousSibling();
		break;
	}

	if(sibling)
		return sibling;

	Node* parentTmp = node->GetParentNode();
	if( !parentTmp ||
		parentTmp == GetRoot() ||
		parentTmp == GetCurrentNode() )
		return 0;

	return parentTmp;
}

Node* TreeWalker::TraverseSiblings(const SiblingType type) {

	Node* node = GetCurrentNode();
	if(GetRoot() == node)
		return 0;

	return TraverseSiblingsSubstep(node, type);
}

Node* TreeWalker::TraverseSiblingsSubstep(Node* node, const SiblingType type) {

	Node* sibling = 0;
	switch(type) {

	case NEXT:
		sibling = node->GetNextSibling();
		break;

	case PREVIOUS:
		sibling = node->GetPreviousSibling();
		break;
	}

	while(sibling) {
		node = TraverseSiblingsInnerSubstep(node, &sibling, type);
	}

	node = node->GetParentNode();
	if( !node || node == GetRoot() )
		return 0;

	if( FilterNode(node) == NodeFilter::FILTER_ACCEPT )
		return 0;

	return TraverseSiblingsSubstep(node, type);
}

Node* TreeWalker::TraverseSiblingsInnerSubstep(Node* node, Node** pSibling, const SiblingType type) {

	node = *pSibling;
	NodeFilter::Result result = FilterNode(node);
	if(result == NodeFilter::FILTER_ACCEPT) {
		SetCurrentNode(node);
		return node;
	}

	switch(type) {

	case NEXT:
		*pSibling = node->GetFirstChild();
		break;

	case PREVIOUS:
		*pSibling = node->GetLastChild();
		break;
	}

	if( result == NodeFilter::FILTER_REJECT ||
		*pSibling == 0 ) {

		switch(type) {

		case NEXT:
			*pSibling = node->GetNextSibling();
			break;

		case PREVIOUS:
			*pSibling = node->GetPreviousSibling();
			break;
		}
	}

	return node;
}

Node* TreeWalker::previousNode() {

	Node* node = GetCurrentNode();
	while(node != GetRoot()) {

		Node* sibling = node->GetPreviousSibling();
		while(sibling) {

			node = sibling;
			NodeFilter::Result result = FilterNode(node);

			while( result != NodeFilter::FILTER_REJECT &&
				   node->GetChildNodes().GetLength() ) {

				node = node->GetLastChild();
				result = FilterNode(node);
			}

			if(result == NodeFilter::FILTER_ACCEPT) {
				SetCurrentNode(node);
				break;
			}
		}

		if(node == GetRoot() || !node->GetParentNode() ) {
			node = 0;
			break; }

		node = node->GetParentNode();
		if( FilterNode(node) == NodeFilter::FILTER_ACCEPT ) {
			SetCurrentNode(node);
			break;
		}
	}

	return node;
}

Node* TreeWalker::nextNode() {

	Node* node = GetCurrentNode();
	NodeFilter::Result result = NodeFilter::FILTER_ACCEPT;
	return NextNodeSubstep(node,result);
}

Node* TreeWalker::NextNodeSubstep(Node* node,NodeFilter::Result& result) {

	while(result != NodeFilter::FILTER_REJECT &&
		  node->GetChildNodes().GetLength() ) {
		node = node->GetFirstChild();
		NodeFilter::Result result = FilterNode(node);
		if(result == NodeFilter::FILTER_ACCEPT) {
			SetCurrentNode(node);
			return node;
		}
	}

	//TODO: check if code beyond does:
	//If a node is following node and is not following root, set node to the first such node
	FollowNodeNotFollowRootFilter testFilter(root, node);
	NodeIterator iterNode = node->GetOwnerDocument()->createNodeIterator(node, NodeFilter::SHOW_ALL, &testFilter);
	node = iterNode.nextNode();
	if(!node)
		return 0;

	result = FilterNode(node);
	if(result == NodeFilter::FILTER_ACCEPT) {
		SetCurrentNode(node);
		return node;
	}

	return NextNodeSubstep(node,result);
}

}
