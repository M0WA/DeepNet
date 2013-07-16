/**
 * @file TableColumnContainer.cpp
 * @author Moritz Wagner
 * @date 19.08.2012
 */


#include "TableColumnContainer.h"
#include "TableColumn.h"

#include <NotImplementedException.h>

namespace database {

TableColumnContainer::TableColumnContainer(TableColumn* pCol)
:  tools::Pointer<TableColumn>(pCol) {
}

TableColumnContainer::TableColumnContainer(const TableColumnContainer& container) {

	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy column container");
}

TableColumnContainer::~TableColumnContainer() {
}

const TableColumn* TableColumnContainer::GetConstColumn() const {
	return this->GetConst();
}

TableColumn* TableColumnContainer::GetColumn() {
	return this->Get();
}

}
