/**
 *
 * @file ReadWriteLock.h
 * @author Moritz Wagner
 * @date 03.07.2013
 *
 */

#pragma once

#include <stddef.h>

#include <pthread.h>

namespace threading {

/**
 * @brief implements read/write lock, allowing multiple read but block on write
 */
class ReadWriteLock {
public:
	ReadWriteLock(const bool isErrorChecked = false);
	virtual ~ReadWriteLock();

public:
	/**
	 * waits for read lock
	 */
	bool WaitForReadLock();

	/**
	 * waits for write lock
	 */
	bool WaitForWriteLock();

	/**
	 * releases lock
	 */
	bool ReleaseLock();

private:
	pthread_rwlock_t rwlock;
	pthread_rwlockattr_t* attr;

	const bool isErrorChecked;
	volatile long int tid;
};

}
