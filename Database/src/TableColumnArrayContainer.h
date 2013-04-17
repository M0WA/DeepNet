/**
 * @file TableColumnArrayContainer.h
 * @author Moritz Wagner
 * @date 19.08.2012
 */

#pragma once

#include <vector>
#include <cstddef>

#include <PointerContainer.h>

#include "TableColumnContainer.h"

namespace database {

/**
 * @brief container for TableColumnContainer.
 * manages memory of multiple TableColumnContainer.
 */
class TableColumnArrayContainer : public tools::PointerContainer<TableColumnContainer> {
public:
	TableColumnArrayContainer() {}
	virtual ~TableColumnArrayContainer() {}
};

}

