/**
 *
 * @file QueryMetaThread.cpp
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#include "QueryMetaThread.h"

namespace queryserver {

QueryMetaThread::QueryMetaThread() {
}

QueryMetaThread::~QueryMetaThread() {
}

bool QueryMetaThread::OnInitThreadInstance(){
	return false;
}

bool QueryMetaThread::OnDestroyThreadInstance(){
	return false;
}

void* QueryMetaThread::Run(){
	return 0;
}


}
