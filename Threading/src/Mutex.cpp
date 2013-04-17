/**
 * @file Mutex.cpp
 * @author Moritz Wagner
 * @date 05.09.2011
 */

#include "Mutex.h"

namespace threading
{

Mutex::Mutex(void)
: m_bIsLocked(false)
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
	pthread_mutex_lock( &m_tMutex );
	m_bIsLocked = true;

	return true;
}

bool Mutex::Unlock(void)
{
	pthread_mutex_unlock( &m_tMutex );
	m_bIsLocked = false;

	return true;
}

bool Mutex::IsLocked(void) const
{
	return m_bIsLocked;
}

}
