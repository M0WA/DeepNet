/**
 * @file DatabaseLayer.h
 * @author Moritz Wagner
 * @date 30.04.2012 *
 * @brief include this header for database functionality.
 */

#pragma once

#include "Statement.h"
#include "SelectStatement.h"
#include "InsertStatement.h"
#include "UpdateStatement.h"
#include "DeleteStatement.h"
#include "GenericStatement.h"
#include "DatabaseConfig.h"

#include "DatabaseConnection.h"
#include "DatabaseHelper.h"
#include "GeneratedTables.h"

#include "../MySQL/MySQLDatabaseConfig.h"
#include "../DB2/DB2DatabaseConfig.h"
#include "../PostgreSQL/PostgreSQLDatabaseConfig.h"
