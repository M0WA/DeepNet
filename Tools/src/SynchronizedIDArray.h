/**
 *
 * @file SynchronizedIDArray.h
 * @author Moritz Wagner
 * @date 16.06.2013
 *
 */

#pragma once

#include <vector>

#include <Mutex.h>
#include <Semaphore.h>

namespace tools {

/**
 * @brief extended semaphore type using IDs
 * this class manages a pool of IDs that can be
 * acuired and released synchroniously
 */
class SynchronizedIDArray {
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
	threading::Semaphore semaphore;
	threading::Mutex idLockMutex;
	std::vector<bool> idLock;
};

}
