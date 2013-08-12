/**
 *
 * @file QuerySecondLevelDomainThread.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QuerySecondLevelDomainThread.h"

namespace queryserver {

QuerySecondLevelDomainThread::QuerySecondLevelDomainThread() {
}

QuerySecondLevelDomainThread::~QuerySecondLevelDomainThread() {
}

bool QuerySecondLevelDomainThread::OnInitThreadInstance(){
	return false;
}

bool QuerySecondLevelDomainThread::OnDestroyThreadInstance(){
	return false;
}

void* QuerySecondLevelDomainThread::Run(){
	return 0;
}

}
