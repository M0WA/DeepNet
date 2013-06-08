/**
 *
 * @file MutationRecord.h
 * @author Moritz Wagner
 * @date 06.03.2013
 *
 */

#pragma once

#include "DOMTypes.h"
#include "NodeList.h"

namespace domparser {
	class Node;

/**
 * @brief contains information about the mutation of a certain node
 */
class MutationRecord {
public:
	MutationRecord();
	virtual ~MutationRecord();

public:
	/**
	 * type of mutation
	 */
	DOMString type;

	/**
	 * node which was changed/mutated
	 */
	Node* target;

	/**
	 * list of nodes added with this mutation
	 */
	NodeList addedNodes;

	/**
	 * list of node removed with this mutation
	 */
	NodeList removedNodes;

	/**
	 * previous sibling of this node (may have changed also)
	 */
	Node* previousSibling;

	/**
	 * next sibling of this node (may have changed also)
	 */
	Node* nextSibling;

	/**
	 * if changed, new attribute, else old attribute name
	 */
	DOMStringPtr attributeName;

	/**
	 * namespace of changed attribute
	 */
	DOMStringPtr attributeNamespace;

	/**
	 * old attribute name
	 */
	DOMStringPtr oldValue;
};

}
