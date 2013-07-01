/**
 * @file Mutex.cpp
 * @author Moritz Wagner
 * @date 05.09.2011
 */

#include "Mutex.h"

#include <unistd.h>
#include <sys/syscall.h>

namespace threading
{

Mutex::Mutex(const bool isErrorChecked)
: m_bIsLocked(false)
, isErrorChecked(false)
, tid(0)
{
	pthread_mutex_init( &m_tMutex, NULL );
}

Mutex::~Mutex(void)
{
	if (m_bIsLocked)
		Unlock();

	pthread_mutex_destroy(&m_tMutex);
}

bool Mutex::Lock(void)
{
	int err = pthread_mutex_lock( &m_tMutex );
	m_bIsLocked = true;

	if(err == 0 && isErrorChecked) {
		tid = syscall(SYS_gettid);}

	return (err == 0);
}

bool Mutex::Unlock(void)
{
	if(isErrorChecked && tid != syscall(SYS_gettid)) {
		tid = 0;
		return false; }
	int err = pthread_mutex_unlock( &m_tMutex );
	m_bIsLocked = false;
	return (err == 0);
}

bool Mutex::IsLocked(void) const
{
	return m_bIsLocked;
}

}
