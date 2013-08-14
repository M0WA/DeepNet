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
#include <PerformanceCounter.h>

#include <Exception.h>

namespace queryserver {

QueryThread::QueryThread()
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(QueryThread::QueryThreadFunction)),false)
, queryThreadParam(0)
, dbConn(0){
}

QueryThread::~QueryThread() {
	queryThreadParam.Release();
	dbConn = 0;
}

const tools::PointerContainer<QueryThreadResultEntry>& QueryThread::GetResults() const {

	return resultEntries;
}

bool QueryThread::InitThreadInstance(threading::Thread::THREAD_PARAM* threadParam) {

	queryThreadParam.Set(reinterpret_cast<QueryThreadParam*>(threadParam->pParam),true);
	if(queryThreadParam.IsNull()) {
		log::Logging::LogError("invalid query thread parameters received, omitting search query");
		return false; }

	dbConn = queryThreadParam.GetConst()->dbConn;
	if(!dbConn) {
		log::Logging::LogError("invalid database connection received, omitting search query");
		return false; }

	OnInitThreadInstance();
	return true;
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
			ret = (void*)1; }
		else {
			ret = instance->Run(); }
		instance->DestroyThreadInstance();
	}
	catch(errors::Exception& e) {
		ret = (void*)1;
	}
	catch(...) {
		log::Logging::LogError("unknown exception occurred, omitting search query");
		ret = (void*)1;
	}

	return ret;
}

void* QueryThread::Run() {

	PERFORMANCE_LOG_START
	void* ret(OnRun());
	PERFORMANCE_LOG_STOP(GetThreadName());

	return ret;
}

}
