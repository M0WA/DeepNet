/**
 *
 * @file DocumentType.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "DocumentType.h"

namespace domparser {

DocumentType::DocumentType(Document* ownerDocument)
: Node(ownerDocument,DOCUMENT_TYPE_NODE){
}

DocumentType::~DocumentType() {
}

}
