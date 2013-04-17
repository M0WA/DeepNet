/**
 * @file Stack.h
 * @author Moritz Wagner
 * @date 15.11.2012
 */

#pragma once

#include <vector>
#include <stdexcept>

#include "StdException.h"

namespace tools {

/**
 * @brief generic implementation of a stack
 */
template <typename T>
class Stack {
private:
	template<class W>
	class StackNode {
	public:
		StackNode(W* node, bool deleteOnDestruct)
		: node(node)
		, deleteOnDestruct(deleteOnDestruct)  {}

		~StackNode() {}

		W* node;
		bool deleteOnDestruct;
	};

public:
	/**
	 * create empty stack.
	 */
	Stack()
	{}

	~Stack() {
		typename std::vector< StackNode<T> >::const_iterator iter = items.begin();
		for(;iter != items.end(); ++iter) {
			if( iter->deleteOnDestruct ) {
				delete iter->node; }
		}
		items.clear();
	}

	Stack(const Stack &rhs) {
		typename std::vector< StackNode<T> >::const_iterator iterRhs = rhs.items.begin();
		for(;iterRhs != rhs.items.end(); ++iterRhs) {
			T* tmpNode = iterRhs->node;
			if(iterRhs->deleteOnDestruct) {
				tmpNode = new T(*tmpNode); }
			StackNode<T> node( tmpNode, iterRhs->deleteOnDestruct );
			Push(*iterRhs);
		}
	}

	Stack& operator=(const Stack &rhs) {
		typename std::vector< StackNode<T> >::const_iterator iterRhs = rhs.items.begin();
		for(;iterRhs != rhs.items.end(); ++iterRhs) {
			T* tmpNode = iterRhs->node;
			if(iterRhs->deleteOnDestruct) {
				tmpNode = new T(*tmpNode); }
			StackNode<T> node( tmpNode, iterRhs->deleteOnDestruct );
			Push(*iterRhs);
		}
		return *this;
	}

	/**
	 * push value to stack not copying and not deleting.
	 * @param value value.
	 */
	void Push(const T* value) {
		items.push_back(StackNode<T>(value,false));
	}

	/**
	 * copy and push value to stack.
	 * @param value value.
	 */
	void Push(const T& value) {
		items.push_back(StackNode<T>(new T(value),true));
	}

	/**
	 * tries to pop value from stack, throws exception if stack is empty.
	 */
	void TryPop() {
		if (Size() == 0) {
			THROW_EXCEPTION(errors::StdException,std::underflow_error("Nothing to pop.")); }
		Pop();
	}

	/**
	 * pop value from stack.
	 */
	void Pop()	{
		if (Size() == 0) {
			return;	}

		if(items.back().deleteOnDestruct)
			delete items.back().node;
		items.pop_back();
	}

	/**
	 * pop value from stack
	 * @return copy of the popped stack value.
	 */
	T PopDump()	{
		if (Size() == 0) {
			THROW_EXCEPTION(errors::StdException,std::underflow_error("Nothing to pop.")); }
		T returnValue = T(*items.back().node);
		Pop();
		return returnValue;
	}

	/**
	 * peek stack.
	 * @return top stack value.
	 */
	T& Peek() {
		return Peek(Size()-1);
	}

	/**
	 * peek stack at position pos.
	 * @param pos position of item
	 * @return stack item.
	 */
	T& Peek(size_t pos) {
		if (Size() <= pos) {
			THROW_EXCEPTION(errors::StdException,std::out_of_range("invalid stack position."));	}
		return *(items.at(pos).node);
	}

	/**
	 * peek top of the stack.
	 * @return top stack value.
	 */
	const T& ConstPeek() const {
		return ConstPeek(Size()-1);
	}

	/**
	 * peek stack at position pos.
	 * @param pos position of item
	 * @return stack item.
	 */
	const T& ConstPeek(size_t pos) const {
		if (Size() <= pos) {
			THROW_EXCEPTION(errors::StdException,std::out_of_range("invalid stack position."));	}
		return *(items.at(pos).node);
	}

	/**
	 * get stack size.
	 * @return stack size.
	 */
	size_t Size() const {
		return items.size();
	}

private:
	std::vector< StackNode<T> > items;
};

}

