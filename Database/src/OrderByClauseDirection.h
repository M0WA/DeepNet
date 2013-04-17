/**
 * @file OrderByClauseDirection.h
 * @author Moritz Wagner
 * @date 22.05.2012
 */

#pragma once

namespace database {

/**
 * @enum OrderByClauseDirection
 * @brief represent ordering direction.
 */
enum OrderByClauseDirection
{
	/**
	 * ascending order.
	 */
	ASCENDING  = 0,

	/**
	 * descending order.
	 */
	DESCENDING = 1,

	/**
	 * do not use.
	 */
	MAX_DIRECTION,
};

}
