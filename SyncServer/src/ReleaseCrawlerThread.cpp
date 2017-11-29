/*
 * @file ReleaseCrawlerThread.cpp
 * @date Nov 29, 2017
 * @author Moritz Wagner
 */

#include "ReleaseCrawlerThread.h"

namespace syncserver {

ReleaseCrawlerThread::ReleaseCrawlerThread()
: threading::Thread(ReleaseCrawlerThreadFunc,false){
}

ReleaseCrawlerThread::~ReleaseCrawlerThread() {
}

void* ReleaseCrawlerThread::ReleaseCrawlerThreadFunc(threading::Thread::THREAD_PARAM* param) {
	return NULL;
}

}
