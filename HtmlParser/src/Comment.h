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

/**
 * @brief wraps html comments
 */
class Comment: public CharacterData {
public:
	/**
	 * construct a comment from an owning document
	 */
	Comment(Document* ownerDocument);
	virtual ~Comment();
};

}
