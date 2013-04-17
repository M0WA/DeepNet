/**
 *
 * @file DocumentFragment.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "Node.h"

namespace htmlparser {

class DocumentFragment: public htmlparser::Node {
public:
	DocumentFragment(Document* ownerDocument);
	virtual ~DocumentFragment();
};

}
