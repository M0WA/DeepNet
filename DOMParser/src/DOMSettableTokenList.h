/**
 *
 * @file src/DOMSettableTokenList.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "DOMTokenList.h"

namespace domparser {

class DOMSettableTokenList : public DOMTokenList {
public:
	DOMSettableTokenList();
	virtual ~DOMSettableTokenList();
};

}
