/**
 *
 * @file ThreadManager.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "ThreadManager.h"

namespace threading {

ThreadManager::ThreadManager() {
}

ThreadManager::~ThreadManager() {
	ReleaseAll();
}

threading::Thread::ThreadID ThreadManager::AddThread(threading::Thread* thread, void* params) {

	Thread::ThreadID tid(thread->StartThread(params));
	if(tid == 0)
		return 0;

	if(threads.count(tid)>0) {
		//
		//TODO: this should never happen
		//
		return 0;
	}

	threads.insert(std::pair<Thread::ThreadID,ThreadManager::ThreadInfos>(tid,ThreadManager::ThreadInfos(thread, params)));
	return tid;
}

void ThreadManager::WaitForAll() const {
	std::map<Thread::ThreadID, ThreadManager::ThreadInfos >::const_iterator i(threads.begin());
	for(;i != threads.end();++i) {
		i->second.first->WaitForThread();}
}

void ThreadManager::ReleaseAll() {

	SetShallEndForAll();
	WaitForAll();

	std::map<Thread::ThreadID, ThreadManager::ThreadInfos >::iterator i(threads.begin());
	for(;i != threads.end();++i) {
		delete i->second.first;	}
}

void ThreadManager::SetShallEndForAll() {
	std::map<Thread::ThreadID, ThreadManager::ThreadInfos >::iterator i(threads.begin());
	for(;i != threads.end();++i) {
		i->second.first->SetShallEnd(true);	}
}

}
