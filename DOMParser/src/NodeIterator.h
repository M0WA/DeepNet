/**
 *
 * @file NodeIterator.h
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

class NodeIterator : public domparser::Traverser {
	friend class Document;

private:
	enum Direction {
		NEXT,
		PREVIOUS,
	};

private:
	NodeIterator(Node* root, NodeFilter::Type whatToShow, NodeFilter* filter);
public:
	virtual ~NodeIterator();

public:
	Node* nextNode()     { return Traverse(NEXT); }
	Node* previousNode() { return Traverse(PREVIOUS); }

	void detach() { }

	Node* GetReferenceNode() { return referenceNode; }
	bool IsPointerBeforeReferenceNode() const { return pointerBeforeReferenceNode; }

private:
	Node* Traverse(const Direction dir);
	Node* TraverseNext(Node* node, bool& beforeNode);
	Node* TraversePrevious(Node* node, bool& beforeNode);
	Node* TraverseSubstep(const Direction dir, Node* node, bool& beforeNode);

private:
	Node* referenceNode;
	bool pointerBeforeReferenceNode;
};

}
