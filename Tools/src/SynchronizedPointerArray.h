/**
 *
 * @file SynchronizedPointerArray.h
 * @author Moritz Wagner
 * @date 16.06.2013
 *
 */

#pragma once

#include <vector>
#include <map>

#include "SynchronizedIDArray.h"
#include "PointerContainer.h"

namespace tools {

/**
 * @brief generic implementation of a lockable pointer array
 * @see tools::SynchronizedIDArray
 */
template <class T>
class SynchronizedPointerArray : private SynchronizedIDArray {
public:
	/**
	 * constructs array from vector of pre-allocated pointers.
	 * all pointers will be delete automatically when this instance is
	 * destroyed.
	 * @param entries vector of pre-allocated pointers
	 */
	SynchronizedPointerArray<T>(const std::vector<T*>& entries)
	: SynchronizedIDArray(entries.size())
	, pointer(entries)
	{ }

	virtual ~SynchronizedPointerArray() {}

public:
	/**
	 * returns a newly locked pointer
	 * @return pointer and it's ID
	 */
	std::pair<T*,size_t> Get() {
		typename std::pair<T*,size_t> ret;
		ret.first = GetID();
		ret.second = pointer.GetVector().at(ret.first);
		return ret;
	}

	/**
	 * release a pointer by it's ID
	 * @param id ID to release
	 */
	void Release(const size_t& id) {
		ReleaseID(id);
	}

private:
	PointerContainer<T> pointer;
};

}
