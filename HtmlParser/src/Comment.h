/**
 *
 * @file Comment.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "CharacterData.h"

namespace htmlparser {

class Comment: public CharacterData {
public:
	Comment(Document* ownerDocument);
	virtual ~Comment();
};

}
