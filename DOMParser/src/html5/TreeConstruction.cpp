/**
 *
 * @file TreeConstruction.cpp
 * @author Moritz Wagner
 * @date 20.06.2013
 *
 */

#include "TreeConstruction.h"

namespace domparser {

namespace html5 {

TreeConstruction::TreeConstruction() {
}

TreeConstruction::~TreeConstruction() {
}

bool TreeConstruction::OnToken(const domparser::generic::Token& token) {
	return false;
}

}

}
