/**
 * @file MySQLDatabaseConfig.cpp
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#include "MySQLDatabaseConfig.h"

namespace database {

MySQLDatabaseConfig::MySQLDatabaseConfig()
: DatabaseConfig(database::DB_MYSQL)
{
}

MySQLDatabaseConfig::~MySQLDatabaseConfig()
{
}

}
