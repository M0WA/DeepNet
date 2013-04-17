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
	Mutex(void);
	virtual ~Mutex(void);
private:
	Mutex(const Mutex&) { throw; } //never ever copy pthread_mutex_t => undefined behaviour

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
	AutoMutex(const AutoMutex& in)
	: mutex(in.mutex) { throw; } 	//never ever copy auto mutex,
									//will be released when first instance is destroyed
	                                //and a second unlock would be triggered also...
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
