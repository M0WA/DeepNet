/**
 * @file Thread.cpp
 * @author Moritz Wagner
 * @date 13.01.2012
 */

#include "Thread.h"

namespace threading
{

Thread::Thread(Thread::ThreadFunction pFunction, bool bAutoDelete)
: autoDelete(bAutoDelete)
, thread(0)
{
	threadParam.threadFunction = pFunction;
	threadParam.pParam = NULL;
}

Thread::~Thread()
{
	SetShallEnd(true);
	WaitForThread();
}

Thread::ThreadID Thread::StartThread(void* pParam)
{
	if(IsRunning())	{
		SetShallEnd(true);
		WaitForThread(); }
	SetShallEnd(false);

	threadParam.pParam   = pParam;
	threadParam.instance = this;

	pthread_attr_init(&threadAttr);
	pthread_attr_setdetachstate(&threadAttr, PTHREAD_CREATE_JOINABLE);

	typedef void* (*PThreadFunction)(void*);
	int errThread(pthread_create( &thread, &threadAttr, (PThreadFunction)threadParam.threadFunction, &threadParam ));
	if ( errThread != 0 ) {
		thread = 0;
		if(autoDelete)
			delete this;
		return 0;
	}

	return reinterpret_cast<unsigned long long&>(thread);
}

bool Thread::SetShallEnd(bool shallEnd)
{
	if(shallEnd && !threadParam.shallEnd.IsLocked())
		threadParam.shallEnd.Lock();
	else if(!shallEnd && threadParam.shallEnd.IsLocked())
		threadParam.shallEnd.Unlock();
	return shallEnd;
}

bool Thread::WaitForThread()
{
	if(thread)
	{
		pthread_join(thread,NULL);
		thread = 0;
		return true;
	}
	else
		return false;
}

}
