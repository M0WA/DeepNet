/**
 *
 * @file IndexerParam.h
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#pragma once

namespace database {
	class DatabaseConfig;
}

namespace indexing {

class IndexerParam {
public:
	IndexerParam();
	IndexerParam(
		const int maxPerSelect,
		const int waitOnIdle,
		const int threadCount,
		database::DatabaseConfig* databaseConfig);
	virtual ~IndexerParam();

	int threadCount;
	int waitOnIdle;
	int maxPerSelect;
	database::DatabaseConfig* databaseConfig;
};

}
