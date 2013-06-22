/**
 *
 * @file DocumentFragment.h
 * @author Moritz Wagner
 * @date 22.06.2013
 *
 */

#pragma once

#include "Node.h"

namespace domparser {

namespace dom3 {

class DocumentFragment: public domparser::dom3::Node {
public:
	DocumentFragment();
	virtual ~DocumentFragment();
};

}

}
