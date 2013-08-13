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
template <class T>
class ThreadManager {

public:
	typedef std::pair<T*,void*> ThreadInfos;

public:
	ThreadManager() {}
	virtual ~ThreadManager(){
		ReleaseAll();
	}

public:
	/**
	 * adds a thread and starts it
	 * @param thread thread to start
	 * @param params parameters to thread
	 * @return thread id on success, 0 on error
	 */
	Thread::ThreadID AddThread(T* thread, void* params = NULL){

		Thread::ThreadID tid(thread->StartThread(params));
		if(tid == 0)
			return 0;

		if(threads.count(tid)>0) {
			//
			//TODO: this should never happen
			//
			return 0;
		}

		threads.insert(std::pair<Thread::ThreadID,ThreadManager<T>::ThreadInfos>(tid,ThreadManager<T>::ThreadInfos(thread, params)));
		return tid;
	}

	/**
	 * sets shutdown flag for all threads
	 */
	void SetShallEndForAll(){
		typename std::map<Thread::ThreadID, ThreadManager<T>::ThreadInfos >::iterator i(threads.begin());
		for(;i != threads.end();++i) {
			i->second.first->SetShallEnd(true);	}
	}

	/**
	 * waits for all threads to end
	 */
	void WaitForAll() const {
		typename std::map<Thread::ThreadID, ThreadManager<T>::ThreadInfos >::const_iterator i(threads.begin());
		for(;i != threads.end();++i) {
			i->second.first->WaitForThread();	}
	}

	/**
	 * terminates all threads if neccessary and releases their memory
	 */
	void ReleaseAll(){

		SetShallEndForAll();
		WaitForAll();

		typename std::map<Thread::ThreadID, ThreadManager<T>::ThreadInfos >::iterator i(threads.begin());
		for(;i != threads.end();++i) {
			delete i->second.first;	}
	}

public:
	/**
	 * gets thread's infos according to it's thread id
	 * @param threadID thread ID
	 * @return thread's info
	 */
	const ThreadManager<T>::ThreadInfos& GetThreadInfosByID(const Thread::ThreadID& threadID) const {
		return threads.at(threadID); }

private:
	std::map<Thread::ThreadID, ThreadManager<T>::ThreadInfos > threads;
};

}
