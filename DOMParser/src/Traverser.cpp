/**
 *
 * @file Traverser.cpp
 * @author Moritz Wagner
 * @date Mar 6, 2013
 *
 * TODO: description for this file
 *
 */

#include "Traverser.h"

#include <stddef.h>

#include "Node.h"

namespace domparser {

Traverser::Traverser(Node* root, NodeFilter::Type whatToShow, NodeFilter* filter)
: root(root)
, whatToShow(whatToShow)
, filter(filter)
, activeFlag(false){
}

Traverser::~Traverser() {
}

NodeFilter::Result Traverser::FilterNode(Node* node) {

	if(activeFlag) {
		//TODO: throw InvalidStateError
		return NodeFilter::FILTER_SKIP;
	}

	size_t typeNumeric = static_cast<size_t>(node->GetNodeType()) - 1;
	bool match = typeNumeric && whatToShow;
	if(!match)
		return NodeFilter::FILTER_SKIP;

	if( filter.IsNull() )
		return NodeFilter::FILTER_ACCEPT;

	NodeFilter::Result result = NodeFilter::FILTER_SKIP;
	activeFlag = true;
	try {
		result = (*filter).acceptNode(node);
	}
	catch(...) {
		activeFlag = false;
		throw;

	}
	activeFlag = false;
	return result;
}

}
