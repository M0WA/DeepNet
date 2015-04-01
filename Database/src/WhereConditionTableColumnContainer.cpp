/**
 * @file WhereConditionTableColumnContainer.cpp
 * @author Moritz Wagner
 * @date 19.08.2012
 */

#include "WhereConditionTableColumnContainer.h"
#include "WhereConditionTableColumn.h"

#include <NotImplementedException.h>

namespace database {

WhereConditionTableColumnContainer::WhereConditionTableColumnContainer(const WhereConditionTableColumnContainer& copy) {

	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy WhereConditionTableColumnContainer");
}

}
