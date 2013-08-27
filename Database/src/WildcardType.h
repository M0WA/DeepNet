/**
 *
 * @file WildcardType.h
 * @author Moritz Wagner
 * @date 27.08.2013
 *
 */

#pragma once

namespace database {

enum WildcardType
{
	WILDCARD_NONE  = 0x00,
	WILDCARD_RIGHT = 0x01,
	WILDCARD_LEFT  = 0x02,
	WILDCARD_BOTH  = 0x03,

	MAX_WHERE_CONDITION_WILDCARD_TYPE = 0xff,
};

}
