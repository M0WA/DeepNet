/**
 *
 * @file QueryThread.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QueryThread.h"

#include <Logging.h>

namespace queryserver {

QueryThread::QueryThread()
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(QueryThread::QueryThreadFunction)),false)
, queryThreadParam(0)
, threadParam(0){
}

QueryThread::~QueryThread() {
}

bool QueryThread::InitThreadInstance() {

	log::Logging::RegisterThreadID(GetThreadName());

	if(!queryThreadParam) {
		return false; }

	if(dbHelper.CreateConnection(queryThreadParam->config)) {
		return false; }

	return OnInitThreadInstance();
}

bool QueryThread::DestroyThreadInstance() {

	OnDestroyThreadInstance();

	dbHelper.DestroyConnection();

	if(queryThreadParam)
		delete queryThreadParam;
	queryThreadParam = 0;

	return true;
}

void* QueryThread::QueryThreadFunction(threading::Thread::THREAD_PARAM* threadParam) {

	QueryThread* instance(dynamic_cast<QueryThread*>(threadParam->instance));
	instance->threadParam = threadParam;
	instance->queryThreadParam = reinterpret_cast<QueryThreadParam*>(threadParam->pParam);

	void* ret(0);
	try {
		if(!instance->InitThreadInstance()) {
			instance->DestroyThreadInstance();
			return 0; }

		ret = instance->Run();
		instance->DestroyThreadInstance();
	}
	catch(...) {
		//
		//TODO: log this error
		//
		ret = (void*)1;
	}

	return ret;
}

}
