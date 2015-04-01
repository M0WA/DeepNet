/*
 * @file FastCGIServerThreadConfig.cpp
 * @date Jan 15, 2015
 * @uthor Moritz Wagner
 */

#include "FastCGIServerThreadConfig.h"

namespace fastcgiserver {

FastCGIServerThreadConfig::FastCGIServerThreadConfig(
	const database::DatabaseConfig* databaseConfig,
	threading::Mutex* acceptMutex,
	unsigned long long max_post_data,
	int port,
	int backlog)
: databaseConfig(databaseConfig)
, acceptMutex(acceptMutex)
, max_post_data(max_post_data)
, socket(port,backlog) {
}

FastCGIServerThreadConfig::FastCGIServerThreadConfig(
	const database::DatabaseConfig* databaseConfig,
	threading::Mutex* acceptMutex,
	unsigned long long max_post_data,
	const std::string& filename,
	int backlog)
: databaseConfig(databaseConfig)
, acceptMutex(acceptMutex)
, max_post_data(max_post_data)
, socket(filename,backlog) {
}

FastCGIServerThreadConfig::~FastCGIServerThreadConfig() {
}

}
