/**
 *
 * @file src/NodeFilter.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

namespace domparser {
	class Node;

class NodeFilter {
public:
	enum Result {
		FILTER_ACCEPT = 1,
		FILTER_REJECT = 2,
		FILTER_SKIP = 3,
	};

	enum Type {
		SHOW_ALL = 0xFFFFFFFF,
		SHOW_ELEMENT = 0x1,
		SHOW_ATTRIBUTE = 0x2, // historical
		SHOW_TEXT = 0x4,
		SHOW_CDATA_SECTION = 0x8, // historical
		SHOW_ENTITY_REFERENCE = 0x10, // historical
		SHOW_ENTITY = 0x20, // historical
		SHOW_PROCESSING_INSTRUCTION = 0x40,
		SHOW_COMMENT = 0x80,
		SHOW_DOCUMENT = 0x100,
		SHOW_DOCUMENT_TYPE = 0x200,
		SHOW_DOCUMENT_FRAGMENT = 0x400,
		SHOW_NOTATION = 0x800, // historical
	};

protected:
	NodeFilter();
public:
	virtual ~NodeFilter();

public:
	virtual NodeFilter::Result acceptNode(Node* node)=0;
};

class FollowFilter : public domparser::NodeFilter {
public:
	FollowFilter(Node* parent);
	virtual ~FollowFilter();

public:
	virtual NodeFilter::Result acceptNode(Node* node);

private:
	Node* parent;
};

class FollowNodeNotFollowRootFilter : public domparser::FollowFilter {
public:
	FollowNodeNotFollowRootFilter(Node* root,Node* checkNode);
	virtual ~FollowNodeNotFollowRootFilter();

public:
	virtual NodeFilter::Result acceptNode(Node* node);

private:
	Node* root;
};

}
