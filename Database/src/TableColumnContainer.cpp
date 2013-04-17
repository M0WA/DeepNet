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
: pCol(pCol) {
}

TableColumnContainer::TableColumnContainer(const TableColumnContainer& container) {

	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy column container");
}


TableColumnContainer::~TableColumnContainer() {

	CleanUp();
}

void TableColumnContainer::CleanUp() {

	if(pCol) {
		delete pCol; }
	pCol = 0;
}

}
