/**
 *
 * @file IndexerParam.cpp
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#include "IndexerParam.h"

namespace indexing {

IndexerParam::IndexerParam()
: threadCount(0)
, waitOnIdle(0)
, maxPerSelect(0)
, databaseConfig(0){
}

IndexerParam::IndexerParam(
		const int maxPerSelect,
		const int waitOnIdle,
		const int threadCount,
		database::DatabaseConfig* databaseConfig)
: threadCount(threadCount)
, waitOnIdle(waitOnIdle)
, maxPerSelect(maxPerSelect)
, databaseConfig(databaseConfig){
}

IndexerParam::~IndexerParam() {
}

}
