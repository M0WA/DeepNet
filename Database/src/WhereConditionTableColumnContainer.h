/**
 * @file WhereConditionTableColumnContainer.h
 * @author Moritz Wagner
 * @date 19.08.2012
 */

#pragma once

#include <vector>
#include <cstddef>

#include "WhereConditionTableColumn.h"

#include <PointerContainer.h>

namespace database {

/**
 * @brief container for multiple pointers to database::WhereConditionTableColumn
 */
class WhereConditionTableColumnContainer : public tools::PointerContainer<WhereConditionTableColumn> {
public:
	WhereConditionTableColumnContainer() {}
	virtual ~WhereConditionTableColumnContainer() {}

private:
	WhereConditionTableColumnContainer(const WhereConditionTableColumnContainer& copy);
};

}

