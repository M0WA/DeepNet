/**
 *
 * @file PostgreSQLPGC.h
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

void pg_db_connect(const char* host, const int port, const char* user, const char* pass, const char* dbname);
void pg_db_disconnect();

#ifdef __cplusplus
}
#endif
