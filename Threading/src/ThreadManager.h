/**
 *
 * @file ThreadManager.h
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#pragma once

#include <map>

#include "Thread.h"

namespace threading {

/**
 * @brief class to manage multiple threads
 */
class ThreadManager {

private:
	typedef std::pair<threading::Thread*,void*> ThreadInfos;

public:
	ThreadManager();
	virtual ~ThreadManager();

public:
	/**
	 * adds a thread and starts it
	 * @param thread thread to start
	 * @param params parameters to thread
	 * @return thread id on success, 0 on error
	 */
	Thread::ThreadID AddThread(threading::Thread* thread, void* params = NULL);

	/**
	 * sets shutdown flag for all threads
	 */
	void SetShallEndForAll();

	/**
	 * waits for all threads to end
	 */
	void WaitForAll() const;

	/**
	 * terminates all threads if neccessary and releases their memory
	 */
	void ReleaseAll();

public:
	/**
	 * gets thread's infos according to it's thread id
	 * @param threadID thread ID
	 * @return thread's info
	 */
	const ThreadManager::ThreadInfos& GetThreadInfosByID(const Thread::ThreadID& threadID) const {
		return threads.at(threadID); }

private:
	std::map<Thread::ThreadID, ThreadManager::ThreadInfos > threads;
};

}
