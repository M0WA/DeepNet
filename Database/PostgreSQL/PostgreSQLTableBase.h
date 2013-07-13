/**
 *
 * @file PostgreSQLTableBase.h
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#pragma once

#include "TableBase.h"

namespace database {

/**
 * @brief implementation of database::TableBase for PostgreSQL servers
 */
class PostgreSQLTableBase: public database::TableBase {
public:
	PostgreSQLTableBase();
	virtual ~PostgreSQLTableBase();
};

}
