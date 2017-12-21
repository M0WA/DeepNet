/**
 * @file Mutex.h
 * @author Moritz Wagner
 * @date 05.09.2011
 */

#pragma once

#include <pthread.h>

namespace threading
{

/**
 * @brief generic mutex class.
 */
class Mutex
{
public:
	Mutex(const bool isErrorChecked = false);
	virtual ~Mutex(void);
private:
	Mutex(const Mutex&) : isErrorChecked(false) { throw; }
	Mutex& operator =(const Mutex& rhs) { throw; }

public:
	/**
	 * waits for and locks mutex.
	 * @return false on error, true on success.
	 */
	bool Lock(void);

	/**
	 * unlocks mutex.
	 * @return false on error, true on success.
	 */
	bool Unlock(void);

	/**
	 * checks if mutex is locked.
	 * @return false on non-locked, true if locked.
	 */
	bool IsLocked(void) const;

private:
	volatile bool m_bIsLocked;
	const bool isErrorChecked;
	volatile long int tid;
	pthread_mutex_t m_tMutex;
};

/**
 * @brief locks and unlocks mutex automatically.
 *
 * locks a mutex automatically on creation and unlocks it on destruction.
 * used for locking a mutex in a certain scope and release it when this
 * instance goes out of scope.
 */
class AutoMutex
{
public:
	AutoMutex(Mutex& mutex)
	: mutex(mutex)
	, unlockAtDestroy(true)	{
		this->mutex.Lock();
	}

	~AutoMutex() {
		if(unlockAtDestroy)
			this->mutex.Unlock();
	}

private:
	/**
	 * never ever copy auto mutex,
	 * will be released when first instance is destroyed
	 * and a second unlock would be triggered also...
	 * will throw() on call
	 * @param in AutoMutex to copy from
	 */
	AutoMutex(const AutoMutex& in)
	: mutex(in.mutex), unlockAtDestroy(in.unlockAtDestroy) { throw; }

public:
	/**
	 * set unlocking at destruction.
	 * @param unlockAtDestroy true if mutex should be unlocked on destruction.
	 */
	void UnlockAtDestroy(const bool unlockAtDestroy) { this->unlockAtDestroy = unlockAtDestroy; }

private:
	Mutex& mutex;
	bool unlockAtDestroy;
};


}
