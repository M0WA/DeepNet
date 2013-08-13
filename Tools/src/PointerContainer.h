/**
 * @file PointerContainer.h
 * @author Moritz Wagner
 * @date 23.02.2013
 */

#pragma once

#include <vector>
#include <cstddef>

namespace tools {

/**
 * @brief memory managing container for pointers.
 * use iterator to enumerate over all entries.
 * @see tools::Pointer for more information
 */
template <class T>
class PointerContainer {
private:
	PointerContainer<T>(const PointerContainer<T>& copy){ ResetIter(); }

public:
	PointerContainer<T>() : container(std::vector<T*>()), deleteOnDestruct(true) {}
	PointerContainer<T>(const std::vector<T*>& container) : container(container), deleteOnDestruct(true) {
		ResetIter();}

	/**
	 * deletes all entries when destructed.
	 */
	virtual ~PointerContainer(){ CleanUp(); }

public:
	/**
	 * adds an entry.
	 * @param entry entry to add.
	 */
	void Add(T* entry) {
		container.push_back(entry);
		ResetIter(); }

	/**
	 * adds multiple entries entry.
	 * @param entries entries to add.
	 */
	void Add(const std::vector<T*>& entries ) {
		container.insert(container.end(), entries.begin(), entries.end());
		ResetIter(); }

	/**
	 * appends all pointers from other container
	 * and takes their ownership
	 * @param appendFrom PointerContainer to append from
	 */
	void AppendFrom(PointerContainer<T>& appendFrom) {
		appendFrom.deleteOnDestruct = false;
		container.insert(container.end(), appendFrom.container.begin(), appendFrom.container.end());
		ResetIter(); }

	/**
	 * resets iterator.
	 */
	void ResetIter() const {
		iterContainer = container.begin(); }

	/**
	 * checks if iterator is at end.
	 * @return false if not at end, true if at end.
	 */
	bool IsIterEnd() const {
		return iterContainer == container.end(); }

	/**
	 * gets current iterator.
	 * @return current iterator
	 */
	T* GetIter() {
		return *iterContainer; }

	/**
	 * gets current iterator as const.
	 * @return current iterator
	 */
	const T* const GetConstIter() const {
		return *iterContainer; }

	/**
	 * increment iterator.
	 */
	void Next() const {
		if(!IsIterEnd())
			++iterContainer;
	}

	/**
	 * gets vector of entries.
	 * @return raw vector of entries.
	 */
	std::vector<T*>& GetVector() {
		return container; }

	/**
	 * gets const vector of entries.
	 * @return const vector of entries.
	 */
	const std::vector<T*>& GetConstVector() const {
		return container; }

	/**
	 * gets current container size.
	 * @return current container size.
	 */
	size_t Size() const {
		return container.size(); }

private:
	void CleanUp(){

		if(deleteOnDestruct)
			for(iterContainer = container.begin(); iterContainer != container.end(); ++iterContainer)
				delete (*iterContainer);

		container.clear();
	}

private:
	std::vector<T*> container;
	mutable typename std::vector<T*>::const_iterator iterContainer;
	bool deleteOnDestruct;
};

}
