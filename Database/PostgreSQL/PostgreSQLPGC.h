/**
 *
 * @file PostgreSQLPGC.h
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#pragma once

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

void pg_get_next_connection_id(
	long long& id,
	std::string& connectionName);

void pg_release_connection_id(
	const long long& id);

bool pg_db_connect(
	long long& id,
	const char* host,
	const int port,
	const char* user,
	const char* pass,
	const char* dbName);

bool pg_db_disconnect(
	long long& id);

bool pg_db_start_transaction(
	const long long& id);

bool pg_db_commit_transaction(
	const long long& id);

bool pg_db_rollback_transaction(
	const long long& id);

bool pg_db_set_autocommit(
	const long long& id,
	const bool autocommit);

void pg_db_log_sqlca(
	const long long id);

#ifdef __cplusplus
}
#endif
