/**
 *
 * @file QueryUrlThread.cpp
 * @author Moritz Wagner
 * @date 11.08.2013
 *
 */

#include "QueryUrlThread.h"

namespace queryserver {

QueryUrlThread::QueryUrlThread() {
}

QueryUrlThread::~QueryUrlThread() {
}

bool QueryUrlThread::OnInitThreadInstance(){
	return false;
}

bool QueryUrlThread::OnDestroyThreadInstance(){
	return false;
}

void* QueryUrlThread::Run(){
	return 0;
}

}
