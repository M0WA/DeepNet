/**
 *
 * @file src/DocumentFragment.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 */

#pragma once

#include "Node.h"

namespace domparser {

/**
 * @brief implements a DocumentFragment
 */
class DocumentFragment: public domparser::Node {
public:
	DocumentFragment(Document* ownerDocument);
	virtual ~DocumentFragment();
};

}
