/*
 * DB2DatabaseConfig.cpp
 *
 *  Created on: 30.04.2012
 *      Author: Moritz Wagner
 */

#include "DB2DatabaseConfig.h"

namespace database {

DB2DatabaseConfig::DB2DatabaseConfig()
: DatabaseConfig(database::DB_IBM_DB2)
{
}

DB2DatabaseConfig::~DB2DatabaseConfig()
{
}

}
