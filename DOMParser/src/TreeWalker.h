/**
 *
 * @file TreeWalker.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "Traverser.h"
#include "NodeFilter.h"

namespace domparser {
	class Node;

class TreeWalker : public domparser::Traverser {

	friend class Document;

private:
	enum ChildType {
		FIRST,
		LAST,
	};

	enum SiblingType {
		PREVIOUS,
		NEXT,
	};

private:
	TreeWalker(Node* root, NodeFilter::Type whatToShow, NodeFilter* filter);
public:
	virtual ~TreeWalker();

	Node* parentNode();
	Node* previousNode();
	Node* nextNode();

	Node* firstChild() { return TraverseChildren(FIRST); }
	Node* lastChild() { return TraverseChildren(LAST); }

	Node* previousSibling() { return TraverseSiblings(PREVIOUS); }
	Node* nextSibling() { return TraverseSiblings(NEXT); }

	Node* GetCurrentNode() { return currentNode; }
	void SetCurrentNode(Node* cur) { currentNode = cur; }

private:
	Node* TraverseChildren(const ChildType type);
	Node* TraverseChildrenSubstep(Node* node, const ChildType type);
	Node* TraverseChildrenInnerSubstep(Node* node, const ChildType type);

	Node* TraverseSiblings(const SiblingType type);
	Node* TraverseSiblingsSubstep(Node* node, const SiblingType type);
	Node* TraverseSiblingsInnerSubstep(Node* node, Node** pSibling, const SiblingType type);

	Node* NextNodeSubstep(Node* node,NodeFilter::Result& result);

private:
	Node* currentNode;
};

}
