/**
 * @file SelectResultContainer.h
 * @author Moritz Wagner
 * @date 20.08.2012
 */

#pragma once

#include <PointerContainer.h>

namespace database {

/**
 * @brief container for results of SELECT statements.
 * this container normally contains database::TableBase or
 * classes derived from it.
 */
template <class T>
class SelectResultContainer : public tools::PointerContainer<T> {
private:
	SelectResultContainer<T>(const SelectResultContainer<T>& copy){}

public:
	SelectResultContainer<T>() : tools::PointerContainer<T>(){}
	virtual ~SelectResultContainer(){ }
};

}

