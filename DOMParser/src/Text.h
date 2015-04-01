/**
 *
 * @file src/Text.h
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

class Text: public CharacterData {
public:
	Text(Document* ownerDocument);
	virtual ~Text();

	Text splitText(unsigned long offset);

	DOMString wholeText;
};

}
