/**
 *
 * @file Text.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "Text.h"

namespace htmlparser {

Text::Text(Document* ownerDocument)
: CharacterData(ownerDocument,TEXT_NODE){
}

Text::~Text() {
}

Text Text::splitText(unsigned long offset) {
	return Text( GetOwnerDocument() );
}

}
