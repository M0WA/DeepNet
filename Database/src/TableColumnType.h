/**
 * @file TableColumnDefinition.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#pragma once

namespace database {

/**
 * @enum TableColumnType
 * @brief types for table columns.
 */
enum TableColumnType {

	/**
	 * unknown type, error.
	 */
	DB_TYPE_UNKNOWN,

	/**
	 * integer type.
	 */
	DB_TYPE_INTEGER,

	/**
	 * double (float) type.
	 */
	DB_TYPE_DOUBLE,

	/**
	 * variable length string type.
	 */
	DB_TYPE_VARCHAR,

	/**
	 * fixed length string type.
	 */
	DB_TYPE_CHAR,

	/**
	 * large string type.
	 */
	DB_TYPE_LARGE_TEXT,

	/**
	 * timestamp/date type.
	 */
	DB_TYPE_TIMESTAMP,

};

}

