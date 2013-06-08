/**
 *
 * @file Node.h
 * @author Moritz Wagner
 * @date 03.03.2013
 *
 */

#pragma once

#include <string>

#include "DOMTypes.h"
#include "NodeList.h"
#include "EventTarget.h"
#include "MutationObserver.h"

namespace domparser {
	class Element;
	class Document;
	class DatabaseUrl;

/**
 * @brief basic implementation of a DOM compatible node
 */
class Node : public EventTarget {

	friend class NodeFactory;

public:
	/**
	 * @enum NodeType
	 * specific type node
	 */
	enum NodeType {
		INVALID_NODE_TYPE,
		ELEMENT_NODE = 1,
//		ATTRIBUTE_NODE = 2, // historical
		TEXT_NODE = 3,
//		CDATA_SECTION_NODE = 4, // historical
//		ENTITY_REFERENCE_NODE = 5, // historical
//		ENTITY_NODE = 6, // historical
		PROCESSING_INSTRUCTION_NODE = 7,
		COMMENT_NODE = 8,
		DOCUMENT_NODE = 9,
		DOCUMENT_TYPE_NODE = 10,
		DOCUMENT_FRAGMENT_NODE = 11,
//		NOTATION_NODE = 12, // historical
	};

	/**
	 * @enum DocumentPosition
	 * describes relationship of two nodes
	 */
	enum DocumentPosition {
		DOCUMENT_POSITION_EQUAL = 0x00, //non standard value but used in standard...

		DOCUMENT_POSITION_DISCONNECTED = 0x01,
		DOCUMENT_POSITION_PRECEDING = 0x02,
		DOCUMENT_POSITION_FOLLOWING = 0x04,
		DOCUMENT_POSITION_CONTAINS = 0x08,
		DOCUMENT_POSITION_CONTAINED_BY = 0x10,
		DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 0x20,
	};

protected:
	/**
	 * constructs a node from a parent document and it's type
	 * @param ownerDocument parent document of this node
	 * @param type type of this node
	 * @see domparser::Node::NodeType
	 */
	Node(Document* ownerDocument, NodeType type);

public:
	virtual ~Node();

	/**
	 * checks if this node has child nodes
	 * @return true if it has, false if not
	 */
	bool hasChildNodes() const { return childNodes.GetLength() > 0; }

	/**
	 * insert a node before another
	 * @param node node to insert before
	 * @param child new node to insert
	 * @return inserted node
	 */
	Node* insertBefore(Node* node, Node* child);

	/**
	 * appends node as a child to a certain node
	 * @param node node to append
	 * @return inserted node
	 */
	Node* appendChild(Node* node);

	/**
	 * replace a child node with another
	 * @param node node to insert
	 * @param child node to replace
	 * @return replaced node
	 */
	Node* replaceChild(Node* node, Node* child);

	/**
	 * removes a child node
	 * @param child node to remove
	 * @return remove node
	 */
	Node* removeChild(Node* child);

	/**
	 * normalize DOM tree
	 */
	void normalize();

	/**
	 * clones this node, optionally including all children
	 * @param deep if set to true, all children are cloned also
	 * @return cloned node
	 */
	Node* cloneNode(bool deep = true);

	/**
	 * compare two nodes for equality
	 * @param node node to compare to
	 * @return true if node is equal
	 */
	bool isEqualNode(Node* node);

	/**
	 * compares position of two DOM nodes
	 * @param other node to compare to
	 * @return relationship of two nodes
	 */
	DocumentPosition compareDocumentPosition(Node* other);

	/**
	 * checks if a node is a child node of this node
	 * @param other node to check for
	 * @return true if it is child, false if not
	 */
	bool contains(Node* other);

	DOMStringPtr lookupPrefix(const DOMString& nameSpace);
	DOMStringPtr lookupNamespaceURI(const DOMString& prefix);
	bool isDefaultNamespace(const DOMString& nameSpace);

public:
	Node::NodeType  GetNodeType() const { return nodeType; }
	DOMString       GetNodeName() const;
	NodeList& 	    GetChildNodes() { return childNodes; }
	Node*           GetParentNode() { return 0; }
	Node*			GetFirstChild() { return 0; }
	Node*			GetLastChild()  { return 0; }
	Node*			GetPreviousSibling() { return 0; }
	Node*			GetNextSibling() { return 0; }
	Document*       GetOwnerDocument();
	const DOMString* GetNodeValue() const;
	DOMStringPtr 	 GetTextContent() const;

	void SetNodeValue(const DOMString& value);
	void SetTextContent(const DOMString& value);

	void RegisterObserver(const MutationObserver& observer);

public:
	static void QueueMutationRecord(const MutationRecord& record);

private:
	virtual void OnNodeInserted(Node*) {}
	virtual void OnNodeRemoved(Node*) {}

protected:
	Node* doPreInsert(Node* node, Node* child);
	Node* doInsert(Node* node, Node* child, bool supressObservers = false);

	Node* doPreRemoveChild(Node* child);
	Node* doRemoveChild(Node* child, bool supressObservers = false);

	bool doGetChildIdx(Node* node,size_t& pos);

protected:
	//changed also by Document::adoptNode
	Document* ownerDocument;

private:
	DatabaseUrl* baseURI;
	Node::NodeType nodeType;

	//Node* parentNode;
	//Element* parentElement;

	NodeList childNodes;

	/*
	Node* firstChild;
	Node* lastChild;
	Node* previousSibling;
	Node* nextSibling;
	*/

	DOMStringPtr nodeValue;
	DOMStringPtr textContent;

	std::vector<MutationObserver> registeredObservers;
};

}
