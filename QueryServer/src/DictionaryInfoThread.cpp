/**
 *
 * @file DictionaryInfoThread.cpp
 * @author Moritz Wagner
 * @date 27.08.2013
 *
 */

#include "DictionaryInfoThread.h"

#include "Query.h"

#include <iterator>

#include <DatabaseLayer.h>
#include <DatabaseHelper.h>
#include <TableDefinition.h>
#include <TableColumnDefinition.h>
#include <TableColumn.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <ContainerTools.h>
#include <StringTools.h>
#include <TimeTools.h>
#include <Pointer.h>
#include <Logging.h>
#include <PerformanceCounter.h>

#include <DatabaseException.h>

namespace queryserver {

DictionaryInfoThread::DictionaryInfoThread(database::DatabaseConnection* dbConn,const Query& query)
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(DictionaryInfoThread::DictionaryInfoThreadFunction)),false)
, dbConn(dbConn)
, query(query) {
}

DictionaryInfoThread::~DictionaryInfoThread() {
}

void* DictionaryInfoThread::DictionaryInfoThreadFunction(threading::Thread::THREAD_PARAM* threadParam) {

	log::Logging::RegisterThreadID("DictionaryInfoThread");

	DictionaryInfoThread* threadInst(reinterpret_cast<DictionaryInfoThread*>(threadParam->instance));

	PERFORMANCE_LOG_START;

	//TODO: split dictionary initializiation by keyword to speedup things ( one thread per keyword )
	if(!threadInst->dictionary.Init(threadInst->dbConn,threadInst->query)) {
		return (void*)1; }

	PERFORMANCE_LOG_STOP("DictionaryInfoThread");

	return 0;
}

}
