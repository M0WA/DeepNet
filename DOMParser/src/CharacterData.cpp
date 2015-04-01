/**
 *
 * @file CharacterData.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "CharacterData.h"

namespace domparser {

CharacterData::CharacterData(Document* ownerDocument, Node::NodeType type)
: Node(ownerDocument, type)
, data(0) {
}

CharacterData::~CharacterData() {
}

DOMString CharacterData::substringData(unsigned long offset, unsigned long count) {
	return (*data).substr(offset,count);
}

void CharacterData::appendData(const DOMString& append) {
	(*data).append(append);
}

void CharacterData::insertData(unsigned long offset, const DOMString& insert) {
	(*data).insert(offset,insert);
}

void CharacterData::deleteData(unsigned long offset, unsigned long count) {
	(*data).erase(offset,count);
}

void CharacterData::replaceData(unsigned long offset, unsigned long count, const DOMString& replace) {
	(*data).replace(offset, count, replace);
}


}
