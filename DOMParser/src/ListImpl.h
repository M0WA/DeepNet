/**
 *
 * @file ListImpl.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <vector>
#include <algorithm>

namespace domparser {

/**
 * generic list implementation for DOM parsing subsystem
 */
template <class T>
class ListImpl {

protected:
	/**
	 * creates an empty typed list
	 */
	ListImpl<T>()
	: items(std::vector<T*>())
	{ }

	/**
	 * creates a prefilled list
	 * @param in list to insert in the beginning
	 */
	ListImpl<T>(const std::vector<T*>& in) {
		items.insert(items.begin(),in.begin(),in.end());
	}

	/**
	 * creates a list prefilled with one item
	 * @param in item to insert in the beginning
	 */
	ListImpl<T>(T* in) {
		items.push_back(in);
	}

public:
	virtual ~ListImpl() {}

	/**
	 * gets an item by it's index
	 * @param index index of the item to get
	 * @return item in list or null
	 */
	virtual T* GetItem(unsigned long index) {
		if(index > items.size() - 1)
			return 0;
		return items.at(index);
	}

	/**
	 * gets the number of items in this list
	 * @return  number of items
	 */
	virtual unsigned long GetLength() const { return items.size(); }

	/**
	 * removes an item
	 * @param del item to delete
	 */
	void RemoveItem(T* del) {
		typename std::vector<T*>::iterator iterItem = std::find(items.begin(),items.end(),del);
		if(iterItem != items.end()) {
			items.erase(iterItem); }
	}

	/**
	 * appends an item to this list
	 * @param append item to append
	 */
	void AppendItem(T* append) {
		items.push_back(append);
	}

	/**
	 * appends multiple items to this list
	 * @param in items to append
	 */
	void AppendItems(const std::vector<T*>& in) {
		items.insert(items.end(),in.begin(),in.end());
	}

private:
	std::vector<T*> items;
};

}
