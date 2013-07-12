/**
 * @file DatabaseConnection.cpp
 * @author Moritz Wagner
 * @date 29.04.2012
 */

#include "DatabaseConnection.h"

namespace database {

DatabaseConnection::DatabaseConnection(const DatabaseType& databaseType, const bool logQuery)
: databaseType(databaseType)
, logQuery(logQuery)
{
}

DatabaseConnection::~DatabaseConnection()
{
	if(Connected())
		Disconnect();
}

}
