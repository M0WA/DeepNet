/**
 *
 * @file ProcessingInstruction.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "ProcessingInstruction.h"

namespace domparser {

ProcessingInstruction::ProcessingInstruction(Document* ownerDocument, const DOMString& target)
: CharacterData(ownerDocument,PROCESSING_INSTRUCTION_NODE)
, target(target){
}

ProcessingInstruction::~ProcessingInstruction() {
}

}
