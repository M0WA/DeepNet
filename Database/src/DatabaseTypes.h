/**
 * @file DatabaseTypes.h
 * @author Moritz Wagner
 * @date 04.05.2012
 */

#pragma once

namespace database
{
	/**
	 * @brief enumeration type for supported database manufacturers.
	 */
	enum DatabaseType
	{
		/**
		 * database type for MySQL databases.
		 */
		DB_MYSQL,

		/**
		 * database type for IBM DB2 databases.
		 */
		DB_IBM_DB2,

		/**
		 * database type for PostgreSQL databases.
		 */
		DB_POSTGRESQL,
	};
}
