/**
 *
 * @file Semaphore.cpp
 * @author Moritz Wagner
 * @date 16.06.2013
 *
 */

#include "Semaphore.h"

namespace threading {

Semaphore::Semaphore(const size_t& maxCount) {
	sem_init(&sem, 0, maxCount);
}

Semaphore::~Semaphore() {
	sem_destroy(&sem);
}

void Semaphore::Lock(){
	sem_wait(&sem);
}

void Semaphore::Unlock(){
	sem_post(&sem);
}

SynchronizedIDArray::SynchronizedIDArray(const size_t& idCount)
: Semaphore(idCount)
{
}

size_t SynchronizedIDArray::GetID()
{
	size_t ret = 0;
	Lock();
	idLockMutex.Lock();
	std::vector<bool>::iterator i = idLock.begin();
	for(size_t id=0;i != idLock.end();++i,id++) {
		if(!(*i)) {
			*i = false;
			ret = id;
			break; }
	}
	idLockMutex.Unlock();
	return ret;
}

void SynchronizedIDArray::ReleaseID(const size_t& id)
{
	idLockMutex.Lock();
	Unlock();
	idLock.at(id) = false;
	idLockMutex.Unlock();
}

}
