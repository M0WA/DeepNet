/**
 *
 * @file TreeConstructionContext.cpp
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#include "TreeConstructionContext.h"

namespace domparser {

namespace html5 {

TreeConstructionContext::TreeConstructionContext()
: insertionMode(initial)
, orgInsertionMode(initial){
}

TreeConstructionContext::~TreeConstructionContext() {
}

void TreeConstructionContext::SwitchMode(const TreeConstructionContext::InsertionMode newMode) {

	switch(newMode)
	{
	case text:
	case in_table_text:
		orgInsertionMode = newMode;
		break;

	default:
		break;
	}

	insertionMode = newMode;
}

}

}
