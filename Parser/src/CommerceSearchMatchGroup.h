/*
 * CommerceSearchMatchGroup.h
 *
 *  Created on: 09.09.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

namespace parser {

enum CommerceSearchMatchGroupType {
	UNKNOWN_CRITERIA_GROUP_TYPE = 0,

	PRODUCT_URL         = 1,
	PRODUCT_ID          = 2,
	PRODUCT_NAME        = 3,
	PRODUCT_DESCRIPTION = 4,
	PRODUCT_IMAGE       = 5,
};

class CommerceSearchMatchGroup {
public:
	CommerceSearchMatchGroup();
	virtual ~CommerceSearchMatchGroup();

public:
	CommerceSearchMatchGroupType groupType;
	bool isPrimaryKey;
	size_t position;
};

}

