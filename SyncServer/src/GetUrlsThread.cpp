/*
 * @file GetUrlsThread.cpp
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#include "GetUrlsThread.h"

namespace syncserver {

GetUrlsThread::GetUrlsThread()
: Thread(GetUrlsThread::GetUrlsThreadFunc,false){

}

GetUrlsThread::~GetUrlsThread() {
}

void* GetUrlsThread::GetUrlsThreadFunc(threading::Thread::THREAD_PARAM* param) {
	return NULL;
}

}
