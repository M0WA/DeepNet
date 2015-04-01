/*
 * @file FastCGIServerThreadConfig.h
 * @date Jan 15, 2015
 * @uthor Moritz Wagner
 */

#pragma once

#include <string>

//#include <DatabaseHelper.h>

#include "FastCGISocket.h"

namespace threading {
	class Mutex;
}

namespace database {
	class DatabaseConfig;
}

namespace fastcgiserver {

class FastCGIServerThreadConfig {
protected:
	FastCGIServerThreadConfig(
		const database::DatabaseConfig* databaseConfig,
		threading::Mutex* acceptMutex,
		unsigned long long max_post_data,
		int port,
		int backlog);

	FastCGIServerThreadConfig(
		const database::DatabaseConfig* databaseConfig,
		threading::Mutex* acceptMutex,
		unsigned long long max_post_data,
		const std::string& filename,
		int backlog);
public:
	virtual ~FastCGIServerThreadConfig();

public:
	const database::DatabaseConfig* GetDatabaseConfig() const { return databaseConfig; }
	threading::Mutex* GetAcceptMutex() { return acceptMutex; }
	FastCGISocket& GetFastCGISocket() { return socket; }

private:
	//database::DatabaseHelper dbHelper;
	const database::DatabaseConfig* databaseConfig;
	threading::Mutex* acceptMutex;
	unsigned long long max_post_data;
	FastCGISocket socket;
};

}
