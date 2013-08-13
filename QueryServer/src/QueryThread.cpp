/**
 *
 * @file QueryThread.cpp
 * @author Moritz Wagner
 * @date 12.08.2013
 *
 */

#include "QueryThread.h"

#include "QueryThreadParam.h"
#include "QueryThreadResultEntry.h"

#include <DatabaseLayer.h>
#include <Logging.h>

namespace queryserver {

QueryThread::QueryThread()
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(QueryThread::QueryThreadFunction)),false)
, queryThreadParam(0)
, dbConn(0){
}

QueryThread::~QueryThread() {
}

const tools::PointerContainer<QueryThreadResultEntry>& QueryThread::GetResults() const {
	return resultEntries; }

bool QueryThread::InitThreadInstance(threading::Thread::THREAD_PARAM* threadParam) {

	queryThreadParam.Set(reinterpret_cast<QueryThreadParam*>(threadParam->pParam),true);
	if(queryThreadParam.IsNull()) {
		return false; }

	dbConn = queryThreadParam.GetConst()->dbConn;
	if(!dbConn) {
		return false; }

	return OnInitThreadInstance();
}

bool QueryThread::DestroyThreadInstance() {

	OnDestroyThreadInstance();
	queryThreadParam.Release();
	dbConn = 0;
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
