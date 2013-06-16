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

}
