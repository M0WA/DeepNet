/**
 *
 * @file Semaphore.h
 * @author Moritz Wagner
 * @date 16.06.2013
 *
 */

#include <semaphore.h>
#include <vector>

#include "Mutex.h"

#pragma once

namespace threading {

/**
 * @brief implementation of a semaphore
 */
class Semaphore {

public:
	/**
	 * construct with maximal signaled count
	 * @param maxCount maximum signals before lock
	 */
	Semaphore(const size_t& maxCount);
	virtual ~Semaphore();

private:
	Semaphore(const Semaphore& sem) {}
	Semaphore& operator =(const Semaphore& rhs) { return *this; }

public:
	/**
	 * adds a lock.
	 * @return lock id
	 */
	void Lock();

	/**
	 * unlocks a lock.
	 */
	void Unlock();

private:
	sem_t sem;
};

/**
 * @brief extended semaphore type using IDs
 */
class SynchronizedIDArray : private Semaphore {
public:
	/**
	 * construct with number of allowed IDs
	 * maximum ID will be idCount - 1 because IDs have
	 * a zero based index
	 * @param idCount maximum number of IDs allowed
	 */
	SynchronizedIDArray(const size_t& idCount);
	virtual ~SynchronizedIDArray(){}

public:
	/**
	 * gets a new ID
	 * @return locked ID
	 */
	size_t GetID();

	/**
	 * releases a previously locked ID
	 * @param id previously locked ID
	 */
	void ReleaseID(const size_t& id);

private:
	Mutex idLockMutex;
	std::vector<bool> idLock;
};

}
