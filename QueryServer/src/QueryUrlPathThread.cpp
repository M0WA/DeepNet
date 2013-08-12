/**
 *
 * @file QueryUrlPathThread.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QueryUrlPathThread.h"

namespace queryserver {

QueryUrlPathThread::QueryUrlPathThread() {
}

QueryUrlPathThread::~QueryUrlPathThread() {
}

bool QueryUrlPathThread::OnInitThreadInstance(){
	return false;
}

bool QueryUrlPathThread::OnDestroyThreadInstance(){
	return false;
}

void* QueryUrlPathThread::Run(){
	return 0;
}

}
