/**
 *
 * @file OpenElementStack.h
 * @author Moritz Wagner
 * @date 22.06.2013
 *
 */

#pragma once

#include <Stack.h>

namespace domparser {

namespace dom3 {
	class Node;
}

namespace html5 {

class OpenElementStack: public tools::Stack<domparser::dom3::Node*> {
public:
	OpenElementStack();
	virtual ~OpenElementStack();
};

}

}
