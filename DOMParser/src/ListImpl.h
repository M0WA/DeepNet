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

template <class T>
class ListImpl {

protected:
	ListImpl<T>()
	: items(std::vector<T*>())
	{ }

	ListImpl<T>(const std::vector<T*>& in) {
		items.insert(items.begin(),in.begin(),in.end());
	}

	ListImpl<T>(T* in) {
		items.push_back(in);
	}

public:
	virtual ~ListImpl() {}

	virtual T* GetItem(unsigned long index) {
		if(index > items.size() - 1)
			return 0;
		return items.at(index);
	}

	virtual unsigned long GetLength() const { return items.size(); }

	void RemoveItem(T* del) {
		typename std::vector<T*>::iterator iterItem = std::find(items.begin(),items.end(),del);
		if(iterItem != items.end()) {
			items.erase(iterItem); }
	}

	void AppendItem(T* append) {
		items.push_back(append);
	}

	void AppendItems(const std::vector<T*>& in) {
		items.insert(items.end(),in.begin(),in.end());
	}

private:
	std::vector<T*> items;
};

}
