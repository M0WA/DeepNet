/**
 *
 * @file PostgreSQLDatabaseConfig.h
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#pragma once

#include "DatabaseConfig.h"

namespace database {

class PostgreSQLDatabaseConfig: public database::DatabaseConfig {
public:
	PostgreSQLDatabaseConfig();
	virtual ~PostgreSQLDatabaseConfig();
};

}
