/*
 * CommerceSearchMatchGroup.cpp
 *
 *  Created on: 09.09.2012
 *      Author: Moritz Wagner
 */

#include "CommerceSearchMatchGroup.h"

namespace parser {

CommerceSearchMatchGroup::CommerceSearchMatchGroup()
: groupType(UNKNOWN_CRITERIA_GROUP_TYPE)
, isPrimaryKey(false)
, position(0){
}

CommerceSearchMatchGroup::~CommerceSearchMatchGroup() {
}

}
