/**
 *
 * @file DocumentFragment.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "DocumentFragment.h"

namespace htmlparser {

DocumentFragment::DocumentFragment(Document* ownerDocument)
: Node(ownerDocument,DOCUMENT_FRAGMENT_NODE){
}

DocumentFragment::~DocumentFragment() {
}

}
