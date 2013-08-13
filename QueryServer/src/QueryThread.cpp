/**
 *
 * @file QueryThread.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QueryThread.h"

#include "QueryThreadParam.h"

#include <Logging.h>

namespace queryserver {

QueryThread::QueryThread()
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(QueryThread::QueryThreadFunction)),false)
, queryThreadParam(0)
, threadParam(0){
}

QueryThread::~QueryThread() {
}

bool QueryThread::InitThreadInstance(threading::Thread::THREAD_PARAM* threadParam) {

	threadParam = threadParam;
	queryThreadParam = reinterpret_cast<QueryThreadParam*>(threadParam->pParam);

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
	log::Logging::RegisterThreadID(instance->GetThreadName());

	void* ret(0);
	try {
		if(!instance->InitThreadInstance(threadParam)) {
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
