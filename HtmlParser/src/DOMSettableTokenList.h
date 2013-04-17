/**
 *
 * @file DOMSettableTokenList.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "DOMTokenList.h"

namespace htmlparser {

class DOMSettableTokenList : public DOMTokenList {
public:
	DOMSettableTokenList();
	virtual ~DOMSettableTokenList();
};

}
