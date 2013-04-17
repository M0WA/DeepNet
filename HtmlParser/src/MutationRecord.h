/**
 *
 * @file MutationRecord.h
 * @author Moritz Wagner
 * @date Mar 6, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "DOMTypes.h"
#include "NodeList.h"

namespace htmlparser {
	class Node;

class MutationRecord {
public:
	MutationRecord();
	virtual ~MutationRecord();

public:
	DOMString type;
	Node* target;
	NodeList addedNodes;
	NodeList removedNodes;
	Node* previousSibling;
	Node* nextSibling;
	DOMStringPtr attributeName;
	DOMStringPtr attributeNamespace;
	DOMStringPtr oldValue;
};

}
