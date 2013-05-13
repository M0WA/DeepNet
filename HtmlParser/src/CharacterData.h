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

namespace htmlparser {

/**
 * @brief class containing character data from a certain node
 */
class CharacterData : public Node {
public:
	/**
	 * construct CharacterData using an owning document and it's containing node type.
	 * @param ownerDocument owning document of the node
	 * @param type type of the node, see Node::NodeType
	 */
	CharacterData(Document* ownerDocument, Node::NodeType type);
	virtual ~CharacterData();

	/**
	 * returns a substring of the containing string using offset and length.
	 * @param offset where to begin copying of the string
	 * @param count number of characters to be copied
	 */
	DOMString substringData(unsigned long offset, unsigned long count);

	/**
	 * appends characters to the end of the contained string
	 * @param append string to append
	 */
	void appendData(const DOMString& append);

	/**
	 * insert a string at a certain position.
	 * @param offset insert after offset characters
	 * @param insert string to insert
	 */
	void insertData(unsigned long offset, const DOMString& insert);

	/**
	 * deletes a certain number of characters from the contained string
	 * @param offset index where to start deleting
	 * @param count number of characters to delete
	 */
	void deleteData(unsigned long offset, unsigned long count);

	/**
	 * replaces a certain amount of string  in the contained string.
	 * please note that number specified in count is only used to
	 * delete a certain number of characters. even if the count is not
	 * equal to the string length of replace.
	 * @param offset index where to start replacing
	 * @param count number of characters to be replaced
	 * @param replace string to insert/replace
	 */
	void replaceData(unsigned long offset, unsigned long count, const DOMString& replace);

	/**
	 * returns the length of the containing string
	 */
	unsigned long GetLength() const {
		if(data.IsNull())
			return 0;
		return (*data).length();
	}

	/**
	 * return pointer to the raw data of the containing string
	 */
	const DOMStringPtr GetData() const { return data; }

protected:
	DOMStringPtr data;
};

}
