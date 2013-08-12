/**
 *
 * @file QuerySubdomainThread.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QuerySubdomainThread.h"

namespace queryserver {

QuerySubdomainThread::QuerySubdomainThread() {
}

QuerySubdomainThread::~QuerySubdomainThread() {
}

bool QuerySubdomainThread::OnInitThreadInstance(){
	return false;
}

bool QuerySubdomainThread::OnDestroyThreadInstance(){
	return false;
}

void* QuerySubdomainThread::Run(){
	return 0;
}

}
