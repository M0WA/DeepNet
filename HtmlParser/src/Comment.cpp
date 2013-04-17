/**
 *
 * @file Comment.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "Comment.h"

namespace htmlparser {

Comment::Comment(Document* ownerDocument)
: CharacterData(ownerDocument,COMMENT_NODE){
}

Comment::~Comment() {
}

}
