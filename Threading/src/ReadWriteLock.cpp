/**
 *
 * @file ReadWriteLock.cpp
 * @author Moritz Wagner
 * @date 03.07.2013
 *
 */

#include "ReadWriteLock.h"

#include <unistd.h>
#include <sys/syscall.h>

namespace threading {

ReadWriteLock::ReadWriteLock(const bool isErrorChecked)
// : rwlock(PTHREAD_RWLOCK_INITIALIZER)
: attr(0)
, isErrorChecked(isErrorChecked){
	pthread_rwlock_init(&rwlock, attr);
}

ReadWriteLock::~ReadWriteLock() {
	pthread_rwlock_destroy(&rwlock);
}

bool ReadWriteLock::WaitForReadLock(){
	int err = pthread_rwlock_rdlock(&rwlock);
	if(isErrorChecked && err == 0) {
		tid = syscall(SYS_gettid);}
	return (err == 0);
}

bool ReadWriteLock::WaitForWriteLock(){
	int err = pthread_rwlock_wrlock(&rwlock);
	if(isErrorChecked) {
		tid = syscall(SYS_gettid);}
	return (err == 0);
}

bool ReadWriteLock::ReleaseLock(){
	if(isErrorChecked && tid != syscall(SYS_gettid)) {
		tid = 0;
		return false; }
	return (pthread_rwlock_unlock(&rwlock) == 0);
}

}
