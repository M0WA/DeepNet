/**
 * @file Thread.h
 * @author Moritz Wagner
 * @date 13.01.2012
 */

#pragma once

#include <pthread.h>
#include "Mutex.h"

namespace threading
{

/**
 * @brief generic thread class.
 */
class Thread
{
protected:
	struct _THREAD_PARAM;

	/**
	 * @struct THREAD_PARAM
	 * container for thread's parameters.
	 */
	typedef struct _THREAD_PARAM THREAD_PARAM;

	/**
	 * type for user defined thread function.
	 * @param thread's parameters.
	 */
	typedef void* (*ThreadFunction)(THREAD_PARAM*);

	/**
	 * @struct _THREAD_PARAM
	 * declaration for internal use
	 * @see threading::Thread::THREAD_PARAM
	 */
	struct _THREAD_PARAM{

		/**
		 * user defined parameters.
		 */
		void* pParam;

		/**
		 * instance of threading::Thread class.
		 */
		Thread* instance;

		/**
		 * mutex signaling termination of the thread.
		 */
		Mutex shallEnd;

		/**
		 * user defined thread function
		 */
		ThreadFunction threadFunction;
	};

public:
	typedef unsigned long long ThreadID;

protected:
	/**
	 * construct an instance using user defined thread function.
	 * @param pFunction user defined thread function.
	 * @param bAutoDelete if true, instance deletes itself when thread ends.
	 */
	Thread(ThreadFunction pFunction, bool bAutoDelete = false);

private:
	Thread(const Thread& copy) { throw; }
	Thread& operator =(const Thread& rhs) { throw; }

public:
	virtual ~Thread();

public:
	/**
	 * starts the thread.
	 * @param pParam user defined parameters.
	 * @return 0 on error, new threadID on success.
	 */
	Thread::ThreadID StartThread(void* pParam = NULL);

	/**
	 * blocks till thread has ended.
	 * @return false on error, true on success.
	 */
	bool WaitForThread();

	/**
	 * set end of thread.
	 * @param shallEnd true if thread should end.
	 * @return false on error, true on success.
	 */
	bool SetShallEnd(bool shallEnd = true);

	/**
	 * checks if thread should end.
	 * @return false if thread should not end, true if thread should end.
	 */
	inline bool ShallEnd() const { return threadParam.shallEnd.IsLocked(); }

	/**
	 * checks if thread is running.
	 * @return false if not running, true if running.
	 */
	inline bool IsRunning() const { return thread > 0; }

public:
	/**
	 * checks if thread should end by thread parameters.
	 * @param threadParam thread parameters.
	 * @return false if thread should not end, true if thread should end.
	 */
	inline static bool ShallEnd(THREAD_PARAM* threadParam) { return threadParam->shallEnd.IsLocked(); }

protected:
	inline void SetThreadFunction(ThreadFunction pFunction) { if (!IsRunning()) threadParam.threadFunction = pFunction; }

private:
	THREAD_PARAM    threadParam;

	bool            autoDelete;
	pthread_t 	    thread;
	pthread_attr_t  threadAttr;
};

}
