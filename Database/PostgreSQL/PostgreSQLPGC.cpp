/* Processed by ecpg (4.7.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "../PostgreSQL/PostgreSQLPGC.pgc"
/**
 *
 * @file PostgresSQLPGC.cpp
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#include "PostgreSQLPGC.h"
#include <stdio.h>

void
pg_db_connect(const char* host, const int port, const char* user, const char* pass, const char* dbname)
{
    { ECPGconnect(__LINE__, 0, "testdb1" , NULL, NULL , NULL, 0); }
#line 15 "../PostgreSQL/PostgreSQLPGC.pgc"

}

void
pg_db_disconnect()
{
    { ECPGdisconnect(__LINE__, "ALL");}
#line 21 "../PostgreSQL/PostgreSQLPGC.pgc"

}
