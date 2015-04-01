/**
 * @file MySQLDatabaseConfig.h
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#pragma once

#include "DatabaseConfig.h"

namespace database {

/**
 * @brief implementation of database::DatabaseConfig for MySQL servers
 */
class MySQLDatabaseConfig : public DatabaseConfig {
public:
	MySQLDatabaseConfig();
	virtual ~MySQLDatabaseConfig();
};

}
