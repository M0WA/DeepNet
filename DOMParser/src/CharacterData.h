/**
 *
 * @file CharacterData.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 */

#pragma once

#include "Node.h"
#include "DOMTypes.h"

namespace domparser {

/**
 * @brief this class implements an dom node
 */
class CharacterData : public Node {
public:
	/**
	 * constructs a node with an owning document and a corresponding node
	 * type
	 */
	CharacterData(Document* ownerDocument, Node::NodeType type);
	virtual ~CharacterData();

	/**
	 * gets a substring of this node character data.
	 * please note that the returned data is already
	 * zero terminated.
	 * @param offset start offset
	 * @param count number of characters to return
	 * @return returns specfied character data
	 */
	DOMString substringData(unsigned long offset, unsigned long count);

	/**
	 * appends data/characters to this node
	 * @param append data to append
	 */
	void appendData(const DOMString& append);

	/**
	 * insert data/characters at a specified place
	 * @param offset insert position
	 * @param insert string/data to insert
	 */
	void insertData(unsigned long offset, const DOMString& insert);

	/**
	 * deletes data from this character node
	 * @param offset deletes data/characters from this node
	 * @param count number of characters to delete
	 */
	void deleteData(unsigned long offset, unsigned long count);

	/**
	 * replace data in this character node
	 * @param offset where to start deleting
	 * @param count number of characters to delete
	 * @param replace replace by this string
	 */
	void replaceData(unsigned long offset, unsigned long count, const DOMString& replace);

	/**
	 * returns the number of characters contained
	 * in this node, NOT it's size !!!
	 * @return number of characters
	 */
	unsigned long GetLength() {
		if(data.IsNull())
			return 0;
		return (*data).length();
	}

	/**
	 * get const raw data from this node
	 */
	const DOMString* GetData() const { return data; }

protected:
	DOMStringPtr data;
};

}
