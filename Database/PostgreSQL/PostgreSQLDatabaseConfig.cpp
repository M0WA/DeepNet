/**
 *
 * @file PostgreSQLDatabaseConfig.cpp
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#include "PostgreSQLDatabaseConfig.h"

#include "DatabaseConfig.h"

namespace database {

PostgreSQLDatabaseConfig::PostgreSQLDatabaseConfig()
: DatabaseConfig(DB_POSTGRESQL){
}

PostgreSQLDatabaseConfig::~PostgreSQLDatabaseConfig() {
}

}
