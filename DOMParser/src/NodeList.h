/**
 *
 * @file NodeList.h
 * @author Moritz Wagner
 * @date Mar 3, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "ListImpl.h"

namespace domparser {
	class Node;

class NodeList : public ListImpl<Node> {
public:
	NodeList();
	virtual ~NodeList();
};

}
