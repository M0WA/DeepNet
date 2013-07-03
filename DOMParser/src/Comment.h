/**
 *
 * @file src/Comment.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 */

#pragma once

#include "CharacterData.h"

namespace domparser {

class Document;

/**
 * @brief wrapper class for character data specified as a commentary
 * @see domparser::Document::createComment
 */
class Comment: public CharacterData {
public:
	/**
	 * constructs comment node with an owning document
	 * @param ownerDocument document owning this node
	 *
	 * @see domparser::Node and domparser::CharacterData
	 */
	Comment(Document* ownerDocument);
	virtual ~Comment();
};

}
