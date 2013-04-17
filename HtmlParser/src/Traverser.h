/**
 *
 * @file Traverser.h
 * @author Moritz Wagner
 * @date Mar 6, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <Pointer.h>
#include "NodeFilter.h"

namespace htmlparser {

class Traverser {
protected:
	Traverser(Node* root, NodeFilter::Type whatToShow, NodeFilter* filter);
public:
	virtual ~Traverser();

public:
	Node* GetRoot() { return root; }
	NodeFilter::Type GetWhatToShow() const { return whatToShow; }
	const NodeFilter* GetFilter() const { return filter; }

protected:
	NodeFilter::Result FilterNode(Node* node);

protected:
	Node* root;
	NodeFilter::Type whatToShow;
	tools::AutoPointer<NodeFilter> filter;
	bool activeFlag;
};

}
