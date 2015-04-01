/**
 *
 * @file src/Range.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <list>

namespace domparser {
	class Document;
	class Node;

class Range {
public:
	enum RangeType {
		START_TO_START = 0,
		START_TO_END = 1,
		END_TO_END = 2,
		END_TO_START = 3,
	};

	enum BoundaryPointPosition {
		BEFORE = -1,
		EQUAL = 0,
		AFTER = 1,
	};

private:
	struct BoundaryPoint {

		BoundaryPoint()
		: container(0)
		, offset(0)
		{}

		BoundaryPoint(Node* container,unsigned long offset)
		: container(container)
		, offset(offset)
		{}

	private:
		bool operator== (const BoundaryPoint& rhs) const {
			//Cannot compare BoundaryPoints directly
			//use Range class...
			throw;
		}

	public:
		Node* container;
		unsigned long offset;
	};

	enum RangePos {
		START,
		END,
	};

public:
	Range(Node* context, unsigned long offset);
	virtual ~Range();

public:
	void setStart(Node* refNode, unsigned long offset) { SetBoundaryPoint(START, refNode, offset); }
	void setEnd(Node* refNode, unsigned long offset) { SetBoundaryPoint(END, refNode, offset); }
	void setStartBefore(Node* refNode);
	void setStartAfter(Node* refNode);
	void setEndBefore(Node* refNode);
	void setEndAfter(Node* refNode);
	void selectNode(Node* refNode);
	void selectNodeContents(Node* refNode);
	void collapse(bool toStart);

	/*
	void deleteContents();
	DocumentFragment* extractContents();
	DocumentFragment* cloneContents();
	void insertNode(Node* node);
	void surroundContents(Node* newParent);

	Range* cloneRange();
	void detach();

	bool isPointInRange(Node* node, unsigned long offset);
	*/
	BoundaryPointPosition compareBoundaryPoints(RangeType how, Range* sourceRange);
	BoundaryPointPosition comparePoint(Node* node, unsigned long offset);
	//bool intersectsNode(Node* node);

public:
	Node* GetStartContainer() { return start.container; }
	unsigned long GetStartOffset() const { return start.offset; }
	Node* GetEndContainer() { return end.container; }
	unsigned long GetEndOffset() const { return end.offset; }
	bool GetCollapsed() { return (compareBoundaryPoints(START_TO_END, this) == EQUAL); }
	Node* GetCommonAncestorContainer();

public:
	static std::list<Range*>& GetRanges() { return ranges; }

private:
	void RegisterRange();
	void UnregisterRange();

	void SetBoundaryPoint(const RangePos pos, Node* node, unsigned long offset);

private:
	BoundaryPoint start;
	BoundaryPoint end;

private:
	static BoundaryPointPosition ComparePoints(BoundaryPoint& a, BoundaryPoint& b);
	static BoundaryPointPosition ComparePoints(Node* nodeA, unsigned long offsetA, Node* nodeB, unsigned long offsetB);

private:
	static std::list<Range*> ranges;
};

}
