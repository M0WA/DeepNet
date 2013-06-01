/**
 *
 * @file ProcessingInstruction.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "DOMTypes.h"
#include "CharacterData.h"

namespace domparser {

class ProcessingInstruction: public CharacterData {
public:
	ProcessingInstruction(Document* ownerDocument,const DOMString& target);
	virtual ~ProcessingInstruction();

	const DOMString& GetTarget() const { return target; }

private:
	DOMString target;
};

}
