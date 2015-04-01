/**
 *
 * @file SynchronizedIDArray.cpp
 * @author Moritz Wagner
 * @date 16.06.2013
 *
 */

#include "SynchronizedIDArray.h"

namespace tools {

SynchronizedIDArray::SynchronizedIDArray(const size_t& idCount)
: semaphore(idCount)
{
	threading::AutoMutex lockAuto(idLockMutex);
	for(size_t id=0;id < idCount;id++) {
		idLock.push_back(false);}
}

size_t SynchronizedIDArray::GetID()
{
	semaphore.Lock();

	size_t ret = 0;

	idLockMutex.Lock();
	std::vector<bool>::iterator i = idLock.begin();
	for(size_t id=0;i != idLock.end();++i,id++) {
		if( !(*i) ) {
			*i = true;
			ret = id;
			break;
		}
	}
	idLockMutex.Unlock();
	return ret;
}

void SynchronizedIDArray::ReleaseID(const size_t& id)
{
	threading::AutoMutex lockAuto(idLockMutex);

	semaphore.Unlock();
	idLock.at(id) = false;
}

}
