/**
 *
 * @file QueryMetaThread.cpp
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#include "QueryMetaThread.h"

namespace queryserver {

QueryMetaThread::QueryMetaThread()
: queryserver::QueryDictionaryThread() {
}

QueryMetaThread::~QueryMetaThread() {
}

void* QueryMetaThread::OnRun(){

	QueryDictionaryThread::OnRun();

	return 0;
}


}
