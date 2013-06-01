/**
 *
 * @file CharacterData.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "Node.h"
#include "DOMTypes.h"

namespace domparser {

class CharacterData : public Node {
public:
	CharacterData(Document* ownerDocument, Node::NodeType type);
	virtual ~CharacterData();

	DOMString substringData(unsigned long offset, unsigned long count);
	void appendData(const DOMString& append);
	void insertData(unsigned long offset, const DOMString& insert);
	void deleteData(unsigned long offset, unsigned long count);
	void replaceData(unsigned long offset, unsigned long count, const DOMString& replace);

	unsigned long GetLength() {
		if(data.IsNull())
			return 0;
		return (*data).length();
	}

	const DOMString* GetData() const { return data; }

protected:
	DOMStringPtr data;
};

}
