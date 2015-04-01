/**
 * @file MemoryContainer.h
 * @author Moritz Wagner
 * @date 20.01.2013
 */

#pragma once

#include <cstdlib>
#include <cstring>

namespace tools {

/**
 * generic wrapper for managed memory.
 */
template <class T>
class MemoryContainer {
public:
	/**
	 * constructs empty container.
	 */
	MemoryContainer() : element(0), elementCount(0), releaseOnDestruct(true) {}

	/**
	 * constructs container and copies initial elements.
	 * @param element initial elements.
	 * @param elementCount number of initial elements.
	 */
	MemoryContainer(const T* element, size_t elementCount) : element(0), elementCount(0), releaseOnDestruct(true) {
		Append(element,elementCount);}

	/**
	 * copy from another memory container.
	 * @param copyFrom container to copy from.
	 */
	MemoryContainer(const MemoryContainer<T>& copyFrom) : element(0), elementCount(0), releaseOnDestruct(true) {
		Append(copyFrom); }

	virtual ~MemoryContainer() {
		Release();
	}

	void operator=(const MemoryContainer<T>& assign) {
		Release();
		Append(assign);
	}

    operator const T*() const {
        return element;
    }

public:
    /**
     * allocates new memory.
     * @param newElementCount number of new elements.
     * @param zeroNewMemory true to zero-initialized memory.
     * @return allocated typed memory.
     */
	T* Allocate(const size_t newElementCount, const bool zeroNewMemory) {

		size_t mallocSize(sizeof(T) * (newElementCount + elementCount));
		if(element) {
			element = (T*)realloc(element,mallocSize );
		}
		else {
			element = (T*)malloc(mallocSize);
		}

		if(!element)
			return 0;

		if(zeroNewMemory)
			memset(&element[elementCount],0,sizeof(T) * newElementCount);

		elementCount += newElementCount;
		return element;
	}

	/**
	 * releases allocated memory.
	 */
	void Release() {

		if(releaseOnDestruct && element)
			free(element);
		element = 0;
		elementCount = 0;
		releaseOnDestruct = true;
	}

	/**
	 * take ownership of another container.
	 * @param own container to take ownership of.
	 */
	void Swap(const MemoryContainer<T>& own) {
		own.releaseOnDestruct = false;

		Release();

		element = own.element;
		elementCount = own.elementCount;
	}

	/**
	 * take ownership of raw memory.
	 * @param own memory to take ownership of.
	 * @param elementCount size of memory.
	 */
	void Swap(T* own, const size_t elementCount) {

		Release();

		this->element = own;
		this->elementCount = elementCount;
	}

	/**
	 * appends complete container.
	 * @param append container to append.
	 * @return first element.
	 */
	T* Append(const MemoryContainer<T>& append) {
		return Append(elementCount,append,0,append.GetCount());
	}

	/**
	 * appends container at a given position.
	 * @param appendAt position to insert at.
	 * @param append container to add.
	 * @return first element.
	 */
	T* Append(const size_t appendAt, const MemoryContainer<T>& append) {
		return Append(appendAt,append,0,append.GetCount());
	}

	/**
	 * appends certain number of elements from an array.
	 * @param append array to append.
	 * @param appendCount number of elements to append.
	 * @return first element.
	 */
	T* Append(const T* append, const size_t& appendCount) {
		return Append(elementCount,append,0,appendCount);
	}

	/**
	 * appends certain number of elements at a certain position.
	 * @param appendAt position to insert at.
	 * @param append elements to append.
	 * @param appendCount number of elements to append.
	 * @return first element.
	 */
	T* Append(const size_t appendAt, const T* append, const size_t appendCount) {
		return Append(appendAt,append,0,appendCount);
	}

	/**
	 * appends certain number of elements from a certain start position at a certain position.
	 * @param appendAt position to insert at.
	 * @param append elements to append.
	 * @param appendStart start position in append.
	 * @param appendCount number of elements to append.
	 * @return first element.
	 */
	T* Append(const size_t appendAt,const T* append, const size_t appendStart, const size_t appendCount) {
		if(appendCount == 0)
			return 0;
		if(!EnsureSize(appendAt + appendCount, true))
			return 0;
		memcpy(&element[appendAt],&append[appendStart],sizeof(T) * appendCount);
		return element;
	}

	/**
	 * ensure buffer size
	 * @param ensureElementCount minimum size of buffer.
	 * @param zeroNewMemory true to initialize newly allocated memory.
	 * @return first element.
	 */
	bool EnsureSize(const size_t ensureElementCount, const bool zeroNewMemory) {
		if(ensureElementCount > elementCount) {
			return Allocate(ensureElementCount - elementCount,zeroNewMemory) != 0;
		}
		return (element!=0);
	}

	/**
	 * resizes capacity to newElementCount eventually truncating allocated memory
	 * @param newElementCount element capacity
	 * @return true if successful, false if error
	 */
	bool Resize(const size_t newElementCount) {
		size_t mallocSize(sizeof(T) * (newElementCount));
		if(element) {
			element = (T*)realloc(element,mallocSize );	}
		else {
			element = (T*)malloc(mallocSize); }
		elementCount = mallocSize;
		return (element!=0);
	}

	/**
	 * zeros all elements.
	 */
	void ZeroAllElements() {
		if(elementCount && element)
			memset(element,0,sizeof(T) * elementCount);
	}

	/**
	 * gets first element.
	 * @return first element.
	 */
	T* GetElements() { return element; }

	/**
	 * gets const first element.
	 * @return first element.
	 */
	const T* GetConstElements() const { return element; }

	/**
	 * gets elements at position.
	 * @param elementNr position.
	 * @return element.
	 */
	T* GetElementAt(const size_t& elementNr) { return &(element[elementNr]); }

	/**
	 * gets const elements at position.
	 * @param elementNr position.
	 * @return element.
	 */
	const T* GetConstElementAt(const size_t& elementNr) const { return &(element[elementNr]); }

	/**
	 * gets number of entries.
	 * @return number of entries.
	 */
	const size_t& GetCount() const { return elementCount; }

private:
	T* element;
	size_t elementCount;
	mutable bool releaseOnDestruct;
};

}
